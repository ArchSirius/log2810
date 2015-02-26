/****************************************************************************
* Fichier       : Serveur.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
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