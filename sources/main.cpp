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
#include "headers/Ordinateur.h"
#include "headers/Tablette.h"
#include "headers/Imprimante.h"
#include "headers/Reseau.h"
#include "headers/Serveur.h"


using namespace std;

void lectureFichierCommutateur(Reseau& reseau);
//void lectureFichierCouts(int i);
void lectureFichierImprimante(Reseau& reseau);
void lectureFichierOrdinateur(Reseau& reseau, string typeOrdi);
//void lectureFichierReseau();
void lectureFichierRouteur(Reseau& reseau);
void lectureFichierServeur(Reseau& reseau);
void lectureFichierTablette(Reseau& reseau);
void lectureFichierType();


int main()
{
	//Création du réseau
	//Création du réseau avec la configuration 1 des couts
	unsigned int filaires, sansFil;
	string nomFichier = "couts-" + to_string(1) + ".txt";
	ifstream fichier(nomFichier);
	if (fichier)
	{
		string input, token;
		vector<string> couts;

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

	//Construction du reseau selon la configuration des couts
	Reseau reseau(filaires,sansFil);

	//Création tout d'abord des noeuds en parcourant les fichiers nécessaires
	//Les noeuds routeur
	lectureFichierRouteur(reseau);
	//Les noeuds commutateur
	lectureFichierCommutateur(reseau);
	//Les noeuds serveur
	lectureFichierServeur(reseau);
	//Les noeuds PC
	lectureFichierOrdinateur(reseau, "PC");
	//Les noeuds laptop
	lectureFichierOrdinateur(reseau, "laptop");
	//Les noeuds tablette
	lectureFichierTablette(reseau);
	//Les noeuds imprimante
	lectureFichierImprimante(reseau);
	//Mise en place du réseau
	reseau.implanter();

	reseau.afficher();
	//lectureFichierType();
	system("PAUSE");

}

void lectureFichierCommutateur(Reseau& reseau)
{
	ifstream fichier("commutateur.txt");
	if (fichier)
	{
		string input, token;
		vector<string> commutateur;
		unsigned int idCommutateur, capacite;
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
			idCommutateur = atoi(commutateur[0].c_str());
			capacite = atoi(commutateur[2].c_str());
			str_ville = commutateur[1];
			char* ville = _strdup(str_ville.c_str());

			//Construction de l'objet commutateur
			Commutateur* commutateur = new Commutateur(idCommutateur, ville, capacite);
			//Ajout de chaque commutateur dans le map de noeuds
			reseau.ajouter(commutateur);
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}
/*
void lectureFichierCouts(int i)
{
	string nomFichier = "couts-" + to_string(i) + ".txt";
	ifstream fichier(nomFichier);
	if (fichier)
	{
		string input, token;
		vector<string> couts;
		unsigned int filaires, sansFil;

		while (!fichier.eof())
		{
			couts.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, ';'))
				couts.push_back(token);

			filaires = atoi(couts[0].c_str());
			sansFil = atoi(couts[1].c_str());

			//Construction du reseau selon la configuration des couts
			Reseau reseau(filaires,sansFil);
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}*/

void lectureFichierImprimante(Reseau& reseau)
{
	ifstream fichier("imprimante.txt");
	if (fichier)
	{
		string input, token;
		vector<string> imprimante;
		unsigned int idImprimante;
		string str_nom;

		while (!fichier.eof())
		{
			imprimante.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, ';'))
				imprimante.push_back(token);

			//Conversion des string en bons types pour le constructeur
			idImprimante = atoi(imprimante[0].c_str());
			str_nom = imprimante[1];
			char* nom = _strdup(str_nom.c_str());

			//Construction de l'objet imprimante
			Imprimante* imprimante = new Imprimante(idImprimante, nom);
			//Ajout de chaque imprimante dans le map de noeuds
			reseau.ajouter(imprimante);
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}

void lectureFichierOrdinateur(Reseau& reseau, string typeOrdi)
{
	ifstream fichier(typeOrdi + ".txt");
	if (fichier)
	{
		string input, token;
		vector<string> ordi;
		unsigned int idOrdi;
		string str_nom;
		bool lienFilaire;

		//Initialisation du bool pour savoir si on a un PC ou un laptop
		bool pTypeOrdi = true;
		if (typeOrdi == "laptop")
			pTypeOrdi = false;

		while (!fichier.eof())
		{
			ordi.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, ';'))
				ordi.push_back(token);

			//Conversion des string en bons types pour le constructeur
			idOrdi = atoi(ordi[0].c_str());
			str_nom = ordi[1];
			char* nom = _strdup(str_nom.c_str());
			ordi[2] == "0" ? lienFilaire = false : lienFilaire = true;
			//Construction de l'objet ordinateur
			Ordinateur* ordi = new Ordinateur(idOrdi, nom, lienFilaire, pTypeOrdi);

			//cout << idOrdi << endl << nom << endl << lienFilaire << endl;

			//Ajout de chaque ordi dans le map de noeuds
			reseau.ajouter(ordi);
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}

void lectureFichierRouteur(Reseau& reseau)
{
	ifstream fichier("routeur.txt");
	if (fichier)
	{
		string input, token;
		vector<string> routeur;
		unsigned int idRouteur, capacite;
		string str_nom;
		bool reseauSansFil, lienFilaire, possibiliteLienFilaire;

		while (!fichier.eof())
		{
			routeur.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, ';'))
				routeur.push_back(token);

			//Conversion des string en bons types pour le constructeur
			idRouteur = atoi(routeur[0].c_str());
			str_nom = routeur[1];
			char* nom = _strdup(str_nom.c_str());
			capacite = atoi(routeur[2].c_str());
			routeur[3] == "0" ? reseauSansFil = false : reseauSansFil = true;
			routeur[4] == "0" ? lienFilaire = false : lienFilaire = true;
			routeur[5] == "0" ? possibiliteLienFilaire = false : possibiliteLienFilaire = true;

			//Constructeur de routeur
			Routeur* routeur = new Routeur(idRouteur, nom, capacite, reseauSansFil);
			//Ajout de chaque routeur dans le map de noeuds
			reseau.ajouter(routeur);
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}

void lectureFichierServeur(Reseau& reseau)
{
	ifstream fichier("serveur.txt");
	if (fichier)
	{
		string input, token;
		vector<string> serveur;
		unsigned int idServeur;
		string str_nom;

		while (!fichier.eof())
		{
			serveur.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, ';'))
				serveur.push_back(token);

			//Conversion des string en bons types pour le constructeur
			idServeur = atoi(serveur[0].c_str());
			str_nom = serveur[1];
			char* nom = _strdup(str_nom.c_str());

			//Construction de l'objet serveur
			Serveur* serveur = new Serveur(idServeur, nom);
			//Ajout de chaque serveur dans le map de noeuds
			reseau.ajouter(serveur);
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}

void lectureFichierTablette(Reseau& reseau)
{
	ifstream fichier("tablette.txt");
	if (fichier)
	{
		string input, token;
		vector<string> tablette;
		unsigned int idTablette;
		string str_nom;

		while (!fichier.eof())
		{
			tablette.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, ';'))
				tablette.push_back(token);

			//Conversion des string en bons types pour le constructeur
			idTablette = atoi(tablette[0].c_str());
			str_nom = tablette[1];
			char* nom = _strdup(str_nom.c_str());

			//Construction de l'objet tablette
			Tablette* tablette = new Tablette(idTablette, nom);
			//Ajout de chaque tablette dans le map de noeuds
			reseau.ajouter(tablette);
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}

void lectureFichierType()
{
	ifstream fichier("type.txt");
	if (fichier)
	{
		string input, token;
		vector<string> type;
		unsigned int idType;
		string str_nom;

		while (!fichier.eof())
		{
			type.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, ';'))
				type.push_back(token);

			//Conversion des string en bons types pour le constructeur
			idType = atoi(type[0].c_str());
			str_nom = type[1];
			char* nom = _strdup(str_nom.c_str());

		}
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}