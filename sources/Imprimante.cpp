/****************************************************************************
* Fichier       : Routeur.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Implementation de la classe Routeur
****************************************************************************/

#include "headers/Imprimante.h"

Imprimante::Imprimante() : Noeud(){
	numType = Noeud::IMPRIMANTE;
	capaciteEthernet = 1;
}

Imprimante::Imprimante(int pId, char* pNom) : Noeud(pId, pNom){
	numType = Noeud::IMPRIMANTE;
	capaciteEthernet = 1;
}

Imprimante::~Imprimante(){}

bool Imprimante::connexionCompatible(Noeud* noeud) {
	if (noeud->getNumType() == COMMUTATEUR)
	{
		for (Noeud* n : connexionsFil)
		{
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