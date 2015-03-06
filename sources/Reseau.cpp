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
	ifstream fichier("reseau.txt");
	if (fichier)
	{
		string input, token;
		vector<string> reseau;
		unsigned int id1, id2;

		while (!fichier.eof())
		{
			reseau.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, '-'))
				reseau.push_back(token);

			//Conversion des string en bons types
			id1 = atoi(reseau[0].c_str());
			id2 = atoi(reseau[1].c_str());
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
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
	return 0; // POUR LA COMPILATION SEULEMENT, a modifier
}
