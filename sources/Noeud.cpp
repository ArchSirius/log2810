#include <string.h>
#include <algorithm>
#include <exception>
#include "headers/Noeud.h"
using namespace std;

Noeud::Noeud(){
	id = 0;
	numType = NOEUD;
	nom[0] = '\0';
}

Noeud::Noeud(int pId, char* pNom){
	numType = NOEUD;
	id = pId;
	strncpy(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
}

Noeud::~Noeud(){}

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
