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
		Etat tampon;
		switch(type) {
			case Automate::FINI:
				while (!lecture.eof()) {
					// Si I, creer Etat et mettre initial
					if(input.at(0) == 'I') {
						// DEBUG
						cout << "Initial state detected" << endl;
						nbEtats++;
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
					// Sinon,
					else {
						// DEBUG
						cout << "Transition detected" << endl;
						// Si Etat B n'existe pas, creer Etat B
						Etat b;
						tampon = Etat((int)input.at(0));
						list<Etat>::iterator it = ListeEtats.begin();
						while(it != ListeEtats.end())
							it++;
						if(it != ListeEtats.end())
							b = *it;
						else
							b = tampon;

						// Si Etat A n'existe pas, creer Etat A
						Etat a;
						tampon = Etat((int)input.at(0));
						it = ListeEtats.begin();
						while(it != ListeEtats.end())
							it++;
						if(it != ListeEtats.end())
							a = *it;
						else
							a = tampon;

						// Appliquer la transition
						Transition transition(Transition::FINI, input.at(2) + "", input.at(0), input.at(4));
						// ajouter la transition à A
					}
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
* Fonction		: Automate::minimiserMoore
* Description	: Minimise l'automate de Moore associe
* Parametre	    : aucun
* Retour		: (Automate) automate de Moore minimise equivalent
****************************************************************************/
Automate Automate::minimiserMoore() {
	return *this; // compilation
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
