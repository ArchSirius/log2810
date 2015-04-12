/****************************************************************************
* Fichier       : Automate.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 12 avril 2015
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

	//getter/setter
	string getType() const;
	Etat etatInitial() const;
	int getNumEtatFinal() const;

	//Taches et RF
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
	void buildAutomate(string input);

	unsigned int nbEtats;
	Type type;
	list<Etat> ListeEtats;
	vector<char> ListeEntrees;
	vector<char> ListeSorties;
};

#endif
