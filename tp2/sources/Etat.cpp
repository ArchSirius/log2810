/****************************************************************************
* Fichier       : Etat.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 26 mars 2015
* Description   : Implementation de la classe Etat
****************************************************************************/

#include "headers/Etat.h"

/****************************************************************************
* Fonction		: Etat::Etat
* Description	: Constructeur par defaut
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
Etat::Etat()
{
	etatInitial = false;
	etatFinal = false;
	numEtat = 0;
}

/****************************************************************************
* Fonction		: Etat::Etat
* Description	: Constructeur par paramètre
* Paramètres	: 
* Retour		: aucun
****************************************************************************/
Etat::Etat(bool etatInitial, bool etatFinal, unsigned int numEtat)
{
	etatInitial = etatInitial;
	etatFinal = etatFinal;
	numEtat = numEtat;
}

/****************************************************************************
* Fonction		: Etat::~Etat
* Description	: Destructeur de la classe etat 
* Paramètres	: auncun
* Retour		: aucun
****************************************************************************/
Etat::~Etat()
{

}

/****************************************************************************
* Fonction		: Etat::existeTransition
* Description   : dit s’il existe ou non une transition portant l’etiquette 
*				  et qui part de l’etat considere.
* Paramètres    : (char) e : l'etiquette de la transition
* Retour        : (bool) true : la transition existe
				  (bool) false : la transition n'existe pas
****************************************************************************/
bool Etat::existeTransition(char e)
{
	
}

/****************************************************************************
* Fonction		: Etat::cible
* Description   : retourne l’ensemble des etats de destination des transitions
*                 portant l’etiquette e et partant de l’etat considere.
* Paramètres    : (char) e : l'etiquette de la transition de la destination
* Retour        : (vector<Etat*>) la liste des etats de destination pour les
*								  transitions avec l'etiquette e
****************************************************************************/
list<Etat*> Etat::cible(char e)
{

}

/****************************************************************************
* Fonction		: Etat::cible
* Description   : retourne l’ensemble de tous les etats de destination pour
*				  toutes les transitions qui partent de l’etat considere.
* Paramètres    : aucun
* Retour        : (vector<Etat*>) la liste des etats de destination pour
*								  toutes les transitions
****************************************************************************/
list<Etat*> Etat::cible()
{

}

/****************************************************************************
* Fonction		: Etat::ajouterTransition
* Description   : permet d’ajouter une transition qui part de l’etat courant
*				  pour l’etat de destination e et portant un ensemble ou liste de symboles c
* Paramètres    : (vector<char>) c : liste de symboles c
*				  (Etat) destination : etat de destination
* Retour        : aucun
****************************************************************************/
void Etat::ajouterTransition(list<char> c, Etat destination)
{

}