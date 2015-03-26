/****************************************************************************
* Fichier       : Transition.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 09 mars 2015
* Description   : Definition de la classe Transition
****************************************************************************/
#ifndef TRANSITION_H_
#define TRANSITION_H_

#include "Etat.h"
#include <string>

using namespace std;

class Transition
{
public: 
	enum Type { FINI, MOORE, MEALY };

	Transition();
	Transition(Type type, string entre, Etat* etatDepart, Etat* etatPointe, string sortie = "");
	~Transition();

	string getEtiquette();
	Etat* getEtatDepart();
	Etat* getEtatDestination();

private:
	Type _type;
	string _entre;
	string _sortie;
	string _etiquette;

	Etat* _etatDepart;
	Etat* _etatDestination;
};

#endif