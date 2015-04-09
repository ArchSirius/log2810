/****************************************************************************
* Fichier       : Transition.h
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 09 mars 2015
* Description   : Definition de la classe Transition
****************************************************************************/
#ifndef TRANSITION_H_
#define TRANSITION_H_

#include <string>

using namespace std;

class Transition
{
public: 
	enum Type { FINI, MOORE, MEALY };

	Transition();
	Transition(Type type, string entre, int etatDepart, int etatPointe, string sortie = "");
	~Transition();

	string getEtiquette() const;
	int getEtatDepart() const;
	int getEtatDestination() const;
	string getEntre() const;
	string getSortie() const;
	void setSortie(string sortie);
	void setType(Type type);
	void setEtatDepart(int etat);
	void setEtatDestination(int etat);
	void setEtiquette(string etiquette);

private:
	Type _type;
	string _entre;
	string _sortie;
	string _etiquette;

	int _etatDepart;
	int _etatDestination;
};

#endif