/****************************************************************************
* Fichier       : Serveur.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 f�vrier 2015
* Mise � jour   : 19 f�vrier 2015
* Description   : Definition de la classe Serveur
****************************************************************************/

#ifndef SERVEUR_H
#define SERVEUR_H

#include "Noeud.h"

class Serveur : public Noeud {

public:
	Serveur();
	Serveur(int pId, char* pNom);
	~Serveur();

private:
	//

};

#endif