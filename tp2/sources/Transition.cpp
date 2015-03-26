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
	_type = MOORE;
	_entre = "";
	_sortie = "";
	_etiquette = "";
}

/****************************************************************************
* Fonction		: Transition::Transition
* Description	: Constructeur par paramètre
* Paramètres	: (int) type : le type de la machine
				  (string) entre : le input de la transition
				  (string) sortie : la sortie de la transition initilament vide si machine de moore
* Retour		: aucun
****************************************************************************/
Transition::Transition(Type type, string entre, string sortie = "")
{
	_type = type;
	_entre = entre;
	_sortie = sortie;

	_etiquette = (type == MEALY) ? _entre + ", " + _sortie : _entre;


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
string Transition::getEtiquette()
{
	return _etiquette;
}