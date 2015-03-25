/****************************************************************************
* Fichier       : Routeur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 f�vrier 2015
* Mise � jour   : 09 mars 2015
* Description   : Implementation de la classe Routeur
****************************************************************************/

#include "headers/Serveur.h"

/****************************************************************************
* Fonction		: Serveur::Serveur
* Description	: Constructeur par defaut
* Param�tres	: aucun
* Retour		: aucun
****************************************************************************/
Serveur::Serveur() : Noeud(){
	numType = Noeud::SERVEUR;
	capaciteEthernet = 1;
}

/****************************************************************************
* Fonction		: Serveur::Serveur
* Description	: Constructeur par param�tre
* Param�tres	: (int) pId : le id du noeud
				  (char*) pNom : le nom du noeud
* Retour		: aucun
****************************************************************************/
Serveur::Serveur(int pId, char* pNom) : Noeud(pId, pNom){
	numType = Noeud::SERVEUR;
	capaciteEthernet = 1;
}

//Destructeur
Serveur::~Serveur(){}

/****************************************************************************
* Fonction		: Serveur::connexionCompatible
* Description	: methode qui verifie si la connexion entre deux appareils est compatible
* Param�tres	: (Noeud*) noeud : le pointeur du noeud sur lequel on veut se connecter
* Retour		: (bool) true = compatible / false = non-compatible
****************************************************************************/
bool Serveur::connexionCompatible(Noeud* noeud) {
	if (noeud->getNumType() == COMMUTATEUR || noeud->getNumType() == ROUTEUR)
	{
		for (Noeud* n : connexionsFil)
		{
			//On peut connecter un seul routeur ou commutateur
			if (n->getNumType() == COMMUTATEUR || n->getNumType() == ROUTEUR)
			{
				cout << "Ce serveur est deja connecte a un commutateur ou un routeur ";
				return false;
			}
		}
		return true;
	}
	else
	{
		cout << "Un serveur peut seulement se conecter avec un commutateur ou un routeur ";
		return false;
	}


			
}