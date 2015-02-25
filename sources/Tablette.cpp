/****************************************************************************
* Fichier       : Routeur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Implementation de la classe Routeur
****************************************************************************/

#include "headers/Tablette.h"

Tablette::Tablette() : Noeud(){
	numType = Noeud::TABLETTE;
	reseauSansFil = true;
}

Tablette::Tablette(int pId, char* pNom) : Noeud(pId, pNom){
	numType = Noeud::TABLETTE;
	reseauSansFil = true;
}

Tablette::~Tablette(){}
