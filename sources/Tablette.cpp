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

bool Tablette::connexionCompatible(Noeud* noeud) {
	if (noeud->getNumType() == ROUTEUR)
	{
		for (Noeud* n : connexionsFil)
		{
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