/****************************************************************************
* Fichier       : Routeur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 09 mars 2015
* Description   : Implementation de la classe Routeur
****************************************************************************/

#include "headers/Tablette.h"

/****************************************************************************
* Fonction		: Tablette::Tablette
* Description	: Constructeur par defaut
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
Tablette::Tablette() : Noeud(){
	numType = Noeud::TABLETTE;
	reseauSansFil = true;
}

/****************************************************************************
* Fonction		: Tablette::Tablette
* Description	: Constructeur par paramètre
* Paramètres	: (int) pId : le id du noeud
				  (char*) pNom : le nom du noeud
* Retour		: aucun
****************************************************************************/
Tablette::Tablette(int pId, char* pNom) : Noeud(pId, pNom){
	numType = Noeud::TABLETTE;
	reseauSansFil = true;
}

//Destructeur
Tablette::~Tablette(){}

/****************************************************************************
* Fonction		: Tablette::connexionCompatible
* Description	: methode qui verifie si la connexion entre deux appareils est compatible
* Paramètres	: (Noeud*) noeud : le pointeur du noeud sur lequel on veut se connecter
* Retour		: (bool) true = compatible / false = non-compatible
****************************************************************************/
bool Tablette::connexionCompatible(Noeud* noeud) {
	if (noeud->getNumType() == ROUTEUR)
	{
		for (Noeud* n : connexionsFil)
		{
			//peut seulement etre connecte a un seul routeur
			if (n->getNumType() == ROUTEUR)
			{
				cout << "Cette tablette est deja connectee a un routeur ";
				return false;
			}
		}
		return true;
	}
	else
	{
		cout << "Une tablette peut seulement se conecter avec un routeur ";
		return false;
	}
}