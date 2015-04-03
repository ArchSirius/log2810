/****************************************************************************
* Fichier       : Commutateur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 f�vrier 2015
* Mise � jour   : 09 mars 2015
* Description   : Implementation de la classe Commutateur
****************************************************************************/

#include <string.h>
#include "headers/Commutateur.h"

/****************************************************************************
* Fonction		: Commutateur::Commutateur
* Description	: Constructeur par defaut
* Param�tres	: aucun
* Retour		: aucun
****************************************************************************/
Commutateur::Commutateur() : Noeud(){
	numType = Noeud::COMMUTATEUR;
	capaciteEthernet = 2;

}

/****************************************************************************
* Fonction		: Commutateur::Commutateur
* Description	: Constructeur par param�tre
* Param�tres	: (int) pId : le id du noeud
				  (char*) pNom : le nom du noeud
* Retour		: aucun
****************************************************************************/
Commutateur::Commutateur(unsigned int pId, char* pNom, unsigned int pCapacite) : Noeud(pId, pNom){
	numType = Noeud::COMMUTATEUR;
	if (pCapacite > 1)
		capaciteEthernet = pCapacite;
	else
		capaciteEthernet = 2; // valeur par defaut
}

//Destructeur
Commutateur::~Commutateur(){}

/****************************************************************************
* Fonction		: Commutateur::connexionCompatible
* Description	: methode qui verifie si la connexion entre deux appareils est compatible
* Param�tres	: (Noeud*) noeud : le pointeur du noeud sur lequel on veut se connecter
* Retour		: (bool) true = compatible / false = non-compatible
****************************************************************************/
bool Commutateur::connexionCompatible(Noeud* noeud) {
	return true; // tjs compatible
}
