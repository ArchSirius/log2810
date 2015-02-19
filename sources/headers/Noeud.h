class Noeud{

public:
	Noeud();
	Noeud(int numT, int pId, char* pNom);
	~Noeud();

protected:
	static const unsigned int MAXSIZE = 255;

	unsigned int id; //Identifiant du noeud
	unsigned int numType; //Identifiant du type
	char nom[MAXSIZE]; //Nom du noeud
};
