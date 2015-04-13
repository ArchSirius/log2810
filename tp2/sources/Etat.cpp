/****************************************************************************
* Fichier       : Etat.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 13 avril 2015
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
* Fonction		: Etat::Etat
* Description   : constructeur par copie
* Paramètres    : (Etat) e : l'etat de comparaison
* Retour        : (Etat) e : etat copier
****************************************************************************/
Etat::Etat(const Etat& e)
{
	estEtatInitial = e.estEtatInitial;
	estEtatFinal = e.estEtatFinal;
	numEtat = e.numEtat;
	sortie = e.sortie;
	list<Transition>::const_iterator it = e.listTransition.begin();
	for (; it != e.listTransition.end(); it++)
	{
		listTransition.push_back(*it);
	}
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
* Fonction		: Etat::setFinal
* Description   : set etat final
* Paramètres    : (bool) : si l'etat est final ou non
* Retour        : aucun
****************************************************************************/
void Etat::setFinal(bool f)
{
	estEtatFinal = f;
}

/****************************************************************************
* Fonction		: Etat::setNumEtat
* Description   : set numero de l'etat
* Paramètres    : (int) : le numero de l'etat (ID)
* Retour        : aucun
****************************************************************************/
void Etat::setNumEtat(int ID)
{
	numEtat = ID;
}

/****************************************************************************
* Fonction		: Etat::setSortie
* Description   : set etat final
* Paramètres    : (string) nouvSortie: la nouvelle sortie de l'etat
* Retour        : aucun
****************************************************************************/
void Etat::setSortie(string nouvSortie)
{
	sortie = nouvSortie;
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
* Fonction		: Etat::listPtrTransition
* Description   : retourne la liste de transitions de l'etat courant (ptr)
* Paramètres    : aucun
* Retour        : (list<Transition*>) : la liste des Transitions
****************************************************************************/
list<Transition*> Etat::listPtrTransition()
{
	list<Transition*> liste;
	list<Transition>::iterator it = listTransition.begin();
	for (; it != listTransition.end(); it++)
	{
		liste.push_back(&(*it));
	}
	return liste;
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
		it++;
	}
	return etatCible;
}

/****************************************************************************
* Fonction		: Etat::ajouterTransition
* Description   : permet d’ajouter une transition qui part de l’etat courant
*				  pour l’etat de destination et portant un ensemble ou liste de symboles c
* Paramètres    : (Type) type : le type de l'automate
*				  (string) entre : l'entre
*				  (Etat*) destination : etat de destination
*				  (string) sortie : la sortie si aucune on met une chaine vide
* Retour        : aucun
****************************************************************************/
void Etat::ajouterTransition(Transition::Type type, string entre, Etat* destination, string sortie)
{
	//si Moore ou Fini, la sortie sera un string vide
		Transition transition(type, entre, getNumEtat(), destination->getNumEtat(), sortie);
		//ajout de la transition a la liste de transitions
		listTransition.push_back(transition);
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

/****************************************************************************
* Requis #5
* Fonction		: Etat::convertisseurMoore2Mealy
* Description	: Convertit un état d'un automate de Moore en état d'un
                  automate de Mealy
* Parametre	    : aucun
* Retour		: aucun
****************************************************************************/
void Etat::convertisseurMoore2Mealy()
{
	list<Transition>::iterator it = listTransition.begin();
	string etiquette = "";
	for (; it != listTransition.end(); it++)
	{
		it->setSortie(sortie);
		it->setType(Transition::MEALY);
		etiquette = it->getEtiquette();
		etiquette += ", " + sortie;
		it->setEtiquette(etiquette);
	}
	sortie = "";
}

/****************************************************************************
* Fonction		: Etat::majNum
* Description	: Met à jour le numéro d'état des transitions sortantes
* Parametre	    : aucun
* Retour		: aucun
****************************************************************************/
void Etat::majNum()
{
	list<Transition>::iterator it = listTransition.begin();
	while (it != listTransition.end())
	{
		it->setEtatDepart(numEtat);
		it++;
	}
}

/****************************************************************************
* Fonction		: Etat::operator==
* Description   : verifie si les etats ont le meme numero d'etat
* Paramètres    : (Etat) e : l'etat de comparaison
* Retour        : (bool) true : etat avec le meme Id
				  (bool) false : etat n'a pas le meme Id
****************************************************************************/
bool Etat::operator==(const Etat& e)
{
	if(getNumEtat() == e.getNumEtat())
		return true;
	else
		return false;
}

/****************************************************************************
* Fonction		: Transition::estEquivalent
* Description	: Vérifie si deux états on un comportement identiques MEALY SEULEMENT
* Paramètres	: (Etat) e : l'etat de comparaison
* Retour		: (bool) true : etat avec les mêmes transitions
				  (bool) false : etat n'a pas les mêmes transitions
****************************************************************************/
bool Etat::estEquivalent(Etat e)
{
	listTransition.sort();
	e.listTransition.sort();
	//parcourir la liste des transition de l'etat
	list<Transition>::iterator it = listTransition.begin();
	list<Transition>::iterator itDest = e.listTransition.begin();
	//si les deux listes on pas la meme taille alors elle ne sont pas equivalente
	if (listTransition.size() != e.listTransition.size())
		return false;
	while (it != listTransition.end() && itDest != e.listTransition.end())
	{
		//verifier si l'étiquette et l'etat est est le même
		if (it->getEtiquette() != itDest->getEtiquette() || it->getEtatDestination() != itDest->getEtatDestination())
			return false;
		it++;
		itDest++;
	}
	return true;
}