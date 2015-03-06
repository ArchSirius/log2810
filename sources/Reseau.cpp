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
	// Reseau ne contient aucun pointeur
	// Ses noeuds sont détruits lorsqu'il est détruit
	// main détruit Reseau
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
			//Construction de l'objet reseau??
			//Reseau reseau(id1, id2);
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}

void Reseau::afficher(){
	// nécessitera d'implémenter operator<< pour Noeud
}

void Reseau::ajouter(Noeud noeud){
	noeuds.insert(pair<unsigned int, Noeud>(noeud.getId(), noeud));
}

void Reseau::retirer(unsigned int id){
	noeuds.erase(id);
}

void Reseau::remplacer(unsigned int ancien, unsigned int nouveau){

}

void Reseau::distance(unsigned int n1, unsigned int n2) const {
	// Si n1 et n2 existent dans map, floyd, puis afficher
}

unsigned int Reseau::floyd(const map<unsigned int, Noeud>* noeuds, const Noeud* n1, const Noeud* n2) const {
	return 0; // POUR LA COMPILATION SEULEMENT, a modifier
}
