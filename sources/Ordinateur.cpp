/****************************************************************************
* Fichier       : Ordinateur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Implementation de la classe Ordinateur
****************************************************************************/

#include <string.h>
#include "headers/Ordinateur.h"

Ordinateur::Ordinateur() : Noeud(){
	numType = Noeud::ORDINATEUR;
	//lienFilaire = false;
}

/****************************************************************************
* Fonction		: Ordinateur::Ordinateur
* Description	: Constructeur par paramètre
* Paramètres	: (int) pId : le id du noeud
				  (char*) pNom : le nom du noeud
				  (bool) pLienFilaire : true = lien Filiaire, false = lien sans fil
				  (bool) pTypeOrdi : true = ordinateur de bureau, false = laptop
* Retour		: aucun
****************************************************************************/
Ordinateur::Ordinateur(int pId, char* pNom, bool pLienFilaire, bool pTypeOrdi) 
	: Noeud(pId, pNom){
	//lienFilaire = pLienFilaire;	
	
	if (pTypeOrdi)
	{
		numType = Noeud::PC;
		capaciteEthernet = 1;
	}
	else 
	{
		numType = Noeud::LAPTOP;
		reseauSansFil = true;
	}
}

Ordinateur::~Ordinateur(){
	for (unsigned int i = 0; i < connexions.size(); i++)
	{
		delete connexions[i];
	}
}
