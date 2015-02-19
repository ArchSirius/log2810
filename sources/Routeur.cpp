#include <string.h>
#include "headers/Routeur.h"

Routeur::Routeur(){
	id = 0;
	numType = 0;
	nom[0] = '\0';
}

Routeur::Routeur(int numT, int pId, char* pNom){
	numType = numT;
	id = pId;
	strncpy(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
}

Routeur::~Routeur(){}
