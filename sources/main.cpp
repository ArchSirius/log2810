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

int main(){
	lectureFichierCommutateur();
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
		string ville;

		while (!fichier.eof())
		{

			commutateur.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, ';')) {
				commutateur.push_back(token);
			}

			id = atoi(commutateur[0].c_str());
			ville = commutateur[1];
			capacite = atoi(commutateur[2].c_str());


			cout << id << endl;
			cout << ville << endl;
			cout << capacite << endl;

			//Commutateur commutateur(id, ville, capacite);

		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}