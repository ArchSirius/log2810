#include "Noeud.h"

class Ordinateur : public Noeud {

public:
	Ordinateur();
	Ordinateur(int numT, int pId, char* pNom);
	~Ordinateur();

private:
	bool lienfilaire; //True indique qu'un lien filaire pourrait �tre �tabli avec l'ordinateur. False signifie que le lien sans fil pourrait �tre �tabli avec l'ordinateur.
};
