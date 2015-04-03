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
		if(input.substr(0, input.find(" ") - 1) == "Fini") {
			type = Automate::FINI;
		}
		else if(input.substr(0, input.find(" ") - 1) == "Moore") {
			type = Automate::MOORE;
		}
		else if(input.substr(0, input.find(" ") - 1) == "Mealy") {
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
			tampon = Etat((int)input.at(4));
			tampon.setInitiale(true);
			tampon.setFinal(true);
			ListeEtats.push_back(tampon);
		}
		// Etat initial
		else {
			tampon = Etat((int)input.at(2));
			tampon.setInitiale(true);
			ListeEtats.push_back(tampon);
		}
	}
	// Sinon, si T, creer Etat et mettre terminal
	else if(input.at(0) == 'T') {
		// DEBUG
		cout << "Terminal state detected" << endl;
		tampon = Etat((int)input.at(2));
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
		Etat tampon = Etat((int)input.at(0));
		list<Etat>::iterator it = ListeEtats.begin();
		while(it != ListeEtats.end())
			it++;
		if(it != ListeEtats.end())
			b = &(*it);
		else {
			b = &tampon;
			ListeEtats.push_back(*b);
		}

		// Si Etat A n'existe pas, creer Etat A
		tampon = Etat((int)input.at(0));
		it = ListeEtats.begin();
		while(it != ListeEtats.end())
			it++;
		if(it != ListeEtats.end()) {
			(*it).ajouterTransition(Transition::FINI, input.at(2) + "", b, "");
		}
		else {
			tampon.ajouterTransition(Transition::FINI, input.at(2) + "", b, "");
			ListeEtats.push_back(tampon);
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
	Etat etat; // compilation
	return etat;// compilation
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
	return false; // compilation
}

/****************************************************************************
* Requis #3
* Fonction		: Automate::minimiserMealy
* Description	: Minimise l'automate de Mealy associe
* Parametre	    : aucun
* Retour		: (Automate) automate de Mealy minimise equivalent
****************************************************************************/
Automate Automate::minimiserMealy() {
	//bool matriceChemin1[dim][dim];
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

	list<Etat> etatMinimise;
	list<Etat>::iterator it = ListeEtats.begin();
	for (unsigned int i = 0; i < nbEtats; i++){
		for (unsigned int j = 0; j < nbEtats; j++){
			if (i == j)/// on regarde ou pas????????????
			{}
			else
			{
				//on minimise
				if (matriceSnPlus1[i][j] == true)
				{

				}
				else
				{

				}
			}
			matriceSnPlus1[i][j]
		}

	return Automate(Automate::MEALY, list<Etat>); // compilation
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
	return ""; // compilation
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
