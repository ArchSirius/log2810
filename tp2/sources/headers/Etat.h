/****************************************************************************
* Fichier       : Etat.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise � jour   : 13 avril 2015
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
	Etat(int etat, string sortie = "");//� ajouter? : Parametre pour le type de machine (fini, moore, mealy) et symbole en sortie si moore?
	Etat(const Etat& e);
	~Etat();

	//Getter et setter
	void setInitiale(bool i);
	void setFinal(bool f);
	void setNumEtat(int ID);
	void setSortie(string nouvSortie);
	bool getEstEtatInitial() const;
	bool getEstEtatFinal() const;
	int getNumEtat() const;
	string getSortie() const;
	list<Transition> getListTransition() const;
	list<Transition*> listPtrTransition();

	//Taches et RF
	bool existeTransition(string e);
	list<int> cible(string e);
	list<int> cible();
	void ajouterTransition(Transition::Type type, string entre, Etat* destination, string sortie);
	list<string> listerEtiquettesTransitions(); //retourne l�ensemble des symboles etiquetant toutes les transitions qui partent de l�etat courant
	void convertisseurMoore2Mealy();
	void majNum();

	//surcharge d'operateur
	bool operator==(const Etat& e);
	bool estEquivalent(Etat e);

private:
	bool estEtatInitial;
	bool estEtatFinal;
	int numEtat;
	string sortie;
	list<Transition> listTransition; //Liste des transitions possibles, donc on a acces aux etiquettes

};
#endif