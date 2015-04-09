/****************************************************************************
* INF2810 - TP2 - Hiver 2015
* Fichier       : main.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise � jour   : -- avril 2015
* Description   : Mod�lisation d'automates
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

	Automate autoMealytestMin("testMealyMin.txt");
	autoMealytestMin.minimiserMealy();

	////TEST prof
	Automate autoDet("Fini.txt");
	Automate autoMoore("Moore.txt");
	Automate autoMealy("Mealy.txt");

	////RF1
	cout << "L'automate FINI est " << (autoDet.estDeterministe() ? "deterministe" : "non-deterministe") << endl;

	////RF2
	cout << "l'automate MEALY est " << (autoMealy.estReactif() ? "reactif" : "non reactif") << endl;

	////RF3
	Automate autoMealyAMinimiser("MealyAMinimiser.txt");
	Automate autoMealyMin(autoMealyAMinimiser.minimiserMealy());
	autoMealyMin.genererFichierAutomate("autoMealyMinimise.txt");

	////RF4
	Automate autoMooreAddMod10("MooreAddMod10.txt");
	cout << "La sortie pour l'entree 11011100111111 avec l'addition modulo 10 avec MOORE est: " << autoMooreAddMod10.calculerSortie("11011100111111") << endl;

	////RF5
	//Automate autoMooreToMealy(autoMoore.convertisseurMoore2Mealy());
	//autoMooreToMealy.genererFichierAutomate("MooreToMealy");

	////RF6
	autoMealy.convertisseurMealy2Moore();
	autoMealy.genererFichierAutomate("MealyToMoore");
	//
	////RF7

	Automate autoMooreRF7("MooreMod3.txt");
	cout << "La sortie pour l'entree 1111 avec MOORE modulo 3 est: " << autoMooreRF7.calculerSortie("1111") << endl;
	cout << "La sortie pour l'entree 1010 avec MOORE modulo 3 est: " << autoMooreRF7.calculerSortie("1010") << endl;
	cout << "La sortie pour l'entree 1110 avec MOORE modulo 3 est: " << autoMooreRF7.calculerSortie("1110") << endl;

	//cout << "La sortie avec Mealy est: " << autoMealy.calculerSortie("01010") << endl;

	system("PAUSE");
}