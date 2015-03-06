/****************************************************************************
* Fichier       : Reseau.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 février 2015
* Mise à jour   : 06 mars 2015
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
		vector<string> relation;
		unsigned int id1, id2;

		while (!fichier.eof())
		{
			relation.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, '-'))
				relation.push_back(token);

			//Conversion des string en bons types
			id1 = atoi(relation[0].c_str());
			id2 = atoi(relation[1].c_str());
			
			// Connecter
			map<unsigned int, Noeud>::iterator it1 = noeuds.find(id1);
			map<unsigned int, Noeud>::iterator it2 = noeuds.find(id2);
			if(it1 != noeuds.end() && it2 != noeuds.end() && it1 != it2){
				(it1->second).connecter(it2->second);
			}
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}

void Reseau::afficher(){
	for (pair<const unsigned int, Noeud*> n : noeuds)
		cout << *(n.second) << endl;
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
	/*
	for(int i = 1; i < instances; i++)
	{
		for(int j = 1; j < instances; j++)
		{
			
		}
	}
	*/
	return 0; // POUR LA COMPILATION SEULEMENT, a modifier
}
