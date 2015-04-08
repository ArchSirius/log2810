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
	Automate autoMoore("Moore.txt");
	Automate autoMealy("Mealy.txt");

	////RF1
	cout << "L'automate FINI est " << (autoDet.estDeterministe() ? "deterministe" : "non-deterministe") << endl;

	////RF2
	cout << "l'automate MEALY est " << (autoMealy.estReactif() ? "reactif" : "non reactif") << endl;

	////RF3
	//Est-ce qu'on doit faire moore minimiser en mealy??????
	//Automate autoMealyAMinimiser("MealyAMinimiser.txt");
	//Automate autoMinMealy(autoMealyAMinimiser.minimiserMealy());
	//autoMinMealy.genererFichierAutomate("minimiser.txt");

	////RF4
	Automate autoMooreAddMod10("MooreAddMod10.txt");
	cout << "La sortie pour l'addition modulo 10 avec MOORE est: " << autoMooreAddMod10.calculerSortie("9821") << endl;

	////RF5
	//Automate autoMooreToMealy(autoMoore.convertisseurMoore2Mealy());
	//autoMooreToMealy.genererFichierAutomate("MooreToMealy");

	////RF6
	//Automate autoMealyToMoore(autoMealy.convertisseurMealy2Moore());
	//autoMealyToMoore.genererFichierAutomate("MealyToMoore");
	//
	////RF7
	//Automate autoMooreRF7("MooreRF7.txt");
	//cout << "La sortie est: " << autoMooreRF7.calculerSortie("1111") << endl;
	//cout << "La sortie est: " << autoMooreRF7.calculerSortie("1010") << endl;
	//cout << "La sortie est: " << autoMooreRF7.calculerSortie("1110") << endl;

	system("PAUSE");
}