#ifndef COMMUTAEUR_H_
#define COMMUTATEUR_H_

#include "Noeud.h"

class Commutateur : public Noeud {

public:
	Commutateur();
	Commutateur(unsigned int pId, char* pNom, unsigned int capacite);
	~Commutateur();

private:
	unsigned int capacite; //Nombre maximal de ports
};

#endif;
