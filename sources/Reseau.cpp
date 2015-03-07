/****************************************************************************
* Fichier       : Reseau.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 février 2015
* Mise à jour   : 06 mars 2015
* Description   : Implementation de la classe Reseau
****************************************************************************/

#include "headers/Reseau.h"
#include <limits>

Reseau::Reseau()
	: coutFil(0), coutSansFil(0) , matriceUpdated(false), coutsUpdated(false) {
}

Reseau::Reseau(unsigned int pCoutFil, unsigned int pCoutSansFil)
	: coutFil(pCoutFil), coutSansFil(pCoutSansFil), matriceUpdated(false), coutsUpdated(false) {
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
			map<unsigned int, Noeud*>::iterator it1 = noeuds.find(id1);
			map<unsigned int, Noeud*>::iterator it2 = noeuds.find(id2);
			if(it1 != noeuds.end() && it2 != noeuds.end() && it1 != it2){
				(it1->second)->connecter(it2->second);
			}
		}
		matriceGen();
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}

void Reseau::afficher(){
	for (pair<const unsigned int, Noeud*> n : noeuds)
		cout << *(n.second) << endl;
}

void Reseau::ajouter(Noeud* noeud){
	noeuds.insert(pair<unsigned int, Noeud*>(noeud->getId(), noeud));
	matriceUpdated = false;
}

void Reseau::retirer(unsigned int id){
	noeuds.erase(id);
	matriceUpdated = false;
}

void Reseau::remplacer(unsigned int ancien, unsigned int nouveau){
	// a faire
	matriceUpdated = false;
}

unsigned int Reseau::distance(unsigned int n1, unsigned int n2) {
	map<unsigned int, Noeud*>::iterator it1 = noeuds.find(n1);
	map<unsigned int, Noeud*>::iterator it2 = noeuds.find(n2);
	if(it1 != noeuds.end() && it2 != noeuds.end() && it1 != it2){
		if(!matriceUpdated)
			matriceGen();
		if(!coutsUpdated)
			floyd();
		unsigned int i = 0;
		unsigned int j = 0;
		// obtenir la position dans la matrice
		while(header[i] != n1){
			i++;
		}
		while(header[j] != n2){
			j++;
		}
		return couts[i][j];
	}
	return 0;
}

void Reseau::floyd() {
	couts = matrice;
	for(unsigned int i = 0; i < couts.size(); i++){
		for(unsigned int j = 0; j < couts.size(); j++){
			for(unsigned int k = 0; k < couts.size(); k++){
				if(couts[j][k] > couts[i][j] + couts[i][k]){
					couts[j][k] = couts[i][j] + couts[i][k];
					couts[k][j] = couts[i][j] + couts[i][k];
				}
			}
		}
	}
	coutsUpdated = true;
}

void Reseau::matriceGen(){
	// Construire la matrice et initialiser à l'infini
	matrice.reserve(noeuds.size());
	header.reserve(noeuds.size());
	for(unsigned int i = 0; i < noeuds.size(); i++){
		vector<unsigned int> temp;
		temp.reserve(noeuds.size());
		for(unsigned int j = 0; j < noeuds.size(); j++){
			temp.push_back(numeric_limits<unsigned int>::max());
		}
		matrice.push_back(temp);
		header.push_back(0);
	}

	// Initialiser le header
	unsigned int i = 0;
	for(pair<unsigned int, Noeud*> paire : noeuds){
		header[i] = paire.first;
		i++;
	}

	// Réinitialiser la diagonale
	for(i = 0; i < matrice.size(); i++){
		matrice[i][i] = 0;
	}

	// Coûts

	// Pour chaque noeud A du réseau
	for(pair<unsigned int, Noeud*> paire : noeuds){
		// FIL
		unsigned int indexA = 0;
		// obtenir la position dans la matrice
			while(header[indexA] != paire.first){
				indexA++;
			}
		vector<Noeud*> connections = paire.second->getConnexionsFil();
		// trouver ses noeuds B connectés
		if(connections.size() > 0){
			for(Noeud* noeud : connections){
				// obtenir le ID de son noeud B
				i = noeud->getId();
				unsigned int indexB = 0;
				// obtenir la position dans la matrice
				while(header[indexB] != i){
					indexB++;
				}
				// poser le coût [A][B]
				matrice[indexA][indexB] = coutFil;
				matrice[indexB][indexA] = coutFil;
			}
		}
		// SANS-FIL
		indexA = 0;
		// obtenir la position dans la matrice
			while(header[indexA] != paire.first){
				indexA++;
			}
		connections = paire.second->getConnexionsSansFil();
		// trouver ses noeuds B connectés
		if(connections.size() > 0){
			for(Noeud* noeud : connections){
				// obtenir le ID de son noeud B
				i = noeud->getId();
				unsigned int indexB = 0;
				// obtenir la position dans la matrice
				while(header[indexB] != i){
					indexB++;
				}
				// poser le coût [A][B]
				matrice[indexA][indexB] = coutSansFil;
				matrice[indexB][indexA] = coutSansFil;
			}
		}
	}

	/* La matrice prend alors la forme

	  - 111 112 113 211 311 312
	111   0   1   -   2   -   -
	112   1   0   -   -   -   1
	113   -   -   0   2   -   -
	211   2   -   2   0   -   1
	311   -   -   -   -   0   -
	312   -   1   -   1   -   0

	*/

	matriceUpdated = true;
}