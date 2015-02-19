#include <string.h>
#include "headers/Routeur.h"

Routeur::Routeur(){
	id = 0;
	numType = Noeud::ROUTEUR;
	nom[0] = '\0';
}

Routeur::Routeur(int pId, char* pNom){
	numType = Noeud::ROUTEUR;
	id = pId;
	strncpy_s(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
}

Routeur::~Routeur(){}
