#include "Noeud.h"

class Commutateur : public Noeud {

public:
	Commutateur();
	Commutateur(int pId, char* pNom);
	~Commutateur();

private:
	unsigned int capacite; //Nombre maximal de ports
	};
