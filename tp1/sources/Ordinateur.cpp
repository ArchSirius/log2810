/****************************************************************************
* Fichier       : Ordinateur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 09 mars 2015
* Description   : Implementation de la classe Ordinateur
****************************************************************************/

#include <string.h>
#include "headers/Ordinateur.h"

/****************************************************************************
* Fonction		: Ordinateur::Ordinateur
* Description	: Constructeur par defaut
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
Ordinateur::Ordinateur() : Noeud(){
	numType = Noeud::ORDINATEUR;
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

//Destructeur
Ordinateur::~Ordinateur(){}

/****************************************************************************
* Fonction		: Ordinateur::connexionCompatible
* Description	: methode qui verifie si la connexion entre deux appareils est compatible
* Paramètres	: (Noeud*) noeud : le pointeur du noeud sur lequel on veut se connecter
* Retour		: (bool) true = compatible / false = non-compatible
****************************************************************************/
bool Ordinateur::connexionCompatible(Noeud* noeud){
	//peut seulement ce connecter avec un commutateur ou un routeur
	if (noeud->getNumType() == COMMUTATEUR || noeud->getNumType() == ROUTEUR)
		return true;
	else
	{
		cout << "Un ordinateur peut seulement se conecter avec un commutateur ou un routeur ";
		return false;
	}
		
}

