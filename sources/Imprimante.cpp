/****************************************************************************
* Fichier       : Routeur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 f�vrier 2015
* Mise � jour   : 09 mars 2015
* Description   : Implementation de la classe Routeur
****************************************************************************/

#include "headers/Imprimante.h"

/****************************************************************************
* Fonction		: Imprimante::Imprimante
* Description	: Constructeur par defaut
* Param�tres	: aucun
* Retour		: aucun
****************************************************************************/
Imprimante::Imprimante() : Noeud(){
	numType = Noeud::IMPRIMANTE;
	capaciteEthernet = 1;
}

/****************************************************************************
* Fonction		: Imprimante::Imprimante
* Description	: Constructeur par param�tre
* Param�tres	: (int) pId : le id du noeud
				  (char*) pNom : le nom du noeud
* Retour		: aucun
****************************************************************************/
Imprimante::Imprimante(int pId, char* pNom) : Noeud(pId, pNom){
	numType = Noeud::IMPRIMANTE;
	capaciteEthernet = 1;
}

//Destructeur
Imprimante::~Imprimante(){}

/****************************************************************************
* Fonction		: Imprimante::connexionCompatible
* Description	: methode qui verifie si la connexion entre deux appareils est compatible
* Param�tres	: (Noeud*) noeud : le pointeur du noeud sur lequel on veut se connecter
* Retour		: (bool) true = compatible / false = non-compatible
****************************************************************************/
bool Imprimante::connexionCompatible(Noeud* noeud) {
	if (noeud->getNumType() == COMMUTATEUR)
	{
		for (Noeud* n : connexionsFil)
		{
			//une imprimante peut etre connectee a un seul commutateur
			if (n->getNumType() == COMMUTATEUR)
			{
				cout << "Cette imprimante est deja connectee a un commutateur ";
				return false;
			}
		}
		return true;
	}
	else
	{
		cout << "Une imprimante peut seulement se conecter avec un commutateur ";
		return false;
	}
}