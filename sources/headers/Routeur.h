#include "Noeud.h"

class Routeur : public Noeud {

public:
	Routeur();
	Routeur(int numT, int pId, char* pNom);
	~Routeur();

private:
	unsigned int capacite; //Nombre maximal de ports
	unsigned int numType;
	bool carteWifi; //Indique si le routeur dispose d'une carte r�seau sans fil
	bool lienfilaire; //True indique que des liens filaires pourraient �tre �tablis. False signifie que des liens filaires ne pourraient pas �tre �tablis;
	bool lienWifi; //True indique que des liens sans fil pourraient \^{e}tre \'{e}tablis. 0 signifie que des liens sans fil ne pourraient pas \^{e}tre \'{e}tablis.
};
