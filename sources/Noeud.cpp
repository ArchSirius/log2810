#include <string.h>
#include "headers/Noeud.h"

Noeud::Noeud(){
	id = 0;
	numType = 0;
	nom[0] = '\0';
}

Noeud::Noeud(int numT, int pId, char* pNom){
	numType = numT;
	id = pId;
	strncpy(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
}

Noeud::~Noeud(){}
