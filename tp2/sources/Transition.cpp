/****************************************************************************
* Fichier       : Transition.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 09 mars 2015
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