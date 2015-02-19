#ifndef ORDINATEUR_H_
#define ORDINATEUR_H_

#include "Noeud.h"

class Ordinateur : public Noeud {

public:
	Ordinateur();
	Ordinateur(int pId, char* pNom, bool pLienfilaire);
	~Ordinateur();

private:
	bool lienFilaire; //True indique qu'un lien filaire pourrait �tre �tabli avec l'ordinateur. False signifie que le lien sans fil pourrait �tre �tabli avec l'ordinateur.
};

#endif 
