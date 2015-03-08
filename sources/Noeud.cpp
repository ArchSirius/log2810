/****************************************************************************
* Fichier       : Noeud.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 février 2015
* Mise à jour   : 06 mars 2015
* Description   : Implementation de la classe Noeud
****************************************************************************/
#include <string.h>
#include <algorithm>
#include <exception>
#include "headers/Noeud.h"
using namespace std;

unsigned int Noeud::instances = 0;
/****************************************************************************
* Fonction		: Noeud::Noeud
* Description	: Constructeur par defaut
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
Noeud::Noeud(){
	id = 0;
	numType = NOEUD;
	nom[0] = '\0';
	capaciteEthernet = 0;
	reseauSansFil = false;
}

/****************************************************************************
* Fonction		: Noeud::Noeud
* Description	: Constructeur par paramètre
* Paramètres	: (int) pId : le id du noeud
				  (char*) pNom : le nom du noeud
* Retour		: aucun
****************************************************************************/
Noeud::Noeud(int pId, char* pNom){
	numType = NOEUD;
	id = pId;
	strncpy_s(nom, pNom, MAXSIZE);
	nom[MAXSIZE - 1] = '\0';
	capaciteEthernet = 0;
	reseauSansFil = false;
	instances++;
}

/****************************************************************************
* Fonction		: Noeud::~Noeud
* Description	: Destructeur du noeud et on enleve toutes les connexion avec ce noeud
* Paramètres	: auncun
* Retour		: aucun
****************************************************************************/
Noeud::~Noeud(){
	for(Noeud* noeud : connexionsFil){
		deconnecter(noeud);
	}

	for (Noeud* noeud : connexionsSansFil){
		deconnecter(noeud);
	}
	instances--;
}

//Accesseur
unsigned int Noeud::getId() const{
	return id;
}

//Accesseur
string Noeud::getNom() const{
	return nom;
}

//Accesseur
Noeud::Type Noeud::getNumType() const {
	return numType;
}

//Accesseur
const char* Noeud::getNomType() const {
	const char* typeStr[] = { "NOEUD", "ROUTEUR", "COMMUTATEUR", "SERVEUR", "PC", "LAPTOP", "TABLETTE", "IMPRIMANTE", "ORDINATEUR" };
	return typeStr[numType];
}

//Accesseur
unsigned int Noeud::getCapacite() const {
	return capaciteEthernet;
}

//Accesseur
bool Noeud::getReseauSansfil() const {
	return reseauSansFil;
}

//Accesseur
unsigned int Noeud::getNbPortDispo() const {
	return capaciteEthernet - connexionsFil.size();
}

//Accesseur
vector<Noeud*> Noeud::getConnexionsFil() const {
	return connexionsFil;
}

//Accesseur
vector<Noeud*> Noeud::getConnexionsSansFil() const {
	return connexionsSansFil;
}

/*
static unsigned int Noeud::nbInstances() {
	return instances;
}
*/

/****************************************************************************
* Requis fonctionnels #3
* Fonction		: Noeud::afficherNbPortDispo
* Description	: methode pour afficher le nombre de port disponible seulement 
				  pour les commutateurs ou les routeurs
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
void Noeud::afficherNbPortDispo() const {
	if (numType == COMMUTATEUR || numType == ROUTEUR)
		cout << "Ce " << getNomType() << " lui reste " << getNbPortDispo() << " port(s) de disponible" << endl;
	else
		cout << "Desole, ce noeud n'est pas un commutateur ou un routeur" << endl;
}

/****************************************************************************
* Fonction		: Noeud::connecter
* Description	: methode pour connecter deux noeud entre eux
				  on verifie si la connexion est compatible puis on regarde s'il reste des ports disponibles
* Paramètres	: (Noeud*) noeud : noeud qu'on veut connecter au noeud courant
* Retour		: (bool): true = reussit / false = echec
****************************************************************************/
bool Noeud::connecter(Noeud* noeud){
	if (connexionCompatible(noeud) && noeud->connexionCompatible(this))
	{
		if (getNbPortDispo() > 0 && noeud->getNbPortDispo() > 0)
		{
			ajouterConnexion(noeud, true);
			noeud->ajouterConnexion(this, true);
			return true;
		}

		else if (reseauSansFil && noeud->reseauSansFil)
		{
			ajouterConnexion(noeud, false);
			noeud->ajouterConnexion(this, false);
			return true;
		}
		else
			cout << "aucun port disponible ou reseau sans fil non-disponible" << endl;
	}
	else
		cout << " : connexions incompatibles entre les deux appareils" << endl;
	return false;
	
}

/****************************************************************************
* Fonction		: Noeud::ajouterConnexion
* Description	: methode pour ajouter le noeud dans le tableau de connexion correspondant
* Paramètres	: (Noeud*) noeud : noeud qu'on veut ajouter au vecteur de noeud correspondant
				  (bool) lienFilaire : le type de lien filaire ou sans-fil
* Retour		: aucun
****************************************************************************/
void Noeud::ajouterConnexion(Noeud* noeud, bool lienFilaire){
	if (lienFilaire)
		connexionsFil.push_back(noeud);
	else
		connexionsSansFil.push_back(noeud);
}

/****************************************************************************
* Fonction		: Noeud::deconnecter
* Description	: methode pour deconnecter deux noeud
* Paramètres	: (Noeud*) noeud : noeud qu'on veut deconnecter au noeud courant
* Retour		: aucun
****************************************************************************/
void Noeud::deconnecter(Noeud* noeud){
	bool trouve = false;
	vector<Noeud*>::iterator it;
	if (capaciteEthernet > 0 && noeud->capaciteEthernet > 0)
	{ 
		it = find(connexionsFil.begin(), connexionsFil.end(), noeud);
		//si on trouve on retire la connexion filaire
		if (it != connexionsFil.end()){
			trouve = true;
			retirerConnexion(noeud, true);
			noeud->retirerConnexion(this, true);
		}
	}

	if (reseauSansFil && noeud->reseauSansFil)
	{
		it = find(connexionsSansFil.begin(), connexionsSansFil.end(), noeud);
		//si on trouve on retire la connexion sans-fil
		if (it != connexionsSansFil.end()){
			trouve = true;
			retirerConnexion(noeud, false);
			noeud->retirerConnexion(this, false);
		}
	}

	if (!trouve)
		cout << "Desole, la connexion demandee n'existe pas!" << endl;

}

/****************************************************************************
* Fonction		: Noeud::retirerConnexion
* Description	: methode pour retirer le noeud dans le tableau de connexion correspondant
* Paramètres	: (Noeud*) noeud : noeud qu'on veut retirer
				  (bool) lienFilaire : le type de lien : true = filaire ou false = sans-fil
* Retour		: aucun
****************************************************************************/
void Noeud::retirerConnexion(Noeud* noeud, bool lienFilaire){
	vector<Noeud*>::iterator it;
	if (lienFilaire)
	{
		it = find(connexionsFil.begin(), connexionsFil.end(), noeud);
		connexionsFil.erase(it);
	}
	else 
	{
		it = find(connexionsSansFil.begin(), connexionsSansFil.end(), noeud);
		connexionsSansFil.erase(it);
	}
	
}

/****************************************************************************
* Fonction		: operator<<
* Description	: Surcharge operateur <<
* Paramètres	: (ostream) &os : permet d'afficher en cascade
*				  (Noeud) &noeud : le noeud qui sera cout en cascade
* Retour		: aucun
****************************************************************************/
ostream& operator<<(ostream& os, const Noeud& noeud)
{
	os << "Id : " << noeud.id << endl << "Type : " << noeud.getNomType() << endl << "Nom : " << noeud.nom << endl << endl;
	
	os << "connexions filaire de " << noeud.nom << ": " << endl;
	if (noeud.connexionsFil.size() == 0)
		cout << "  Aucune connexion filaire" << endl;
	for (unsigned int i = 0; i < noeud.connexionsFil.size(); i++)
		os << "  " << i + 1 << "- " << "Id : " << noeud.connexionsFil[i]->id << " Type : " << noeud.connexionsFil[i]->getNomType() << " Nom : " << noeud.connexionsFil[i]->nom << endl;
	os << endl;

	os << "connexions sans fil " << noeud.nom << ": " << endl;
	if (noeud.connexionsSansFil.size() == 0)
		cout << "  Aucune connexion sans fil" << endl;
	for (unsigned int i = 0; i < noeud.connexionsSansFil.size(); i++)
		os << "  " << i + 1 << "- " << "Id : " << noeud.connexionsSansFil[i]->id << " Type : " << noeud.connexionsSansFil[i]->getNomType() << " Nom : " << noeud.connexionsSansFil[i]->nom << endl;
	os << endl;
	cout << "======================================================";

	return os;
}