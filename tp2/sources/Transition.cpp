/****************************************************************************
* Fichier       : Transition.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 13 avril 2015
* Description   : Implementation de la classe Transition
****************************************************************************/

#include "headers/Transition.h"

/****************************************************************************
* Fonction		: Transition::Transition
* Description	: Constructeur par defaut
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
Transition::Transition()
{
	_type = FINI;
	_entre = "";
	_sortie = "";
	_etiquette = "";
	_etatDepart = 0;
	_etatDestination = 0;
}

/****************************************************************************
* Fonction		: Transition::Transition
* Description	: Constructeur par paramètre
* Paramètres	: (int) type : le type de la machine
				  (string) entre : le input de la transition
				  (int) etatDepart : represente le id de l'etat de depart
				  (int) etatPointe : represente le id de l'etat de d'arrive
				  (string) sortie : la sortie de la transition initilament vide si machine de moore
* Retour		: aucun
****************************************************************************/
Transition::Transition(Type type, string entre, int etatDepart, int etatPointe, string sortie)
{
	_type = type;
	_entre = entre;
	_sortie = sortie;
	_etiquette = (type == MEALY) ? _entre + ", " + _sortie : _entre;

	_etatDepart = etatDepart;
	_etatDestination = etatPointe;
	
}

/****************************************************************************
* Fonction		: Transition::~Transition
* Description	: Destructeur
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
Transition::~Transition()
{
}

//Accesseur
string Transition::getEtiquette() const
{
	return _etiquette;
}

//Accesseur
int Transition::getEtatDepart() const
{
	return _etatDepart;
}

//Accesseur
int Transition::getEtatDestination() const
{
	return _etatDestination;
}

//Accesseur
string Transition::getEntre() const
{
	return _entre;
}

//Accesseur
string Transition::getSortie() const
{
	return _sortie;
}

//Modificateur
void Transition::setSortie(string sortie)
{
	_sortie = sortie;
}

//Modificateur
void Transition::setType(Type type)
{
	_type = type;
}

//Modificateur
void Transition::setEtatDepart(int etat)
{
	_etatDepart = etat;
}

//Modificateur
void Transition::setEtatDestination(int etat)
{
	_etatDestination = etat;
}

//Modificateur
void Transition::setEtiquette(string e)
{
	_etiquette = e;
}

/****************************************************************************
* Fonction		: Etat::operator<
* Description   : verifie si les transition sont plus petites
* Paramètres    : (Transition) t : la transition de comparaison
* Retour        : (bool) true : transition plus petite
*				  (bool) false : transition plus grande
****************************************************************************/
bool Transition::operator<(const Transition& t)
{
	if (_etatDepart < t._etatDepart)
		return true;
	else if (_etatDepart == t._etatDepart)
	{
		if (_entre < t._entre)
			return true;
	}	
	return false;
}