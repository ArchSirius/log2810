/****************************************************************************
* Fichier       : Reseau.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 f�vrier 2015
* Mise � jour   : 26 f�vrier 2015
* Description   : Definition de la classe Reseau
****************************************************************************/
#ifndef RESEAU_H
#define RESEAU_H

#include "Noeud.h"
#include <map>
#include <string> 
#include <iostream> 
#include <fstream> 
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

class Reseau {

public:
	Reseau();
	Reseau(unsigned int pCoutFil, unsigned int pCoutSansFil);
	~Reseau();

	/*
	*	Dans implanter() on lit reseau.txt et pour chaque paire de noeuds
	*	on cr�e la connexion n1 avec n2, qui appellera automatiquement
	*	la connexion n2 avec n1. Ainsi on aura ensuite une map de noeuds
	*	et ces noeuds contiennent leurs connexions.
	*/
	void implanter();														//RF1
	void afficher() const;													//RF2
	void afficher(unsigned int id) const;

	/*
	*	Une fois un noeud lu et cr��, on l'ajoute au r�seau.
	*	On fait cela pour tous les noeuds.
	*	Ensuite, on lit reseau.txt avec implanter(),
	*	puis on appelle connexion() des noeuds cibles.
	*	Ainsi la map noeuds contient chaque appareil du reseau,
	*	et chaque appareil contient un vecteur listant ses connexions.
	*/
	void ajouter(Noeud* noeud);
	void ajouterConnecter(Noeud* noeudAjoute, unsigned int idConnecteur);	//RF4
	void retirer(unsigned int id);											//RF5
	void remplacer(unsigned int ancienId, Noeud* nouveauNoeud);				//RF6
	unsigned int distance(unsigned int n1, unsigned int n2);				//RF7

private:
	unsigned int coutFil, coutSansFil;

	map<unsigned int, Noeud*> noeuds;

	vector<unsigned int> header;
	vector< vector<unsigned int> > matrice;
	vector< vector<unsigned int> > couts;
	bool matriceUpdated, coutsUpdated;
	
	void matriceGen();
	void floyd();
};

#endif