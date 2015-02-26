/****************************************************************************
* Fichier       : Commutateur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 f�vrier 2015
* Mise � jour   : 19 f�vrier 2015
* Description   : Implementation de la classe Commutateur
****************************************************************************/

#include <string.h>
#include "headers/Commutateur.h"

Commutateur::Commutateur() : Noeud(){
	numType = Noeud::COMMUTATEUR;
	capaciteEthernet = 2;

}

Commutateur::Commutateur(unsigned int pId, char* pNom, unsigned int pCapacite) : Noeud(pId, pNom){
	numType = Noeud::COMMUTATEUR;
	if (pCapacite > 1)
		capaciteEthernet = pCapacite;
	else
		capaciteEthernet = 2; // valeur par defaut

}

Commutateur::~Commutateur(){}
