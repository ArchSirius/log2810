/****************************************************************************
* Fichier       : Ordinateur.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Definition de la classe Ordinateur
****************************************************************************/

#ifndef ORDINATEUR_H_
#define ORDINATEUR_H_

#include "Noeud.h"

class Ordinateur : public Noeud {

public:
	Ordinateur();
	Ordinateur(int pId, char* pNom, bool pLienfilaire, bool pTypeOrdi);
	~Ordinateur();

private:
	//bool lienFilaire; //True indique qu'un lien filaire pourrait �tre �tabli avec l'ordinateur. False signifie que le lien sans fil pourrait �tre �tabli avec l'ordinateur.
};

#endif 
