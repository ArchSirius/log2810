#include <string.h>
#include "headers/Ordinateur.h"

Ordinateur::Ordinateur(){
	id = 0;
	numType = Noeud::ORDINATEUR;
	nom[0] = '\0';
	lienFilaire = false;
}

Ordinateur::Ordinateur(int pId, char* pNom, bool pLienFilaire){
	numType = Noeud::ORDINATEUR;
	id = pId;
	strncpy_s(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
	lienFilaire = pLienFilaire;
}

Ordinateur::~Ordinateur(){
	for (unsigned int i = 0; i < connexions.size(); i++)
	{
		delete connexions[i];
	}
}
