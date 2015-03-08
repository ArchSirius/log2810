/****************************************************************************
* Fichier       : Noeud.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Definition de la classe Noeud
****************************************************************************/

#ifndef NOEUD_H_
#define NOEUD_H_

#include <vector>
#include "iostream"
using namespace std;

class Noeud{

public:
	enum Type {NOEUD, ROUTEUR, COMMUTATEUR, SERVEUR, PC, LAPTOP, TABLETTE, IMPRIMANTE, ORDINATEUR};
	
	Noeud();
	Noeud(int pId, char* pNom);
	virtual ~Noeud();

	unsigned int getId() const;
	string getNom() const;
	Type getNumType() const;
	const char* getNomType() const;
	vector<Noeud*> getConnexionsFil() const;
	vector<Noeud*> getConnexionsSansFil() const;

	unsigned int getNbPortDispo() const;
	void afficherNbPortDispo() const;	//RF3

	bool connecter(Noeud* noeud);
	void deconnecter(Noeud* noeud);

	friend ostream& operator<<(ostream& os, const Noeud& noeud);
	static unsigned int instances;


protected:
	virtual bool connexionCompatible(Noeud* noeud) = 0;

	void ajouterConnexion(Noeud* noeud, bool lienFilaire);
	void retirerConnexion(Noeud* noeud, bool lienFilaire);

	static const unsigned int MAXSIZE = 255;

	unsigned int id; //Identifiant du noeud
	Type numType; //Identifiant du type
	char nom[MAXSIZE]; //Nom du noeud
	unsigned int capaciteEthernet;
	bool reseauSansFil;
	vector<Noeud*> connexionsFil;
	vector<Noeud*> connexionsSansFil;
};

#endif 
