/****************************************************************************
* Fichier       : Reseau.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 février 2015
* Mise à jour   : 26 février 2015
* Description   : Implementation de la classe Reseau
****************************************************************************/

#include "headers/Reseau.h"

Reseau::Reseau()
	: coutFil(0), coutSansFil(0) {
}

Reseau::Reseau(unsigned int pCoutFil, unsigned int pCoutSansFil)
	: coutFil(pCoutFil), coutSansFil(pCoutSansFil) {
}

Reseau::~Reseau(){
	for(map<unsigned int, Noeud*>::reverse_iterator rit = noeuds.rbegin();
		rit != noeuds.rend();
		++rit)
	{
		// Destructeur de Noeud
		delete rit->second;
		// Retirer l'élément de la map (par clé, car reverse_iterator ne marche pas)
    	noeuds.erase(rit->first);
	}
}

void Reseau::implanter(){
	// Lire reseau.txt et établir connexions
}

void Reseau::afficher(){
	// nécessitera d'implémenter operator<< pour Noeud
}

void Reseau::ajouter(Noeud* noeud){
	noeuds.insert(pair<unsigned int, Noeud*>(noeud->getId(), noeud));
}

void Reseau::retirer(Noeud* noeud){
	noeuds.erase(noeud->getId());
	// Le destructeur de Noeud retire toutes les connexions;
	delete noeud;
}

void Reseau::remplacer(Noeud* ancien, Noeud* nouveau){

}

void Reseau::distance(Noeud* n1, Noeud* n2){
	// Si n1 et n2 existent dans map, floyd, puis afficher
}

unsigned int Reseau::floyd(map<unsigned int, Noeud*> noeuds, Noeud* n1, Noeud* n2){

}
