/****************************************************************************
* Fichier       : Noeud.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 19 f�vrier 2015
* Mise � jour   : 5 mars 2015
* Description   : Implementation de la classe Noeud
****************************************************************************/
#include <string.h>
#include <algorithm>
#include <exception>
#include "headers/Noeud.h"
using namespace std;

/****************************************************************************
* Fonction		: Noeud::Noeud
* Description	: Constructeur par defaut
* Param�tres	: aucun
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
* Description	: Constructeur par param�tre
* Param�tres	: (int) pId : le id du noeud
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
}

//Destructeur
Noeud::~Noeud(){
	for(Noeud* noeud : connexionsFil){
		deconnecter(noeud);
	}

	for (Noeud* noeud : connexionsSansFil){
		deconnecter(noeud);
	}
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
const char* Noeud::getNomType() const
{
	const char* typeStr[] = { "NOEUD", "ROUTEUR", "COMMUTATEUR", "SERVEUR", "PC", "LAPTOP", "TABLETTE", "IMPRIMANTE", "ORDINATEUR" };
	return typeStr[numType];
}

//Accesseur
unsigned int Noeud::getNbPortDispo() const {
	return capaciteEthernet - connexionsFil.size();
}

/****************************************************************************
* Fonction		: Noeud::connecter
* Description	: methode pour connecter deux noeud entre eux
* Param�tres	: (Noeud*) noeud : noeud qu'on veut connecter au noeud courant
* Retour		: aucun
****************************************************************************/
void Noeud::connecter(Noeud& noeud){
	if (getNbPortDispo() > 0)
	{
		ajouterConnexion(noeud, true); 
		noeud->ajouterConnexion(this, true);
	}

	else if (reseauSansFil && noeud->reseauSansFil)
	{
		ajouterConnexion(noeud, false);
		noeud->ajouterConnexion(this, false);
	}
	
}

/****************************************************************************
* Fonction		: Noeud::ajouterConnexion
* Description	: methode pour ajouter le noeud dans le tableau de connexion correspondant
* Param�tres	: (Noeud*) noeud : noeud qu'on veut ajouter au vecteur de noeud correspondant
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
* Param�tres	: (Noeud*) noeud : noeud qu'on veut deconnecter au noeud courant
* Retour		: aucun
****************************************************************************/
void Noeud::deconnecter(Noeud* noeud){
	vector<Noeud*>::iterator it;
	if (capaciteEthernet > 0 && noeud->capaciteEthernet > 0)
	{ 
		it = find(connexionsFil.begin(), connexionsFil.end(), noeud);
		//si on trouve on retire la connexion filaire
		if (it != connexionsFil.end()){
			retirerConnexion(noeud, true);
			noeud->retirerConnexion(this, true);
		}
	}

	if (reseauSansFil && noeud->reseauSansFil)
	{
		it = find(connexionsSansFil.begin(), connexionsSansFil.end(), noeud);
		//si on trouve on retire la connexion sans-fil
		if (it != connexionsSansFil.end()){
			retirerConnexion(noeud, false);
			noeud->retirerConnexion(this, false);
		}
	}

}

/****************************************************************************
* Fonction		: Noeud::retirerConnexion
* Description	: methode pour retirer le noeud dans le tableau de connexion correspondant
* Param�tres	: (Noeud*) noeud : noeud qu'on veut retirer
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
* Param�tres	: (ostream) &os : permet d'afficher en cascade
*				  (Noeud) &noeud : le noeud qui sera cout en cascade
* Retour		: aucun
****************************************************************************/
ostream& operator<<(ostream& os, const Noeud& noeud)
{
	os << "Id : " << noeud.id << " Type : " << noeud.getNomType() << " Nom : " << noeud.nom << endl;
	
	os << "connexions filaire: " << endl;
	for (unsigned int i = 0; i < noeud.connexionsFil.size(); i++)
		os << "  " << i + 1 << "- " << "Id : " << noeud.connexionsFil[i]->id << " Type : " << noeud.connexionsFil[i]->getNomType() << " Nom : " << noeud.connexionsFil[i]->nom << endl;
	os << endl;

	os << "connexions sans fil: " << endl;
	for (unsigned int i = 0; i < noeud.connexionsSansFil.size(); i++)
		os << "  " << i + 1 << "- " << "Id : " << noeud.connexionsSansFil[i]->id << " Type : " << noeud.connexionsSansFil[i]->getNomType() << " Nom : " << noeud.connexionsSansFil[i]->nom << endl;
	os << endl;

	return os;
}