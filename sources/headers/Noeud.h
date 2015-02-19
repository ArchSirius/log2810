#ifndef NOEUD_H_
#define NOEUD_H_
#include <vector>
using namespace std;

class Noeud{

public:
	enum Type {NOEUD, ROUTEUR, COMMUTATEUR, SERVEUR, PC, LAPTOP, TABLETTE, IMPRIMANTE, ORDINATEUR};

	Noeud();
	Noeud(int pId, char* pNom);
	~Noeud();

	void connecter(Noeud* noeud);
	void deconnecter(Noeud* noeud);

	void ajouterConnexion(Noeud* noeud);
	void retirerConnexion(Noeud* noeud);

protected:
	static const unsigned int MAXSIZE = 255;

	unsigned int id; //Identifiant du noeud
	Type numType; //Identifiant du type
	char nom[MAXSIZE]; //Nom du noeud
	vector<Noeud*> connexions;
};

#endif 
