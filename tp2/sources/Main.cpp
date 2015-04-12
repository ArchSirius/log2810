/****************************************************************************
* INF2810 - TP2 - Hiver 2015
* Fichier       : main.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 12 avril 2015
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
/*	Automate autoTest("Fini.txt");
	autoTest.genererFichierAutomate("genererFichierFini.txt");
	Automate autoMooreTest("Moore.txt");
	autoMooreTest.genererFichierAutomate("genererFichierMoore.txt"); 
	Automate autoMealyTest("Mealy.txt");
	autoMealyTest.genererFichierAutomate("genererFichierMealy.txt");
*/
	//TD8 Ex3
/*	Automate autoMealytestMin("ex3td8.txt");
	Automate autoMealyMin(autoMealytestMin.minimiserMealy());
	cout << "TD8 Ex3 MEALY" << endl;
	cout << "La sortie pour l'entree 110: " << autoMealyMin.calculerSortie("110") << endl;
	cout << "La sortie pour l'entree 101: " << autoMealyMin.calculerSortie("101") << endl;
	cout << "La sortie pour l'entree 1010110: " << autoMealyMin.calculerSortie("1010110") << endl;

	Automate autoMooretestMin("ex3td8Moore.txt");
	Automate autoMooreMin(autoMooretestMin.minimiserMealy());
	cout << "TD8 Ex3 MOORE" << endl;
	cout << "La sortie pour l'entree 110: " << autoMooreMin.calculerSortie("110") << endl;
	cout << "La sortie pour l'entree 101: " << autoMooreMin.calculerSortie("101") << endl;
	cout << "La sortie pour l'entree 1010110: " << autoMooreMin.calculerSortie("1010110") << endl;
*/

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

	system("PAUSE");
}