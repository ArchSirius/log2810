#include <string.h>
#include "headers/Commutateur.h"

Commutateur::Commutateur(){
	id = 0;
	numType = 0;
	nom[0] = '\0';
}

Commutateur::Commutateur(int numT, int pId, char* pNom){
	numType = numT;
	id = pId;
	strncpy(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
}

Commutateur::~Commutateur(){}
