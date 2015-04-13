/****************************************************************************
* INF2810 - TP2 - Hiver 2015
* Fichier       : main.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 13 avril 2015
* Description   : Modélisation d'automates
****************************************************************************/

#include "headers/Automate.h"
#include "headers/Etat.h"
#include "headers/Transition.h"

#include <iostream>

using namespace std;

int main()
{
	//TEST prof
	Automate autoDet("Fini.txt");
	Automate autoMoore("Moore.txt");
	Automate autoMealy("Mealy.txt");

	//RF1
	cout << "L'automate FINI est " << (autoDet.estDeterministe() ? "deterministe" : "non-deterministe") << endl;

	//RF2
	cout << "l'automate MEALY est " << (autoMealy.estReactif() ? "reactif" : "non reactif") << endl;

	//RF3
	Automate autoMealyAMinimiser("MealyAMinimiser.txt");
	Automate autoMealyMin(autoMealyAMinimiser.minimiserMealy());
	autoMealyMin.genererFichierAutomate("MealyAMinimiser_solution.txt");

	//RF4
	Automate autoMooreAddMod10("MooreAddMod10.txt");
	cout << "La sortie pour l'entree 11011100111111 avec l'addition modulo 10 avec MOORE est: " << autoMooreAddMod10.calculerSortie("11011100111111") << endl;

	//RF5
	Automate autoMooreAConvertir("Moore2Mealy.txt");
	autoMooreAConvertir.convertisseurMoore2Mealy();
	autoMooreAConvertir.genererFichierAutomate("Moore2Mealy_solution.txt");

	//RF6
	Automate autoMealyAConvertir("Mealy2Moore.txt");
	autoMealyAConvertir.convertisseurMealy2Moore();
	autoMealyAConvertir.genererFichierAutomate("Mealy2Moore_solution.txt");

	//RF7
	Automate autoMooreRF7("MooreMod3.txt");
	cout << "La sortie pour l'entree 1111 avec MOORE modulo 3 est: " << autoMooreRF7.calculerSortie("1111") << endl;
	cout << "La sortie pour l'entree 1010 avec MOORE modulo 3 est: " << autoMooreRF7.calculerSortie("1010") << endl;
	cout << "La sortie pour l'entree 1110 avec MOORE modulo 3 est: " << autoMooreRF7.calculerSortie("1110") << endl;

	//cout << "La sortie avec Mealy est: " << autoMealy.calculerSortie("01010") << endl;

	system("PAUSE");
}