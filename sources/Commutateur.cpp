#include <string.h>
#include "headers/Commutateur.h"

Commutateur::Commutateur(){
	id = 0;
	numType = Noeud::COMMUTATEUR;
	nom[0] = '\0';
}

Commutateur::Commutateur(int pId, char* pNom){
	numType = Noeud::COMMUTATEUR;
	id = pId;
	strncpy_s(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
}

Commutateur::~Commutateur(){}
