/****************************************************************************
* Fichier       : Imprimante.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Definition de la classe Imprimante
****************************************************************************/

#ifndef IMPRIMANTE_H_
#define IMPRIMANTE_H_

#include "Noeud.h"

class Imprimante : public Noeud {

public:
	Imprimante();
	Imprimante(int pId, char* pNom);
	~Imprimante();

	virtual bool connexionCompatible(Noeud* noeud);
	//virtual void connecter(Noeud* noeud);

private:
	//carte reseau pour tous

};
#endif