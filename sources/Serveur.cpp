/****************************************************************************
* Fichier       : Routeur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 f�vrier 2015
* Mise � jour   : 19 f�vrier 2015
* Description   : Implementation de la classe Routeur
****************************************************************************/

#include "headers/Serveur.h"

Serveur::Serveur() : Noeud(){
	numType = Noeud::SERVEUR;
	capaciteEthernet = 1;
}

Serveur::Serveur(int pId, char* pNom) : Noeud(pId, pNom){
	numType = Noeud::SERVEUR;
	capaciteEthernet = 1;
}

Serveur::~Serveur(){}
