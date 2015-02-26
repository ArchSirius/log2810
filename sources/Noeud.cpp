/****************************************************************************
* Fichier       : Noeud.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Implementation de la classe Noeud
****************************************************************************/
#include <string.h>
#include <algorithm>
#include <exception>
#include "headers/Noeud.h"
using namespace std;

Noeud::Noeud(){
	id = 0;
	numType = NOEUD;
	nom[0] = '\0';
	capaciteEthernet = 0;
	reseauSansFil = false;
}

Noeud::Noeud(int pId, char* pNom){
	numType = NOEUD;
	id = pId;
	strncpy(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
	capaciteEthernet = 0;
	reseauSansFil = false;
}

Noeud::~Noeud(){
	for(Noeud* noeud : connexions){
		deconnecter(noeud);
	}
}

Noeud::Type Noeud::getNumType() const {
	return numType;
}

unsigned int Noeud::getId(){
	return id;
}

void Noeud::connecter(Noeud* noeud){
	ajouterConnexion(noeud);
	noeud->ajouterConnexion(this);
}

void Noeud::ajouterConnexion(Noeud* noeud){
	connexions.push_back(noeud);
}

void Noeud::deconnecter(Noeud* noeud){
	vector<Noeud*>::iterator it;
	it = find(connexions.begin(), connexions.end(), noeud);
	if (it != connexions.end()){
		retirerConnexion(noeud);
		noeud->retirerConnexion(this);
	}
}

void Noeud::retirerConnexion(Noeud* noeud){
	vector<Noeud*>::iterator it;
	it = find(connexions.begin(), connexions.end(), noeud);
	connexions.erase(it);
}
