/****************************************************************************
* Fichier       : Routeur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 f�vrier 2015
* Mise � jour   : 19 f�vrier 2015
* Description   : Implementation de la classe Routeur
****************************************************************************/
#include <string.h>
#include "headers/Routeur.h"

Routeur::Routeur(){
	id = 0;
	numType = Noeud::ROUTEUR;
	nom[0] = '\0';
}

Routeur::Routeur(int pId, char* pNom){
	numType = Noeud::ROUTEUR;
	id = pId;
	strncpy(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
}

Routeur::~Routeur(){}
