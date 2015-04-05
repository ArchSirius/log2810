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
#include <list>
#include "Etat.h"

using namespace std;

class Automate {
public:
	enum Type {FINI, MOORE, MEALY};

	Automate();
	Automate(string fichier);
	~Automate();

	string getType();
	Etat etatInitial();
	int getNumEtatFinal();
	void ajouterEtat(Etat e);
	void genererFichierAutomate(string fichier);
	bool estDeterministe();
	bool estReactif();
	Automate minimiserMealy();
	string calculerSortie(string mot);
	void convertisseurMoore2Mealy();
	void convertisseurMealy2Moore();

private:
	void buildBase(string input);
	void buildFini(string input);
	void buildMoore(string input);
	void buildMealy(string input);

	unsigned int nbEtats;
	Type type;
	list<Etat> ListeEtats;
	vector<char> ListeEntrees;
	vector<char> ListeSorties;
};

#endif
