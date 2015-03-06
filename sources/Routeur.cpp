/****************************************************************************
* Fichier       : Routeur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Implementation de la classe Routeur
****************************************************************************/
#include <string.h>
#include "headers/Routeur.h"

Routeur::Routeur() : Noeud(){
	numType = Noeud::ROUTEUR;
	capaciteEthernet = 2;
	reseauSansFil = false;
}

/****************************************************************************
* Fonction		: Routeur::Routeur
* Description	: Constructeur par paramètre
* Paramètres	: (int) pId : le id du noeud
				  (char*) pNom : le nom du noeud
				  (unsigned int) pCapacite : capacite strictement superieur a 1
				  (bool) pReseauSansFil : true = il y a une carte sans fil, false = il n'y a pas une carte sans fil
* Retour		: aucun
****************************************************************************/
Routeur::Routeur(int pId, char* pNom, unsigned int pCapacite, bool pReseauSansFil) : Noeud(pId, pNom){
	numType = Noeud::ROUTEUR;
	if (pCapacite > 1) 
		capaciteEthernet = pCapacite;
	else 
		capaciteEthernet = 2; // valeur par defaut
	reseauSansFil = pReseauSansFil;
}

Routeur::~Routeur(){}

bool Routeur::connexionCompatible(Noeud* noeud) {
	return true;
}