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
	estEtatInitial = false;
	estEtatFinal = false;
	numEtat = 0;
	sortie = "";
}

/****************************************************************************
* Fonction		: Etat::Etat
* Description	: Constructeur par paramètre
* Paramètres	: (int) etat : le numero de l'etat
* Retour		: aucun
****************************************************************************/
Etat::Etat(int etat, string s)
{
	estEtatInitial = false;
	estEtatFinal = false;
	numEtat = etat;
	sortie = s;
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
* Fonction		: Etat::estInitiale
* Description   : set etat initial
* Paramètres    : (bool) : si l'etat est initial ou non
* Retour        : aucun
****************************************************************************/
void Etat::setInitiale(bool i)
{
	estEtatInitial = i;
}

/****************************************************************************
* Fonction		: Etat::estFinal
* Description   : set etat final
* Paramètres    : (bool) : si l'etat est final ou non
* Retour        : aucun
****************************************************************************/
void Etat::setFinal(bool f)
{
	estEtatFinal = f;
}

/****************************************************************************
* Fonction		: Etat::getEstEtatInitial
* Description   : verifie si l'etat est initial
* Paramètres    : aucun
* Retour        : (bool) : true si l'etat est initial, false sinon
****************************************************************************/
bool Etat::getEstEtatInitial() const
{
	return estEtatInitial;
}

/****************************************************************************
* Fonction		: Etat::getEstEtatFinal
* Description   : verifie si l'etat est final
* Paramètres    : aucun
* Retour        : (bool) : true si l'etat est final, false sinon
****************************************************************************/
bool Etat::getEstEtatFinal() const
{
	return estEtatFinal;
}

/****************************************************************************
* Fonction		: Etat::getNumEtat
* Description   : numero de l'etat
* Paramètres    : aucun
* Retour        : (int) : le numero de l'etat
****************************************************************************/
int Etat::getNumEtat() const
{
	return numEtat;
}

/****************************************************************************
* Fonction		: Etat::getSortie
* Description   : retourne la sortie de l'etat
* Paramètres    : aucun
* Retour        : (string) : la sortie de l'etat (Si c'est Moore sinon string vide par défaut)
****************************************************************************/
string Etat::getSortie() const
{
	return sortie;
}

/****************************************************************************
* Fonction		: Etat::getListTransition
* Description   : retourne la liste de transitions de l'etat courant
* Paramètres    : aucun
* Retour        : (list<Transition>) : la liste des Transitions
****************************************************************************/
list<Transition> Etat::getListTransition() const
{
	return listTransition;
}

/****************************************************************************
* Fonction		: Etat::existeTransition
* Description   : dit s’il existe ou non une transition portant l’etiquette 
*				  et qui part de l’etat considere.
* Paramètres    : (string) e : l'etiquette de la transition
* Retour        : (bool) true : la transition existe
				  (bool) false : la transition n'existe pas
****************************************************************************/
bool Etat::existeTransition(string e)
{
	list<Transition>::iterator it = listTransition.begin();
	while (it != listTransition.end())
	{
		if (it->getEtiquette() == e)
			return true;
	}
	return false;
}

/****************************************************************************
* Fonction		: Etat::cible
* Description   : retourne l’ensemble des etats de destination des transitions
*                 portant l’etiquette e et partant de l’etat considere.
* Paramètres    : (string) e : l'etiquette de la transition de la destination
* Retour        : (list<int>) la liste des etats de destination pour les
*								  transitions avec l'etiquette e
****************************************************************************/
list<int> Etat::cible(string e)
{
	list<int> etatCible;
	list<Transition>::iterator it = listTransition.begin();
	while (it != listTransition.end())
	{
		//si etat de depart est this et que l'etiquette == e et que transition existe alors ajoute etat destination dans la liste
		if (existeTransition(e) && it->getEtiquette() == e && numEtat == it->getEtatDepart())
			etatCible.push_back(it->getEtatDestination());
	}
	return etatCible;
}

/****************************************************************************
* Fonction		: Etat::cible
* Description   : retourne l’ensemble de tous les etats de destination pour
*				  toutes les transitions qui partent de l’etat considere.
* Paramètres    : aucun
* Retour        : (list<int>) la liste des numero des etats de destination pour
*				  toutes les transitions partant de this
****************************************************************************/
list<int> Etat::cible()
{
	list<int> etatCible;
	list<Transition>::iterator it = listTransition.begin();
	//Pour tout les transitions de la liste on ajoute l'etat dest 
	while (it != listTransition.end())
	{
		//si etat de depart est this alors ajoute etat destination dans la liste
		if (numEtat == it->getEtatDepart())
			etatCible.push_back(it->getEtatDestination());
	}
	return etatCible;
}

/****************************************************************************
* Fonction		: Etat::ajouterTransition
* Description   : permet d’ajouter une transition qui part de l’etat courant
*				  pour l’etat de destination et portant un ensemble ou liste de symboles c
* Paramètres    : (string) c : symbole c de transition
*				  (Etat*) destination : etat de destination
* Retour        : aucun
****************************************************************************/
void Etat::ajouterTransition(Transition::Type type, string c, Etat* destination, string sortie)
{
	//si mealy -> sortie associé a la transition
	if (type == Transition::MOORE)
	{
		//creation de la transition avec sortie (mealy)
		Transition transition(type, c, getNumEtat(), destination->getNumEtat(), sortie);
		//ajout de la transition a la liste de transitions
		listTransition.push_back(transition);
	}
	else
	{
		//creation de la transition sans sortie
		Transition transition(type, c, getNumEtat(), destination->getNumEtat());
		//ajout de la transition a la liste de transitions
		listTransition.emplace_back(transition);
	}
		
	
}



/****************************************************************************
* Fonction		: Etat::listerEtiquettesTransitions
* Description   : retourne l’ensemble des symboles etiquetant toutes les 
*				  transitions qui partent de l’etat courant.
* Paramètres    : aucun
* Retour        : (list<string>) :Liste des étiquettes de transitions
****************************************************************************/
list<string> Etat::listerEtiquettesTransitions()
{
	list<string> listEtiquettes;
	list<Transition>::iterator it = listTransition.begin();
	while (it != listTransition.end())
	{
		if (numEtat == it->getEtatDepart())
			listEtiquettes.push_back(it->getEtiquette());
		it++;
	}
	return listEtiquettes;
}

bool Etat::operator==(const Etat& e)
{
	if(getNumEtat() == e.getNumEtat())
		return true;
	else
		return false;
}