/****************************************************************************
* Fichier       : Automate.cpp
* Auteur        : Jules Favreau-Pollender, Francis Rochon, Samuel Rondeau
* Date          : 26 mars 2015
* Mise à jour   : 26 mars 2015
* Description   : Implementation de la classe Automate
****************************************************************************/

#include "headers/Automate.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

/****************************************************************************
* Fonction		: Automate::Automate
* Description	: Constructeur par defaut
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
Automate::Automate() {
	nbEtats = 0;
	type = FINI;
}

/****************************************************************************
* Tache #3
* Fonction		: Automate::Automate
* Description	: Constructeur par parametre
* Parametre	    : (string) fichier : fichier descriptif pour creer un automate
* Retour		: aucun
****************************************************************************/
Automate::Automate(string fichier) {
	ifstream lecture(fichier);
	if(lecture) {
		string input;
		getline(lecture, input);
		if(input.substr(0, input.find(" ") ) == "Fini")
			type = Automate::FINI;
		else if(input.substr(0, input.find(" ") ) == "Moore")
			type = Automate::MOORE;
		else if(input.substr(0, input.find(" ") ) == "Mealy")
			type = Automate::MEALY;
		else {
			cerr << "Fichier non conforme" << endl;
			lecture.close();
			return;
		}

		// try catch numberformatexception
		nbEtats = atoi(input.substr(input.find(" ") + 1).c_str());

		// Creation des etats et leurs attributs et transitions
		while (!lecture.eof()) {
			getline(lecture, input);
			buildAutomate(input);
		}
		lecture.close();
	}
	else {
		cerr << "Fichier introuvable" << endl;
	}
}

void Automate::buildBase(string input) {
	Etat tampon;
	// Si I, creer Etat et mettre initial
	if (input.at(0) == 'I') {
		// DEBUG
		cout << "Initial state detected" << endl;
		// Si aussi T, mettre aussi terminal
		if (input.at(2) == 'T') {
			// DEBUG
			cout << "Terminal state detected" << endl;
			string s = &input.at(4);
			s = s.substr(0, 1);
			tampon = Etat(atoi(s.c_str()));
			tampon.setInitiale(true);
			tampon.setFinal(true);
			ListeEtats.push_back(tampon);
		}
		// Etat initial
		else {
			string s0 = &input.at(2);
			s0 = s0.substr(0, 1);
			tampon = Etat(atoi(s0.c_str()));
			tampon.setInitiale(true);
			ListeEtats.push_back(tampon);
		}
	}
	// Sinon, si T, creer Etat et mettre terminal
	else if (input.at(0) == 'T') {
		// DEBUG
		cout << "Terminal state detected" << endl;
		string s1 = &input.at(2);
		s1 = s1.substr(0, 1);
		tampon = Etat(atoi(s1.c_str()));
		tampon.setFinal(true);
		ListeEtats.push_back(tampon);
	}
}

void Automate::buildAutomate(string input) {
	// Si I ou T, cas spéciaux communs
	if (input.at(0) == 'I' || input.at(0) == 'T') {
		buildBase(input);
	}
	// Sinon, transition
	else {
		// DEBUG
		cout << "Transition detected" << endl;

		// Si Etat A n'existe pas, creer Etat A
		string valA = input.substr(0, 1);
		//trouvons si l'etat A existe
		Etat tamponA = Etat(atoi(valA.c_str()));
		list<Etat>::iterator itEtatA = find(ListeEtats.begin(), ListeEtats.end(), tamponA);
		Etat* a;
		if (itEtatA != ListeEtats.end())
			a = &(*itEtatA);
		//on ajoute l'etat A
		else
		{
			a = &tamponA;
			ListeEtats.push_back(*a);
		}

		// Si Etat B n'existe pas, creer Etat B
		string valB = input.substr(input.length() - 1);
		//trouvons si l'etat B existe
		Etat tamponB = Etat(atoi(valB.c_str()));
		list<Etat>::iterator itEtatB = find(ListeEtats.begin(), ListeEtats.end(), tamponB);
		Etat* b;
		if (itEtatB != ListeEtats.end())
			b = &(*itEtatB);
		//on ajoute l'etat B
		else 
		{
			b = &tamponB;
			ListeEtats.push_back(*b);
		}		

		//Etablir la transition selon le type d'automate
		string etiquette = input.substr(2, input.length() - 4);
		string entre = etiquette.substr(0, 1);
		if (type == FINI)
			a->ajouterTransition(Transition::FINI, entre, b, "");
		else if (type == MOORE) // sortie sur l'etat
		{
			if (etiquette.length() > 1)
				a->setSortie(etiquette.substr(2));//la sortie sur l'etat
			a->ajouterTransition(Transition::MOORE, entre, b, "");
		}
		else if (type == MEALY) // la sortie sur la transition
			a->ajouterTransition(Transition::MEALY, entre, b, etiquette.substr(2));
	}
}

/****************************************************************************
* Fonction		: Automate::~Automate
* Description	: Destructeur
* Paramètres	: aucun
* Retour		: aucun
****************************************************************************/
Automate::~Automate() {
	//detruit toutes les transition puis les etats
}

/****************************************************************************
* Fonction		: Automate::etatInitial
* Description	: Retourne l'etat initial de l'automate
* Parametre	    : aucun
* Retour		: (Etat) etat initial
****************************************************************************/
string Automate::getType() {
	if (type == 0)
		return "Fini";
	else if (type == 1)
		return "Moore";
	else if (type == 2)
		return "Mealy";
	else return "";
}
/****************************************************************************
* Tache #6
* Fonction		: Automate::etatInitial
* Description	: Retourne l'etat initial de l'automate
* Parametre	    : aucun
* Retour		: (Etat) etat initial
****************************************************************************/
Etat Automate::etatInitial() {
	//parcours la liste d'états 
	list<Etat>::iterator itEtats = ListeEtats.begin();
	while(itEtats != ListeEtats.end())
	{
		//l'etat est initial?
		if(itEtats->getEstEtatInitial() == true)
			return *itEtats;
		itEtats++;
	}
	cerr << "Il n'y a pas d'etat initial. Machine a Etats invalide" << endl;
	return 0;
}

/****************************************************************************
* Fonction		: Automate::etatFinal
* Description	: Retourne l'etat final de l'automate
* Parametre	    : aucun
* Retour		: (int) id de l'etat final
****************************************************************************/
int Automate::getNumEtatFinal() {
	//parcours la liste d'états 
	list<Etat>::iterator itEtats = ListeEtats.begin();
	while (itEtats != ListeEtats.end())
	{
		//l'etat est final?
		if (itEtats->getEstEtatFinal() == true)
			return itEtats->getNumEtat();
		itEtats++;
	}
	cerr << "Il n'y a pas d'etat final." << endl;
	return -1;
}

/****************************************************************************
* Tache #7
* Fonction		: Automate::ajouterEtat
* Description	: Ajoute un nouvel etat a l'automate
* Parametre	    : (Etat) e : etat a ajouter
* Retour		: aucun
****************************************************************************/
void Automate::ajouterEtat(Etat e) {

}

/****************************************************************************
* Tache #9
* Fonction		: Automate::genererFichierAutomate
* Description	: Genere un fichier descriptif de l'automate utilisable dans
                  son constructeur par parametre
* Parametre	    : (string) fichier : fichier de sortie a enregistrer
* Retour		: aucun
****************************************************************************/
void Automate::genererFichierAutomate(string fichier) {
	string init = "-1";
	string fin = "-1";
	ofstream ecriture(fichier, ios::out | ios::trunc);
	if (ecriture)
	{
		init = to_string(etatInitial().getNumEtat());
		fin = to_string(getNumEtatFinal());

		//ligne 0
		ecriture << getType() << " " << nbEtats << endl;

		//ligne 1 ou 1-2
		if (fin == "-1")
			ecriture << "I " << init << endl;
		else if (init == fin)
			ecriture << "I T " << init << endl;
		else
		{
			ecriture << "I " << init << endl;
			ecriture << "T " << fin << endl;
		}

		//lignes des transitions
		list<Etat>::iterator itEtats = ListeEtats.begin();
		list<Transition>::iterator itTrans;
		for (; itEtats != ListeEtats.end(); itEtats++)
		{
			list<Transition> listTransTemp = itEtats->getListTransition();
			for (itTrans = listTransTemp.begin(); itTrans != listTransTemp.end(); itTrans++)
			{
				if (type == FINI)
					ecriture << itTrans->getEtatDepart() << " " << itTrans->getEntre() << " " << itTrans->getEtatDestination() << endl;
				else if (type == MOORE) // sortie sur l'etat
				{
					ecriture << itTrans->getEtatDepart() << " " << itTrans->getEntre() << " " << itEtats->getSortie() << " " << itTrans->getEtatDestination() << endl;
				}
				else if (type == MEALY) // sortie sur la transition
					ecriture << itTrans->getEtatDepart() << " " << itTrans->getEntre() << " " << itTrans->getSortie() << " " << itTrans->getEtatDestination() << endl;
			}
		}
		ecriture.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}

/****************************************************************************
* Requis #1
* Fonction		: Automate::estDeterministe
* Description	: Determine si l'automate est deterministe si pour chaque
                  etat une seule transition est associee a chaque symbole
* Parametre	    : aucun
* Retour		: (bool) true = deterministe / false = non deterministe
****************************************************************************/
bool Automate::estDeterministe() {
	list<Etat>::iterator itEtat = ListeEtats.begin();
	
	//parcours chaque etat
	for (; itEtat != ListeEtats.end(); itEtat++)
	{
		//cout << itEtat->getNumEtat();
		//liste des symboles
		list<string> listSymb = itEtat->listerEtiquettesTransitions();

		//trouver si unique
		list<string> listTemp = listSymb;
		listTemp.unique();

		//si non unique
		if (listTemp.size() != listSymb.size())
			return false;
	}
	return true;
}

/****************************************************************************
* Requis #2
* Fonction		: Automate::estReactif
* Description	: Determine si la sortie de l'automate est une fonction si
                  chaque etat possede une sortie par entree
* Parametre	    : aucun
* Retour		: (bool) true = reactif / false = non reactif
****************************************************************************/
bool Automate::estReactif() {
	
	//boolean pour savoir si est reactif
	bool estReactif = false;
	//Pour chaque etat
	list<Etat>::iterator itEtats = ListeEtats.begin();

	while(itEtats != ListeEtats.end())
	{	
		//la liste des transitions et un iterator sur celle-ci
		list<Transition> ListeTransition = itEtats->getListTransition();
		list<Transition>::iterator itTransition = ListeTransition.begin();
	
		//initialisations necessaires
		string sortie0 = "", sortie1 = "", entree = "";
		bool premiereSortiePour0 = true;
		bool premiereSortiePour1 = true;
		int IDetat = 0;
		auto EtatResultant = ListeEtats.begin();

		if(Automate::type == MEALY)
		{
			premiereSortiePour0 = true;
			premiereSortiePour1 = true;
			//pour chaque transition il y a exactement une sortie associe
			for(; itTransition != ListeTransition.end(); itTransition++)
			{
				entree = itTransition->getEntre();
				if(entree == "0")
				{
					//sortie de la premiere transition de l'etat compare avec l'autre sortie pour la meme entree
					if(premiereSortiePour0 == true)
					{
						sortie0 = itTransition->getSortie();
						premiereSortiePour0 = false;
					}
					else
					{
						//si la sortie est pas la meme alors on retourne false
						if(itTransition->getSortie() != sortie0)
							return false;
					}
				}

				if(entree == "1")
				{
				//sortie de la premiere transition de l'etat compare avec l'autre sortie pour la meme entree
					if(premiereSortiePour1 == true)
					{
						sortie1 = itTransition->getSortie();
						premiereSortiePour1 = false;
					}
					else
					{
						//si la sortie est pas la meme alors on retourne false
						if(itTransition->getSortie() != sortie1)
							return false;
					}
				}
			}
		}
		
		else if(Automate::type == MOORE)
		{
			premiereSortiePour0 = true;
			premiereSortiePour1 = true;

			//pour chaque transition il y a exactement une sortie associe
			for(; itTransition != ListeTransition.end(); itTransition++)
			{
				entree = itTransition->getEntre();
				if(entree == "0")
				{
					//va chercher la sortie de chacun des etat pointer par l'etat courant
					IDetat = itTransition->getEtatDestination();
					EtatResultant = ListeEtats.begin();
					advance(EtatResultant, IDetat);
					//sortie de la premiere transition de l'etat compare avec l'autre sortie pour la meme entree
					if(premiereSortiePour0 == true)
					{
						//sortie pour chaque etat de destination
						sortie0 = EtatResultant->getSortie();
						premiereSortiePour0 = false;
					}
					else
					{
						//si la sortie est pas la meme alors on retourne false
						if(EtatResultant->getSortie() != sortie0)
							return false;
					}
				}

				if(entree == "1")
				{
					//va chercher la sortie de chacun des etat pointer par l'etat courant
					IDetat = itTransition->getEtatDestination();
					EtatResultant = ListeEtats.begin();
					advance(EtatResultant, IDetat);
					//sortie de la premiere transition de l'etat compare avec l'autre sortie pour la meme entree
					if(premiereSortiePour1 == true)
					{
						//sortie pour chaque etat de destination
						sortie1 = EtatResultant->getSortie();
						premiereSortiePour1 = false;
					}
					else
					{
						//si la sortie est pas la meme alors on retourne false
						if(EtatResultant->getSortie() != sortie1)
							return false;
					}
				}
			}
		}
		else if(Automate::type == FINI)
			return false;

		itEtats++;
	}
	return true;
}

/****************************************************************************
* Requis #3
* Fonction		: Automate::minimiserMealy
* Description	: Minimise l'automate de Mealy associe
* Parametre	    : aucun
* Retour		: (Automate) automate de Mealy minimise equivalent
****************************************************************************/
Automate Automate::minimiserMealy() {

	//Matrice d'équivalence des chemins comme vue en cours
	vector< vector<bool> > matriceSnPlus1;
	matriceSnPlus1.reserve(nbEtats);

	//Initialisation : on met toutes les cases a true
	for (unsigned int i = 0; i < nbEtats; i++){
		vector<bool> temp;
		temp.reserve(nbEtats);
		for (unsigned int j = 0; j < nbEtats; j++){
			temp.push_back(true);
		}
		matriceSnPlus1.push_back(temp);
	}

	vector< vector<bool> > matriceSn;
	do
	{
		matriceSn = matriceSnPlus1;

		//pour chaque ligne de Sn+1
		for (Etat etat : ListeEtats)
		{
			list<int> etatCible = etat.cible();
			//pour chaque colonne
			for (int e : etatCible)
			{
				//on met les états de destination a false
				//est-ce qu'il faut vérifier si les étiquettes sont identique???????????????????
				matriceSnPlus1[etat.getNumEtat()][e] = false;
			}
		}
	} while (matriceSnPlus1 != matriceSn);




	//déterminer les etats qui sont equivalent
	list<string> etatEq;
	for (unsigned int i = 0; i < nbEtats; i++){
		for (unsigned int j = 0; j < nbEtats; j++){
			if (i == j)/// on regarde ou pas????????????
			{}
			else
			{
				//on determine les etats équivalents
				if (matriceSnPlus1[i][j] == true)
				{
					// p-e a repenser----------------------------
					string egalite = (i < j) ? i + "=" + j : j + "=" + i;
					etatEq.push_back(egalite);//on identifie les etats equivalentes
				}
			}
		}
	}
	etatEq.unique();//enleve doublons


	//trouve l'etat initial
	char init = etatInitial().getNumEtat();

	//trouver les etat a enlever
	list<char> etat2Remove;
	char num = ' ';
	for (Etat e : ListeEtats)
	{
		num = e.getNumEtat();
		if (num != init)
		{
			//on parcourt les état equivalente
			for (string eq : etatEq)
			{
				if (num == eq.front() || num == eq.back())
				{
					etat2Remove.push_back(num);
				}
			}
		}
	}



	//petit test avec les fichiers
	//on genere le fichier et on récupere les données
	this->genererFichierAutomate("minimiser.txt");
	vector<string> lignesFichier;
	ifstream lecture("minimiser.txt");
	if (lecture) {
		string input;
		while (!lecture.eof()) {
			getline(lecture, input);
			lignesFichier.push_back(input);
		}
	}
	else {
		cerr << "Fichier non conforme" << endl;
		lecture.close();
	}

	//on réecrit le fichier minimise
	int nbEtMin = 0;
	ofstream fichier("minimiser.txt", ios::out | ios::trunc);
	if (fichier)
	{
		for (unsigned int i = 0; i < lignesFichier.size(); i++)
		{
			if (i == 0)
			{
				nbEtMin = nbEtats - etatEq.size();
			}
			else if (lignesFichier[i].at(0) == 'I')
			{ }
			else
			{
				//pour toute les etat d'equivalence
				//for (string eq : etatEq)
				//{
					char eDepart = lignesFichier[i].front();
					char eArrive = lignesFichier[i].back();
					//pour toutes les etats a enlever
					for (char e2r : etat2Remove)
					{
						if (eDepart == e2r)
						{
							lignesFichier[i].erase();///////////////iterator
						}
							
						if (eArrive == e2r)
						{
							//faire le remplacament dans le dernier terme de la transition------------
						}	
					}	
				//}
			}
		}

		fichier << "Mealy " << nbEtMin << endl;
		fichier << "I " << init << endl;
		for (unsigned int i = 2; i < lignesFichier.size(); i++)
		{
			fichier << lignesFichier[i] << endl;
		}
		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;

	/*
		//On crer l'automate minimise
		//list avec le nombre d'état minimal
		list<Etat> etatMinimise;
		for (unsigned int i = 0; i < nbEtats - etatEq.size(); i++)
		{
			etatMinimise.push_back(Etat());
		}

		list<Etat>::iterator it = ListeEtats.begin();
		list<Etat>::iterator itMin = etatMinimise.begin();
		for (; it != ListeEtats.end(); it++)
		{
			//On doit établir les transitions pr chaque état

			//il faut gerer etat init et final
			
			//si une transition demande une des états qui a été enlevé 
			//on doit lui dire d'allez voir l'état équivalent restant
			//on ajoute une par une les transition
			//(*itMin).ajouterTransition(Transition::MEALY, string c, Etat* destination, string sortie)
		}
		*/
		return Automate("minimiser.txt");
}



/****************************************************************************
* Requis #4
* Fonction		: Automate::calculerSortie
* Description	: Determine la chaine de sortie en fonction de la chaine
                  d'entree
* Parametre	    : (string) mot : chaine d'entree
* Retour		: (string) chaine de sortie
****************************************************************************/
string Automate::calculerSortie(string mot) {
	//trouver l'etat initial
	Etat etat = etatInitial();
	string sortie = "";

	//Pour chaque caractere du string d'entree (mot)
	for(unsigned int i = 0; i < mot.length(); ++i)
	{
		char entree = mot[i];
		//pour pouvoir recuperer les transitions d'un etat
		list<Transition> listTransitionsEtat = etat.getListTransition();
		list<Transition>::iterator itTransitions = listTransitionsEtat.begin();

		int IDetat = 0;
		auto EtatDest = ListeEtats.begin();

		//appliquer le caractere du mot à l'etat
		for(;itTransitions != listTransitionsEtat.end(); itTransitions++)
		{
			//prendre le string en entree et le convertir en char pour pouvoir comparer
			char c = itTransitions->getEntre()[0];
			//faire la bonne transition selon si c'est 1 ou 0
			if(c == entree)
			{
				//aller chercher le ID de l'etat dest 
				IDetat = itTransitions->getEtatDestination();
				EtatDest = ListeEtats.begin();
				//trouver cet etat et mettre a jour la variable etat
				advance(EtatDest, IDetat);

				if(Automate::type == MOORE)
				{
					//sortie pour etat de destination
					sortie += EtatDest->getSortie();
				}
				//aller chercher le ID de l'etat dest 
				etat = *EtatDest;
				//Prendre la sortie de cette transition, la mettre dans le string de sortie
				sortie += itTransitions->getSortie();
			}
		}
	}
	//enlever les espaces 
	sortie.erase(remove_if(sortie.begin(), sortie.end(), isspace), sortie.end());
	return sortie;
}

/****************************************************************************
* Requis #5
* Fonction		: Automate::convertisseurMoore2Mealy
* Description	: Convertit un automate de Moore en automate de Mealy
* Parametre	    : aucun
* Retour		: aucun
****************************************************************************/
void Automate::convertisseurMoore2Mealy() {
	if(type != Automate::MOORE)
	{
		cerr << "Type de conversion invalide" << endl;
		return;
	}

	for(Etat etat : ListeEtats)
	{
		etat.convertisseurMoore2Mealy();
		type = Automate::MEALY;
	}
}

/****************************************************************************
* Requis #6
* Fonction		: Automate::convertisseurMealy2Moore
* Description	: Convertit un automate de Mealy en automate de Moore
* Parametre	    : aucun
* Retour		: aucun
****************************************************************************/
void Automate::convertisseurMealy2Moore() {
	if(type != Automate::MEALY)
	{
		cerr << "Type de conversion invalide" << endl;
		return;
	}

	// Pour chaque état cible
	for(Etat cible : ListeEtats)
	{
		// Enregistrer toutes les transitions entrantes
		list<pair<Etat, Transition>> ListeTransitions;
		// Pour chaque état source
		for(Etat source : ListeEtats)
		{
			// Si une transition pointe vers la cible, enregistrer (avec la source)
			for(Transition transition : source.getListTransition())
			{
				if(transition.getEtatDestination() == cible.getNumEtat())
					ListeTransitions.push_back(make_pair(source, transition));
			}
		}

		// Vérifier si toutes les transitions entrantes sont de même sortie
		// Si oui, transférer les sorties
		// Sinon, créer autant d'états que de différentes sorties, puis modifier les transitions
	}
}
