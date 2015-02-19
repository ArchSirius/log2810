#include <string.h>
#include "headers/Ordinateur.h"

Ordinateur::Ordinateur(){
	id = 0;
	numType = Noeud::ORDINATEUR;
	nom[0] = '\0';
}

Ordinateur::Ordinateur(int pId, char* pNom){
	numType = Noeud::ORDINATEUR;
	id = pId;
	strncpy_s(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
}

Ordinateur::~Ordinateur(){
	for (unsigned int i = 0; i < connexions.size(); i++)
	{
		delete connexions[i];
	}
}
