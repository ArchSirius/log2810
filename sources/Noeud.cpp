#include <string.h>
#include "headers/Noeud.h"

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
