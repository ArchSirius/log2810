/****************************************************************************
* Fichier       : Routeur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Implementation de la classe Routeur
****************************************************************************/

#include "headers/Serveur.h"

Serveur::Serveur() : Noeud(){
	numType = Noeud::SERVEUR;
	capaciteEthernet = 1;
}

Serveur::Serveur(int pId, char* pNom) : Noeud(pId, pNom){
	numType = Noeud::SERVEUR;
	capaciteEthernet = 1;
}

Serveur::~Serveur(){}

bool Serveur::connexionCompatible(Noeud* noeud) {
	if (noeud->getNumType() == COMMUTATEUR || noeud->getNumType() == ROUTEUR)
	{
		for (Noeud* n : connexionsFil)
		{
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