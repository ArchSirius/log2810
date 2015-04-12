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
	autoTest.genererFichierAutomate("genererFichierFini.txt");
	Automate autoMooreTest("Moore.txt");
	autoMooreTest.genererFichierAutomate("genererFichierMoore.txt"); 
	Automate autoMealyTest("Mealy.txt");
	autoMealyTest.genererFichierAutomate("genererFichierMealy.txt");

	//TD8 Ex3 MALADE CA MARCHE
	Automate autoMealytestMin("ex3td8.txt");
	Automate autoMealyMin(autoMealytestMin.minimiserMealy());
	cout << "TD8 Ex3" << endl;
	cout << "La sortie pour l'entree 110: " << autoMealyMin.calculerSortie("110") << endl;
	cout << "La sortie pour l'entree 101: " << autoMealyMin.calculerSortie("101") << endl;
	cout << "La sortie pour l'entree 1010110: " << autoMealyMin.calculerSortie("1010110") << endl;



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
	//Automate autoMealyMin(autoMealyAMinimiser.minimiserMealy());
	//autoMealyMin.genererFichierAutomate("genererFichierMealyMinimise.txt");

	////RF4
	Automate autoMooreAddMod10("MooreAddMod10.txt");
	cout << "La sortie pour l'entree 11011100111111 avec l'addition modulo 10 avec MOORE est: " << autoMooreAddMod10.calculerSortie("11011100111111") << endl;

	////RF5
	autoMoore.convertisseurMoore2Mealy();
	autoMoore.genererFichierAutomate("MooreToMealy.txt");

	////RF6
	Automate autoMealy2("Mealy2Moore.txt");
	autoMealy2.convertisseurMealy2Moore();
	autoMealy2.genererFichierAutomate("MealyToMoore.txt");

	////RF7
	Automate autoMooreRF7("MooreMod3.txt");
	cout << "La sortie pour l'entree 1111 avec MOORE modulo 3 est: " << autoMooreRF7.calculerSortie("1111") << endl;
	cout << "La sortie pour l'entree 1010 avec MOORE modulo 3 est: " << autoMooreRF7.calculerSortie("1010") << endl;
	cout << "La sortie pour l'entree 1110 avec MOORE modulo 3 est: " << autoMooreRF7.calculerSortie("1110") << endl;

	//cout << "La sortie avec Mealy est: " << autoMealy.calculerSortie("01010") << endl;

	system("PAUSE");
}