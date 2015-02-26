/****************************************************************************
* Fichier       : Commutateur.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 f�vrier 2015
* Mise � jour   : 19 f�vrier 2015
* Description   : Definition de la classe Commutateur
****************************************************************************/
#ifndef COMMUTATEUR_H_
#define COMMUTATEUR_H_

#include "Noeud.h"

class Commutateur : public Noeud {

public:
	Commutateur();
	Commutateur(unsigned int pId, char* pNom, unsigned int capacite);
	~Commutateur();

private:
	//unsigned int capacite; //Nombre maximal de ports
};

#endif;
