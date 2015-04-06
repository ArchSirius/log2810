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
	Automate autoTest("Fini.txt");
	autoTest.genererFichierAutomate("test.txt");
	Automate autoMooreTest("Moore.txt");
	autoMooreTest.genererFichierAutomate("testMoore.txt"); 
	Automate autoMealyTest("Mealy.txt");
	autoMealyTest.genererFichierAutomate("testMealy.txt");


	////TEST prof
	Automate autoDet("Fini.txt");
	//Automate autoMoore("Moore.txt");
	//Automate autoMealy("Mealy.txt");

	////RF1
	cout << "L'automate est " << (autoDet.estDeterministe() ? "deterministe" : "non-deterministe") << endl;

	////RF2
	//cout << "l'automate est " << (autoMoore.estReactif() ? "reactif" : "non reactif") << endl;

	////RF3
	//Est-ce qu'on doit faire moore minimiser en mealy??????
	//Automate autoMealyAMinimiser("MealyAMinimiser.txt");
	//Automate autoMinMealy(autoMealyAMinimiser.minimiserMealy());
	//autoMinMealy.genererFichierAutomate("minimiser.txt");

	////RF4
	//Automate autoMooreAddMod10(/*fichier ici : voir enonce*/);
	//cout << La sortie est : << autoMooreAddMod10.calculerSortie("1000") << endl;

	////RF5
	//Automate autoMooreToMealy(autoMoore.convertisseurMoore2Mealy());
	//autoMooreToMealy.genererFichierAutomate("MooreToMealy");

	////RF6
	//Automate autoMealyToMoore(autoMealy.convertisseurMealy2Moore());
	//autoMealyToMoore.genererFichierAutomate("MealyToMoore");
	//
	////RF7
	//Automate autoMooreRF7(/*fichier ici : voir enonce*/);
	//cout << La sortie est : << autoMooreRF7.calculerSortie("001") << endl;
	//cout << La sortie est : << autoMooreRF7.calculerSortie("1010") << endl;
	//cout << La sortie est : << autoMooreRF7.calculerSortie("1110") << endl;

	system("PAUSE");
}