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
	
	(pLienFilaire) ? capaciteEthernet = 1 : reseauSansFil = true;

	(pTypeOrdi) ? numType = Noeud::PC : numType = Noeud::LAPTOP;

}

Ordinateur::~Ordinateur(){}

bool Ordinateur::connexionCompatible(Noeud* noeud){
	if (noeud->getNumType() == COMMUTATEUR || noeud->getNumType() == ROUTEUR)
		return true;
	else
	{
		cout << "Un ordinateur peut seulement se conecter avec un commutateur ou un routeur ";
		return false;
	}
		
}

