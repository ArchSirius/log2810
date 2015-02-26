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
	void implanter();
	void afficher();

	/*
	*	Une fois un noeud lu et cr��, on l'ajoute au r�seau.
	*	On fait cela pour tous les noeuds.
	*	Ensuite, on lit reseau.txt avec implanter(),
	*	puis on appelle connexion() des noeuds cibles.
	*	Ainsi la map noeuds contient chaque appareil du reseau,
	*	et chaque appareil contient un vecteur listant ses connexions.
	*/
	void ajouter(Noeud* noeud);
	void retirer(Noeud* noeud);
	void remplacer(Noeud* ancien, Noeud* nouveau);
	void distance(Noeud* n1, Noeud* n2);

private:
	unsigned int floyd(map<unsigned int, Noeud*> noeuds, Noeud* n1, Noeud* n2);

	map<unsigned int, Noeud*> noeuds;
	unsigned int coutFil, coutSansFil;

};

#endif