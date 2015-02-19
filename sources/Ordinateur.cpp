#include <string.h>
#include "headers/Ordinateur.h"

Ordinateur::Ordinateur(){
	id = 0;
	numType = 0;
	nom[0] = '\0';
}

Ordinateur::Ordinateur(int numT, int pId, char* pNom){
	numType = numT;
	id = pId;
	strncpy(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
}

Ordinateur::~Ordinateur(){}
