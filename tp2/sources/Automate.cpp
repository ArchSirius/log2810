/****************************************************************************
* Fichier       : Automate.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 26 mars 2015
* Description   : Implementation de la classe Automate
****************************************************************************/

#include "headers/Automate.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

/****************************************************************************
* Fonction		: Automate::Automate
* Description	: Constructeur par defaut
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
Automate::Automate() {
	nbEtats = 0;
	type = FINI;
}

/****************************************************************************
* Fonction		: Automate::Automate
* Description	: Constructeur par parametre
* Parametre	    : (Type) type : le type de l'automate Fini, Mealy ou Moore
*				  (list<Etat>) listEtat : liste des états
* Retour		: aucun
****************************************************************************/
Automate::Automate(Type type, list<Etat> listEtat)
{
	//besoin pour minimiser Mealy
}

/****************************************************************************
* Tache #3
* Fonction		: Automate::Automate
* Description	: Constructeur par parametre
* Parametre	    : (string) fichier : fichier descriptif pour creer un automate
* Retour		: aucun
****************************************************************************/
Automate::Automate(string fichier) {
	ifstream lecture(fichier);
	if(lecture) {
		string input;
		getline(lecture, input);
		if(input.substr(0, input.find(" ") ) == "Fini") {
			type = Automate::FINI;
		}
		else if(input.substr(0, input.find(" ") ) == "Moore") {
			type = Automate::MOORE;
		}
		else if(input.substr(0, input.find(" ") ) == "Mealy") {
			type = Automate::MEALY;
		}
		else {
			cerr << "Fichier non conforme" << endl;
			lecture.close();
			return;
		}

		// try catch numberformatexception
		nbEtats = atoi(input.substr(input.find(" ") + 1).c_str());

		// Creation des etats et leurs attributs et transitions
		
		switch(type) {
			case Automate::FINI:
				while (!lecture.eof()) {
					getline(lecture, input);
					buildFini(input);
				}
				break;
			case Automate::MOORE:
				while (!lecture.eof()) {
			
				}
				break;
			case Automate::MEALY:
				while (!lecture.eof()) {
			
				}
				break;
		}

		lecture.close();
	}
	else {
		cerr << "Fichier introuvable" << endl;
	}
}

void Automate::buildBase(string input) {
	Etat tampon;
	// Si I, creer Etat et mettre initial
	if(input.at(0) == 'I') {
		// DEBUG
		cout << "Initial state detected" << endl;
		// Si aussi T, mettre aussi terminal
		if(input.at(2) == 'T') {
			// DEBUG
			cout << "Terminal state detected" << endl;
			string s = & input.at(4);
			s = s.substr(0,1);
			tampon = Etat(atoi(s.c_str()));
			tampon.setInitiale(true);
			tampon.setFinal(true);
			ListeEtats.push_back(tampon);
		}
		// Etat initial
		else {
			string s0 = & input.at(2);
			s0 = s0.substr(0,1);
			tampon = Etat(atoi(s0.c_str()));
			tampon.setInitiale(true);
			ListeEtats.push_back(tampon);
		}
	}
	// Sinon, si T, creer Etat et mettre terminal
	else if(input.at(0) == 'T') {
		// DEBUG
		cout << "Terminal state detected" << endl;
		string s1 = & input.at(2);
		s1 = s1.substr(0,1);
		tampon = Etat(atoi(s1.c_str()));
		tampon.setFinal(true);
		ListeEtats.push_back(tampon);
	}
}

void Automate::buildFini(string input) {
	// Si I ou T, cas spéciaux communs
	if(input.at(0) == 'I' || input.at(0) == 'T') {
		buildBase(input);
	}
	// Sinon, transition
	else {
		// DEBUG
		cout << "Transition detected" << endl;
		// Si Etat B n'existe pas, creer Etat B
		Etat* b;
		string s2 = & input.at(4);
		s2 = s2.substr(0,1);
		Etat tampon = Etat(atoi(s2.c_str()));
		list<Etat>::iterator it = ListeEtats.begin();
		while(it != ListeEtats.end())
			it++;
		if(it != ListeEtats.end())
			b = &(*it);
		else {
			b = &tampon;
			ListeEtats.push_back(*b);
		}
		Etat tampon2;//MODIFICATION TEMPORAIRE POUR RÉGLER LE PROBLEM LORSQU'ON MODIFIE TAMPON
		// Si Etat A n'existe pas, creer Etat A
		string s3 = & input.at(0);
		s3 = s3.substr(0,1);
		tampon2 = Etat(atoi(s3.c_str()));
		it = ListeEtats.begin();
		while(it != ListeEtats.end())
			it++;
		if(it != ListeEtats.end()) {
			string s4 = & input.at(2);
			s4 = s4.substr(0,1);
			(*it).ajouterTransition(Transition::FINI, s4, b, "");
		}
		else {
			string s5 = & input.at(2);
			s5 = s5.substr(0,1);
			tampon2.ajouterTransition(Transition::FINI, s5, b, "");
			ListeEtats.push_back(tampon2);
		}
	}
}

void Automate::buildMoore(string input) {
	// Si I ou T, cas spéciaux communs
	if(input.at(0) == 'I' || input.at(0) == 'T') {
		buildBase(input);
	}
	// Sinon, transition
	else {

	}
}

void Automate::buildMealy(string input) {
	// Si I ou T, cas spéciaux communs
	if(input.at(0) == 'I' || input.at(0) == 'T') {
		buildBase(input);
	}
	// Sinon, transition
	else {
		
	}
}

/****************************************************************************
* Fonction		: Automate::~Automate
* Description	: Destructeur
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
Automate::~Automate() {
	//detruit toutes les transition puis les etats
}

/****************************************************************************
* Tache #9
* Fonction		: Automate::etatInitial
* Description	: Retourne l'etat initial de l'automate
* Parametre	    : aucun
* Retour		: (Etat) etat initial
****************************************************************************/
Etat Automate::etatInitial() {
	Etat etat;
	//parcours la liste d'états 
	list<Etat>::iterator itEtats = ListeEtats.begin();
	while(itEtats != ListeEtats.end())
	{
		//l'etat est initial?
		if(itEtats->getEstEtatInitial() == true)
			return etat;
		else
			cerr << "Il n'y a pas d'etat initial. Machine à Etats invalide";
		itEtats++;
	}
	return 0;
}

/****************************************************************************
* Tache #10
* Fonction		: Automate::ajouterEtat
* Description	: Ajoute un nouvel etat a l'automate
* Parametre	    : (Etat) e : etat a ajouter
* Retour		: aucun
****************************************************************************/
void Automate::ajouterEtat(Etat e) {

}

/****************************************************************************
* Tache #12
* Fonction		: Automate::genererFichierAutomate
* Description	: Genere un fichier descriptif de l'automate utilisable dans
                  son constructeur par parametre
* Parametre	    : (string) fichier : fichier de sortie a enregistrer
* Retour		: aucun
****************************************************************************/
void Automate::genererFichierAutomate(string fichier) {

}

/****************************************************************************
* Requis #1
* Fonction		: Automate::estDeterministe
* Description	: Determine si l'automate est deterministe si pour chaque
                  etat une seule transition est associee a chaque symbole
* Parametre	    : aucun
* Retour		: (bool) true = deterministe / false = non deterministe
****************************************************************************/
bool Automate::estDeterministe() {
	list<Etat>::iterator itEtat = ListeEtats.begin();
	
	//parcours chaque etat
	for (; itEtat != ListeEtats.end(); itEtat++)
	{
		//liste des symboles
		list<string> listSymb = itEtat->listerEtiquettesTransitions();

		//trouver si unique
		list<string> listTemp = listSymb;
		listTemp.unique();

		//si non unique
		if (listTemp.size() != listSymb.size())
			return false;
	}
	return true;
}

/****************************************************************************
* Requis #2
* Fonction		: Automate::estReactif
* Description	: Determine si la sortie de l'automate est une fonction si
                  chaque etat possede une sortie par entree
* Parametre	    : aucun
* Retour		: (bool) true = reactif / false = non reactif
****************************************************************************/
bool Automate::estReactif() {
	
	//boolean pour savoir si est reactif
	bool estReactif = false;
	//Pour chaque etat
	list<Etat>::iterator itEtats = ListeEtats.begin();
	//la liste des transitions et un iterator sur celle-ci
	list<Transition> ListeTransition = itEtats->getListTransition();
	list<Transition>::iterator itTransition = ListeTransition.begin();

	while(itEtats != ListeEtats.end())
	{	
		if(Automate::type == MEALY)
		{
			//sortie de la premiere transition de l'etat
			string sortie = itTransition->getSortie();
			//pour chaque transition il y a exactement une sortie associe
			for(; itTransition != ListeTransition.end(); itTransition++)
			{
				//si la sortie est pas la meme alors on retourne false
				if(itTransition->getSortie() != sortie)
					return false;
			}
		}
		else if(Automate::type == MOORE)
		{
			//ID du premier etat resultant (pour aller voir sa sortie)
			int IDetat = itTransition->getEtatDestination();
			//aller chercher la sortie de l'etat a l'indice du int etat dans la liste d'etat
			auto EtatResultant = ListeEtats.begin();
			advance(EtatResultant, IDetat);
			//sortie de la premiere transition de l'etat
			string sortie = EtatResultant->getSortie();

			for(; itTransition != ListeTransition.end(); itTransition++)
			{
				//va chercher la sortie de chacun des etat pointe par l'etat courant
				IDetat = itTransition->getEtatDestination();
				EtatResultant = ListeEtats.begin();
				advance(EtatResultant, IDetat);
				//sortie pour chaque etat de destination
				sortie = EtatResultant->getSortie();
				//la sortie de chaque etat resultant est la meme?
				if(EtatResultant->getSortie() != sortie)
					return false;
			}
			
		}
		else if(Automate::type == FINI)
			return false;

		itEtats++;
	}
	return true;
}

/****************************************************************************
* Requis #3
* Fonction		: Automate::minimiserMealy
* Description	: Minimise l'automate de Mealy associe
* Parametre	    : aucun
* Retour		: (Automate) automate de Mealy minimise equivalent
****************************************************************************/
Automate Automate::minimiserMealy() {

	//Matrice d'équivalence des chemins comme vue en cours
	vector< vector<bool> > matriceSnPlus1;
	matriceSnPlus1.reserve(nbEtats);

	//Initialisation : on met toutes les cases a true
	for (unsigned int i = 0; i < nbEtats; i++){
		vector<bool> temp;
		temp.reserve(nbEtats);
		for (unsigned int j = 0; j < nbEtats; j++){
			temp.push_back(true);
		}
		matriceSnPlus1.push_back(temp);
	}

	vector< vector<bool> > matriceSn;
	do
	{
		matriceSn = matriceSnPlus1;

		//pour chaque ligne de Sn+1
		for (Etat etat : ListeEtats)
		{
			list<int> etatCible = etat.cible();
			//pour chaque colonne
			for (int e : etatCible)
			{
				//on met les états de destination a false
				//est-ce qu'il faut vérifier si les étiquettes sont identique???????????????????
				matriceSnPlus1[etat.getNumEtat()][e] = false;
			}
		}
	} while (matriceSnPlus1 != matriceSn);




	//déterminer les etats qui sont equivalent
	list<string> etatEq;
	for (unsigned int i = 0; i < nbEtats; i++){
		for (unsigned int j = 0; j < nbEtats; j++){
			if (i == j)/// on regarde ou pas????????????
			{
			}
			else
			{
				//on minimise
				if (matriceSnPlus1[i][j] == true)
				{
					// p-e a repenser----------------------------
					string egalite = (i < j) ? i + "=" + j : j + "=" + i;
					etatEq.push_back(egalite);//on identifie les etats equivalentes
				}
			}
		}
	}
	etatEq.unique();//enleve doublons



		//On crer l'automate minimise
		//list avec le nombre d'état minimal
		list<Etat> etatMinimise;
		for (unsigned int i = 0; i < nbEtats - etatEq.size(); i++)
		{
			etatMinimise.push_back(Etat());
		}

		list<Etat>::iterator it = ListeEtats.begin();
		list<Etat>::iterator itMin = etatMinimise.begin();
		for (; it != ListeEtats.end(); it++)
		{
			//On doit établir les transitions pr chaque état

			//il faut gerer etat init et final
			
			//si une transition demande une des états qui a été enlevé 
			//on doit lui dire d'allez voir l'état équivalent restant
			//on ajoute une par une les transition
			//(*itMin).ajouterTransition(Transition::MEALY, string c, Etat* destination, string sortie)
		}

		return Automate(Automate::MEALY, etatMinimise); // compilation
}



/****************************************************************************
* Requis #4
* Fonction		: Automate::calculerSortie
* Description	: Determine la chaine de sortie en fonction de la chaine
                  d'entree
* Parametre	    : (string) mot : chaine d'entree
* Retour		: (string) chaine de sortie
****************************************************************************/
string Automate::calculerSortie(string mot) {
	//trouver l'etat initial
	Etat etat = etatInitial(); //Implémenter operator= de la classe Etat??
	string sortie = "";

	//Pour chaque caractere du string d'entree (mot)
	for(unsigned int i = 0; i < mot.length(); ++i)
	{
		char entree = mot[i];
		//pour pouvoir recuperer les transitions d'un etat
		list<Transition> listTransitionsEtat = etat.getListTransition();
		list<Transition>::iterator itTransitions = listTransitionsEtat.begin();
		//appliquer le caractere du mot à l'etat
		for(;itTransitions != listTransitionsEtat.end(); itTransitions++)
		{
			//prendre le string en entree et le convertir en char pour pouvoir comparer
			char c = itTransitions->getEntre()[0];										//A VERIFIER CONVERSION EN CHAR
			//faire la bonne transition selon si c'est 1 ou 0
			if(c == entree)
			{
				//Prendre la sortie de cette transition, la mettre dans le string de sortie
				sortie += itTransitions->getSortie();
				//aller chercher le ID de l'etat dest 
				int IDetat = itTransitions->getEtatDestination();
				//trouver cet etat et mettre a jour la variable etat
				auto EtatDest = ListeEtats.begin();
				advance(EtatDest, IDetat);
				etat = *EtatDest;
			}
		}
	}
	return sortie;
}

/****************************************************************************
* Requis #5
* Fonction		: Automate::convertisseurMoore2Mealy
* Description	: Convertit un automate de Moore en automate de Mealy
* Parametre	    : aucun
* Retour		: aucun
****************************************************************************/
void Automate::convertisseurMoore2Mealy() {

}

/****************************************************************************
* Requis #6
* Fonction		: Automate::convertisseurMealy2Moore
* Description	: Convertit un automate de Mealy en automate de Moore
* Parametre	    : aucun
* Retour		: aucun
****************************************************************************/
void Automate::convertisseurMealy2Moore() {

}
