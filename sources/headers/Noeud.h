class Noeud{

public:
	enum Type {NOEUD, ROUTEUR, COMMUTATEUR, SERVEUR, PC, LAPTOP, TABLETTE, IMPRIMANTE, ORDINATEUR};

	Noeud();
	Noeud(int pId, char* pNom);
	~Noeud();

	void connecter(const Noeud* noeud);
	void deconnecter(const Noeud* noeud);

protected:
	static const unsigned int MAXSIZE = 255;

	unsigned int id; //Identifiant du noeud
	Type numType; //Identifiant du type
	char nom[MAXSIZE]; //Nom du noeud
	Noeud* connexions[];
};
