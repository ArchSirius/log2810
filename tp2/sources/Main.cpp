/****************************************************************************
* INF2810 - TP2 - Hiver 2015
* Fichier       : main.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : -- avril 2015
* Description   : Modélisation d'automates
****************************************************************************/

#include "headers/Automate.h"
#include "headers/Etat.h"
#include "headers/Transition.h"

#include <iostream>

using namespace std;

int main()
{
	//TEST personelle


	
	//TEST prof
	Automate autoDet(/*paremetre ici*/);
	Automate autoMoore(/*paremetre ici*/);
	Automate autoMealy(/*paremetre ici*/);

	//RF1
	cout << "l'automate est " << (autoDet.estDeterministe() ? "deterministe" : "non-deterministe") << endl;

	//RF2
	cout << "l'automate est " << (autoMoore.estReactif() ? "reactif" : "non reactif") << endl;

	//RF3
	Automate autoMinMoore(autoMealy.minimiserMoore());

	//RF4
	Automate autoMooreAddMod10(/*paremetre ici*/);
	cout << autoMooreAddMod10.calculerSortie("1000") << endl;

	//RF5
	Automate autoMooreToMealy(autoMoore.convertisseurMoore2Mealy());

	//RF6
	Automate autoMealyToMoore(autoMealy.convertisseurMealy2Moore());
	system("PAUSE");
}