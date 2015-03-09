/****************************************************************************
* Fichier       : Reseau.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 février 2015
* Mise à jour   : 09 mars 2015
* Description   : Implementation de la classe Reseau
****************************************************************************/

#include "headers/Reseau.h"
#include <limits>

/****************************************************************************
* Fonction		: Reseau::Reseau
* Description	: Constructeur par defaut
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
Reseau::Reseau()
	: coutFil(0), coutSansFil(0) , matriceUpdated(false), coutsUpdated(false) {
}

/****************************************************************************
* Fonction		: Reseau::Reseau
* Description	: Constructeur par paramètre
* Paramètres	: (unsigned int) pCoutFil : le cout des connexions filaire
				  (unsigned int) pCoutSansFil : le cout des connexions sans fil
* Retour		: aucun
****************************************************************************/
Reseau::Reseau(unsigned int pCoutFil, unsigned int pCoutSansFil)
	: coutFil(pCoutFil), coutSansFil(pCoutSansFil), matriceUpdated(false), coutsUpdated(false) {
}

/****************************************************************************
* Fonction		: Reseau::~Reseau
* Description	: Destructeur du reseau qui detruit les noeuds
* Paramètres	: auncun
* Retour		: aucun
****************************************************************************/
Reseau::~Reseau(){
	for (map<unsigned int, Noeud*>::iterator it = noeuds.begin();
		it != noeuds.end();)
	{
		delete it->second;
		it = noeuds.erase(it);
	}
	/*
	for(map<unsigned int, Noeud*>::reverse_iterator rit = noeuds.rbegin();
		rit != noeuds.rend();
		++rit)
	{
		// Destructeur de Noeud
		delete rit->second;
		// Retirer l'élément de la map (par clé, car reverse_iterator ne marche pas)
    	noeuds.erase(rit->first);
	}*/
}

/****************************************************************************
* Requis fonctionnel 1
* Fonction		: Reseau::implanter
* Description   : permet d'implanter le reseau à l'aide de fichiers texte
* Paramètres    : aucun
* Retour        : aucun
****************************************************************************/
void Reseau::implanter(){
	// Lire reseau.txt et établir connexions
	ifstream fichier("reseau.txt");
	if (fichier)
	{
		string input, token;
		vector<string> relation;
		unsigned int id1, id2;

		while (!fichier.eof())
		{
			relation.clear();
			getline(fichier, input);
			istringstream ss(input);
			while (getline(ss, token, '-'))
				relation.push_back(token);

			//Conversion des string en bons types
			id1 = atoi(relation[0].c_str());
			id2 = atoi(relation[1].c_str());
			
			// Connecter
			map<unsigned int, Noeud*>::iterator it1 = noeuds.find(id1);
			map<unsigned int, Noeud*>::iterator it2 = noeuds.find(id2);
			if (it1 != noeuds.end() && it2 != noeuds.end() && it1 != it2){
				(it1->second)->connecter(it2->second);
			}
			else
				cout << "Id introuvable" << endl;
		}
		matriceGen();
	}
	else
		cout << "Impossible d'ouvrir le fichier" << endl;
}

/****************************************************************************
* Requis fonctionnel 2
* Fonction		: Reseau::afficher
* Description   : permet d'afficher la topologie du reseau
* Paramètres    : aucun
* Retour        : aucun
****************************************************************************/
void Reseau::afficher() const{
	for (pair<const unsigned int, Noeud*> n : noeuds)
		cout << *(n.second) << endl;
}

/****************************************************************************
* Requis fonctionnel 2
* Fonction		: Reseau::afficher
* Description   : permet d'afficher un noeud par id
* Paramètres    : (unsigned int) id : le id du noeud qu'on veut afficher
* Retour        : aucun
****************************************************************************/
void Reseau::afficher(unsigned int id) const{
	map<unsigned int, Noeud*>::const_iterator it = noeuds.find(id);
	cout << *(it->second) << endl;
}

/****************************************************************************
* Fonction		: Reseau::ajouter
* Description   : permet d'ajouter un noeud au réseau sans faire de connexions
* Paramètres    : (Noeud*) noeud : le noeud a ajouter au map
* Retour        : aucun
****************************************************************************/
void Reseau::ajouter(Noeud* noeud){
	noeuds.insert(pair<unsigned int, Noeud*>(noeud->getId(), noeud));
	matriceUpdated = false;
}

/****************************************************************************
* Requis fonctionnel 4
* Fonction		: Reseau::ajouterConnecter
* Description   : permet d'ajouter un noeud au réseau et de le connecter avec un autre noeud
* Paramètres    : (Noeud*) noeudAjoute : le noeud a ajouter au map
				: (unsigned int) idConnecteur : le id du noeud  sur lequel on veut connecter
* Retour        : aucun
****************************************************************************/
void Reseau::ajouterConnecter(Noeud* noeudAjoute, unsigned int idConnecteur) {
	map<unsigned int, Noeud*>::iterator it = noeuds.find(idConnecteur);
	if (it != noeuds.end())
	{
		if (noeudAjoute->connecter(it->second))
			noeuds.insert(pair<unsigned int, Noeud*>(noeudAjoute->getId(), noeudAjoute));
	}
	else
		cout << "Id introuvable" << endl;
	
	matriceUpdated = false;
}


/****************************************************************************
* Requis fonctionnel 5
* Fonction		: Reseau::retirer
* Description   : permet de retirer un noeud du réseau ainsi que toute ces connexions
                  Seulement valide sur un PC, Laptop, tablette ou imprimante
* Paramètres    : (unsigned int) id : le id du noeud a retirer
* Retour        : aucun
****************************************************************************/
void Reseau::retirer(unsigned int id){
	map<unsigned int, Noeud*>::iterator it = noeuds.find(id);

	if ((it != noeuds.end()) && (it->second->getNumType() == 4 || it->second->getNumType() == 5 || it->second->getNumType() == 6 || it->second->getNumType() == 7))
	{
		delete it->second;	//appel du destructeur de noeud qui s'assure de supprimer toutes les connexions reliées au noeud
		noeuds.erase(id);
		matriceUpdated = false;
	}
	else
		cout << "Desoler vous ne pouvez pas retirer un commutateur, un routeur ou un serveur" << endl;
}

/****************************************************************************
* Requis fonctionnel 6
* Fonction		: Reseau::remplacer
* Description   : permet de remplacer un noeud du réseau par un autre noeud
* Paramètres    : (unsigned int) ancienId : l'ancien id du noeud a remplacer
				  (Noeud*) nouveauNoeud : le nouveau noeud
* Retour        : aucun
****************************************************************************/
void Reseau::remplacer(unsigned int ancienId, Noeud* nouveauNoeud){
	map<unsigned int, Noeud*>::iterator it = noeuds.find(ancienId);

	//si existe et si routeur ou commutateur
	if ((it != noeuds.end()) && (it->second->getNumType() == 1 || it->second->getNumType() == 2) && (nouveauNoeud->getNumType() == 1 || nouveauNoeud->getNumType() == 2))
	{
		if (nouveauNoeud->getCapacite() > it->second->getCapacite()) // capacite superieur
		{
			if (it->second->getReseauSansfil() && !nouveauNoeud->getReseauSansfil()) //carte sans fil = nouveau noeud avec carte sans fil
				cout << "Impossible, le nouvel appareil n'a pas de carte reseau" << endl;
			else
			{
				vector<Noeud*> tempFil = it->second->getConnexionsFil();
				vector<Noeud*> tempSansFil = it->second->getConnexionsSansFil();
				//retirer(ancienId); peut pas a cause que c'est un routeur
				delete it->second;	//appel du destructeur de noeud qui s'assure de supprimer toutes les connexions reliées au noeud
				noeuds.erase(ancienId);
				matriceUpdated = false;

				for (unsigned int i = 0; i < tempFil.size(); i++)
					nouveauNoeud->connecter(tempFil[i]);

				for (unsigned int i = 0; i < tempSansFil.size(); i++)
					nouveauNoeud->connecter(tempSansFil[i]);
	
			}
		}
		else
			cout << "Remplacement impossible : la capacite doit etre superieur" << endl;
	}
	else
		cout << "Desoler, vous pouvez seulement remplacer un commutateur ou un routeur" << endl;
}

/****************************************************************************
* Requis fonctionnel 7
* Fonction		: Reseau::distance
* Description   : permet d'obtenir la distance la plus courte entre deux noeuds du reseau
				  en utilisant l'algorithme de Floyd-Warshall
* Paramètres    : (unsigned int) n1 : le id du premier noeud
				  (unsigned int) n2 : le id du deuxieme noeud
* Retour        : (unsigned int) la distance minimal
****************************************************************************/
unsigned int Reseau::distance(unsigned int n1, unsigned int n2) {
	map<unsigned int, Noeud*>::iterator it1 = noeuds.find(n1);
	map<unsigned int, Noeud*>::iterator it2 = noeuds.find(n2);
	if(it1 != noeuds.end() && it2 != noeuds.end() && it1 != it2){
		if(!matriceUpdated)
			matriceGen();
		if(!coutsUpdated)
			floyd();
		unsigned int i = 0;
		unsigned int j = 0;
		// obtenir la position dans la matrice
		while(header[i] != n1){
			i++;
		}
		while(header[j] != n2){
			j++;
		}
		return couts[i][j];
	}
	return 0;
}

/****************************************************************************
* Requis fonctionnel 7
* Fonction		: Reseau::floyd
* Description   : l'algorithme de Floyd-Warshall
* Paramètres    : aucun
* Retour        : aucun
****************************************************************************/
void Reseau::floyd() {
	couts = matrice;
	for(unsigned int i = 0; i < couts.size(); i++){
		for(unsigned int j = 0; j < couts.size(); j++){
			for(unsigned int k = 0; k < couts.size(); k++){
				if(couts[j][k] > couts[i][j] + couts[i][k]){
					couts[j][k] = couts[i][j] + couts[i][k];
					couts[k][j] = couts[i][j] + couts[i][k];
				}
			}
		}
	}
	coutsUpdated = true;
}

/****************************************************************************
* Requis fonctionnel 7
* Fonction		: Reseau::matriceGen
* Description   : Permet de construire nos matrices pour faciliter les calculs
* Paramètres    : aucun
* Retour        : aucun
****************************************************************************/
void Reseau::matriceGen(){
	// Construire la matrice et initialiser à l'infini
	matrice.reserve(noeuds.size());
	header.reserve(noeuds.size());
	for(unsigned int i = 0; i < noeuds.size(); i++){
		vector<unsigned int> temp;
		temp.reserve(noeuds.size());
		for(unsigned int j = 0; j < noeuds.size(); j++){
			temp.push_back(numeric_limits<unsigned int>::max());
		}
		matrice.push_back(temp);
		header.push_back(0);
	}

	// Initialiser le header
	unsigned int i = 0;
	for(pair<unsigned int, Noeud*> paire : noeuds){
		header[i] = paire.first;
		i++;
	}

	// Réinitialiser la diagonale
	for(i = 0; i < matrice.size(); i++){
		matrice[i][i] = 0;
	}

	// Coûts

	// Pour chaque noeud A du réseau
	for(pair<unsigned int, Noeud*> paire : noeuds){
		// FIL
		unsigned int indexA = 0;
		unsigned int i = matrice.size();
		// obtenir la position dans la matrice
		while(header[indexA] != paire.first){
				indexA++;
		}
		vector<Noeud*> connections = paire.second->getConnexionsFil();
		// trouver ses noeuds B connectés
		if(connections.size() > 0){
			for(Noeud* noeud : connections){
				// obtenir le ID de son noeud B
				i = noeud->getId();
				unsigned int indexB = 0;
				// obtenir la position dans la matrice
				while(header[indexB] != i){
					indexB++;
				}
				// poser le coût [A][B]
				matrice[indexA][indexB] = coutFil;
				matrice[indexB][indexA] = coutFil;
			}
		}
		// SANS-FIL
		indexA = 0;
		// obtenir la position dans la matrice
			while(header[indexA] != paire.first){
				indexA++;
			}
		connections = paire.second->getConnexionsSansFil();
		// trouver ses noeuds B connectés
		if(connections.size() > 0){
			for(Noeud* noeud : connections){
				// obtenir le ID de son noeud B
				i = noeud->getId();
				unsigned int indexB = 0;
				// obtenir la position dans la matrice
				while(header[indexB] != i){
					indexB++;
				}
				// poser le coût [A][B]
				matrice[indexA][indexB] = coutSansFil;
				matrice[indexB][indexA] = coutSansFil;
			}
		}
	}

	/* La matrice prend alors la forme

	  - 111 112 113 211 311 312
	111   0   1   -   2   -   -
	112   1   0   -   -   -   1
	113   -   -   0   2   -   -
	211   2   -   2   0   -   1
	311   -   -   -   -   0   -
	312   -   1   -   1   -   0

	*/

	matriceUpdated = true;
}