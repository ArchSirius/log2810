/****************************************************************************
* Fichier       : Routeur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Implementation de la classe Routeur
****************************************************************************/

#include "headers/Imprimante.h"

Imprimante::Imprimante() : Noeud(){
	numType = Noeud::IMPRIMANTE;
	capaciteEthernet = 1;
}

Imprimante::Imprimante(int pId, char* pNom) : Noeud(pId, pNom){
	numType = Noeud::IMPRIMANTE;
	capaciteEthernet = 1;
}

Imprimante::~Imprimante(){}
