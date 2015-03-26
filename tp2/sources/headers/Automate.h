/****************************************************************************
* Fichier       : Automate.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 26 mars 2015
* Description   : Definition de la classe Automate
****************************************************************************/

#ifndef AUTOMATE_H_
#define AUTOMATE_H_

#include <string>
#include <vector>
#include "Etat.h"
using namespace std;

class Automate {
public:
	enum Type {FINI, MOORE, MEALY};

	Automate();
	Automate(string fichier);
	~Automate();

	Etat etatInitial();
	void ajouterEtat(Etat e);
	void genererFichierAutomate(string fichier);
	bool estDeterministe();
	bool estReactif();
	Automate minimiserMoore();
	string calculerSortie(string mot);
	void convertisseurMoore2Mealy();
	void convertisseurMealy2Moore();

private:
	vector<Etat> ListeEtat;
	vector<char> ListeEntrees;
	vector<char> ListeSorties;
};

#endif;
