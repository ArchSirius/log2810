/****************************************************************************
* Fichier       : Etat.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 26 mars 2015
* Description   : Definition de la classe Etat
****************************************************************************/
#ifndef ETAT_H
#define ETAT_H

#include <string> 
#include <list>
#include "Transition.h"
using namespace std;

class Etat {

public:
	Etat();
	Etat(bool etatInitial, bool etatFinal, unsigned int numEtat);//À ajouter? : Parametre pour le type de machine (fini, moore, mealy)
	~Etat();

	//Getter et setter
	list<Etat*> getEtatCible();//???
	list<char> getListeEtiquette();//???

	bool existeTransition(char e);
	list<Etat*> cible(char e);
	list<Etat*> cible();
	void ajouterTransition(list<char> c, Etat destination);
	list<char> listerEtiquettes(); //retourne l’ensembl des symboles etiquetant toutes les transitions qui partent de l’´etat courant

	
private:
	bool etatInitial;
	bool etatFinal;
	unsigned int numEtat;
	list<Etat*> etatCible;
	list<Transition> listTransition; //Liste des transitions possibles

};
#endif