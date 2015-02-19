#ifndef COMMUTAEUR_H_
#define COMMUTATEUR_H_

#include "Noeud.h"

class Commutateur : public Noeud {

public:
	Commutateur();
	Commutateur(int pId, char* pNom);
	~Commutateur();

private:
	unsigned int capacite; //Nombre maximal de ports
};

#endif;