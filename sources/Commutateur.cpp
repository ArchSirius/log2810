#include <string.h>
#include "headers/Commutateur.h"

Commutateur::Commutateur(){
	id = 0;
	numType = Noeud::COMMUTATEUR;
	nom[0] = '\0';
}

Commutateur::Commutateur(unsigned int pId, char* pNom, unsigned int pCapacite){
	numType = Noeud::COMMUTATEUR;
	id = pId;
	strncpy_s(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
	capacite = pCapacite;
}

Commutateur::~Commutateur(){}
