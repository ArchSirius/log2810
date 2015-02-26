/**
* INF2810 - TP1 - Hiver 2015
* Remise: 9 mars 2015
*
* @description: Modélisation d'un réseau informatique à l'aide de graphes et matrices
* @author: Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* @created: 2015-02-19
*/
#include <string> 
#include <iostream> 
#include <fstream> 
#include <vector>
#include <sstream>

#include "headers/Routeur.h"
#include "headers/Commutateur.h"
//#include "headers/Serveur.h"
#include "headers/Ordinateur.h"
#include "headers/Tablette.h"
#include "headers/Imprimante.h"


using namespace std;

void lectureFichierCommutateur();
void lectureFichierCouts(int i);

int main()
{
	//lectureFichierCommutateur();
	//lectureFichierCouts(4);
	system("PAUSE");
}

void lectureFichierCommutateur()
{
	ifstream fichier("commutateur.txt");
	if (fichier)
	{
		string input;
		string token;
		vector<string> commutateur;
		unsigned int id, capacite;
		string str_ville;

		while (!fichier.eof())
		{

			commutateur.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, ';')) {
				commutateur.push_back(token);
			}
			//Conversion des string en bons types pour le constructeur
			id = atoi(commutateur[0].c_str());
			capacite = atoi(commutateur[2].c_str());
			str_ville = commutateur[1];
			char* ville = _strdup(str_ville.c_str());

			//Construction de l'objet commutateur
			Commutateur commutateur(id, ville, capacite);

		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}

void lectureFichierCouts(int i)
{
	string input;
	string token;
	string nomFichier = "couts-" + to_string(i) + ".txt";
	vector<string> couts;

	ifstream fichier(nomFichier);
	if (fichier)
	{
		int filaires;
		int sansFil;

		while (!fichier.eof())
		{
			couts.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, ';'))
				couts.push_back(token);

			filaires = atoi(couts[0].c_str());
			sansFil = atoi(couts[1].c_str());
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}