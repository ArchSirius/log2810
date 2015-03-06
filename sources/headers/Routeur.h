/****************************************************************************
* Fichier       : Routeur.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 19 février 2015
* Description   : Definition de la classe Routeur
****************************************************************************/
#ifndef ROUTEUR_H_
#define ROUTEUR_H_

#include "Noeud.h"

class Routeur : public Noeud {

public:
	Routeur();
	Routeur(int pId, char* pNom, unsigned int pCapacite, bool pReseauSansFil);
	~Routeur();

	virtual bool connexionCompatible(Noeud* noeud);
private:
	//unsigned int capacite; //Nombre maximal de ports
	//bool carteWifi; //Indique si le routeur dispose d'une carte r�seau sans fil
	//bool lienfilaire; //True indique que des liens filaires pourraient �tre �tablis. False signifie que des liens filaires ne pourraient pas �tre �tablis;
	//bool lienWifi; //True indique que des liens sans fil pourraient \^{e}tre \'{e}tablis. 0 signifie que des liens sans fil ne pourraient pas \^{e}tre \'{e}tablis.
};

#endif