/****************************************************************************
* Fichier       : Tablette.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Definition de la classe Tablette
****************************************************************************/
#ifndef TABLETTE_H_
#define TABLETTE_H_

#include "Noeud.h"

class Tablette : public Noeud {

public:
	Tablette();
	Tablette(int pId, char* pNom);
	~Tablette();

	virtual bool connexionCompatible(Noeud* noeud);
private:
	//carte reseau pour tous
	
};

#endif 