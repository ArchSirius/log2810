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
		//cout << "Initial state detected" << endl;
		// Si aussi T, mettre aussi terminal
		if (input.at(2) == 'T') {
			// DEBUG
			//cout << "Terminal state detected" << endl;
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
		//cout << "Terminal state detected" << endl;
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
		//cout << "Transition detected" << endl;

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
			//pour etre capable de modifier a dans la liste
			itEtatA = find(ListeEtats.begin(), ListeEtats.end(), tamponA);
			a = &(*itEtatA);
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
string Automate::getType() const{
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
Etat Automate::etatInitial() const{
	//parcours la liste d'états 
	list<Etat>::const_iterator itEtats = ListeEtats.begin();
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
int Automate::getNumEtatFinal() const{
	//parcours la liste d'états 
	list<Etat>::const_iterator itEtats = ListeEtats.begin();
	while (itEtats != ListeEtats.end())
	{
		//l'etat est final?
		if (itEtats->getEstEtatFinal() == true)
			return itEtats->getNumEtat();
		itEtats++;
	}
	//cerr << "Il n'y a pas d'etat final." << endl;
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
	//list<Etat>::iterator itEtat = find(ListeEtats.begin(), ListeEtats.end(), e);
	//if (itEtat != ListeEtats.end())
	e.setNumEtat(ListeEtats.size());
	ListeEtats.push_back(e);
	//else
	//	cerr << "Impossible d'ajouter l'état";
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
		int numTrans;
		//pour chaques etats
		for (; itEtats != ListeEtats.end(); itEtats++)
		{
			numTrans = 0;
			list<Transition> listTransTemp = itEtats->getListTransition();
			//pour toutes les transitions partant de l'etat pointé par l'iterator
			for (itTrans = listTransTemp.begin(); itTrans != listTransTemp.end(); itTrans++)
			{
				if (type == FINI)
					ecriture << itTrans->getEtatDepart() << " " << itTrans->getEntre() << " " << itTrans->getEtatDestination() << endl;
				else if (type == MOORE) // sortie sur l'etat
				{
					if (numTrans++ == 0)	//premiere transition : on met la sortie de l'etat
						ecriture << itTrans->getEtatDepart() << " " << itTrans->getEntre() << " " << itEtats->getSortie() << " " << itTrans->getEtatDestination() << endl;
					else
						ecriture << itTrans->getEtatDepart() << " " << itTrans->getEntre() << " " << itTrans->getEtatDestination() << endl;
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
	if (type != MEALY)
	{
		cerr << "Veuillez convertir votre automate en machine de MEALY avant de la minimiser" << endl;
		return *this;
	}

	/*
	* déterminer les etats qui sont equivalents
	*/
	string init = to_string(etatInitial().getNumEtat()); // num de l'etat initial
	int i = 0; //num de l'etat courant
	int j = 0; //num de l'etat des autres etats
	list<string> etatEq;
	list<string>::iterator itEq;
	for (Etat etat : ListeEtats)
	{
		//pour chaque colonne
		i = etat.getNumEtat();
		for (Etat etat2 : ListeEtats)
		{
			j = etat2.getNumEtat();
			if (i == j)
			{}
			else if (etat.estEquivalent(etat2))
			{
				int i = etat.getNumEtat();
				int j = etat2.getNumEtat();
				string egalite;
				if (i < j)
					egalite = to_string(i) + "=" + to_string(j);
				else
					egalite = to_string(j) + "=" + to_string(i);

				//positionner etatEq de sorte que chaque ligne soit : "EtatAEnlever=EtatARemplacer", mais on veux conserver l'etat initial
				if (egalite.substr(0, egalite.find("=")) == init)
					egalite = egalite.substr(egalite.find("=") + 1, egalite.length()) + "=" + egalite.substr(0, egalite.find("="));
					
				//ne pas mettre les doublons
				itEq = etatEq.begin();
				if (find(etatEq.begin(), etatEq.end(), egalite) == etatEq.end())
					etatEq.push_back(egalite);//on identifie les etats equivalentes
			}
		}
	}

	/*
	* on genere le fichier et on récupere les données
	*/
	this->genererFichierAutomate("minimiser.txt");
	vector<string> lignesFichier;
	ifstream lecture("minimiser.txt");
	if (lecture) {
		string input;
		while (!lecture.eof()) {
			getline(lecture, input);
			if (input != "") //gestion des erreurs
				lignesFichier.push_back(input);
		}
	}
	else {
		cerr << "Fichier non conforme" << endl;
		lecture.close();
	}


	/*
	* on réecrit le fichier minimiser.txt
	*/
	int nbEtMin = 0;
	ofstream fichier("minimiser.txt", ios::out | ios::trunc);
	if (fichier)
	{
		vector<string>::iterator itLigne = lignesFichier.begin();
		//pour chaque ligne du fichier
		while (itLigne != lignesFichier.end())
		{
			if (itLigne == lignesFichier.begin())
			{
				nbEtMin = nbEtats - etatEq.size();
			}
			else if (itLigne->at(0) == 'I')
			{ }
			else
			{
				char eDepart = itLigne->front();
				char eArrive = itLigne->back();
			
				list<string>::iterator itEquivalence = etatEq.begin();
				//on parcourt la liste d'equivalence pour la ligne du fichier courante
				while (itEquivalence != etatEq.end() && itLigne != lignesFichier.end())
				{
					//on supprime les lignes du fichier qui commence par l'etat equivalent
					if (eDepart == itEquivalence->front())
					{
						itLigne = lignesFichier.erase(itLigne);
						if (itLigne != lignesFichier.end())
						{
							//on renitialise  les donnees puisqu'on change de ligne
							eDepart = itLigne->front();
							eArrive = itLigne->back();
							itEquivalence = etatEq.begin();//on recommencer puisqu'on change de ligne
						}
					}

					//faire le remplacament dans le dernier terme de la transition par l'etat equivalent
					else if (eArrive == itEquivalence->front())
					{
						*itLigne = itLigne->substr(0, itLigne->length() - 1) + itEquivalence->back();
						eArrive = itLigne->back();//on change l'etat d'arrive
					}
					else
						itEquivalence++;
				}	
			}

			//on passe a la prochaine ligne du fichier
			if (itLigne != lignesFichier.end())
				itLigne++;
		}

		//on remplit le fichier minimise.txt
		fichier << "Mealy " << nbEtMin << endl;
		for (unsigned int i = 1; i < lignesFichier.size() - 1 ; i++)
		{
			fichier << lignesFichier[i] << endl;
		}
		fichier << lignesFichier[lignesFichier.size() - 1];//on ne veut pas de fin de ligne
		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;

	Automate temp("minimiser.txt");
	return temp;
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

	if (Automate::type == FINI)
	{
		cerr << "Les machines a etats de type fini n'ont pas de sorties" << endl;
		return "";
	}
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
				//trouver cet etat et mettre a jour la variable etat
				Etat tampon = Etat(IDetat);
				EtatDest = find(ListeEtats.begin(), ListeEtats.end(), tampon);

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

	list<Etat>::iterator itEtats = ListeEtats.begin();
	for (; itEtats != ListeEtats.end(); itEtats++)
	{
		itEtats->convertisseurMoore2Mealy();
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
		list<pair<Etat*, Transition*>> listeTransitions;
		// Pour chaque état source
		for(Etat source : ListeEtats)
		{
			// Si une transition pointe vers la cible, enregistrer (avec la source)
			for(Transition transition : source.getListTransition())
			{
				if(transition.getEtatDestination() == cible.getNumEtat())
					listeTransitions.push_back(make_pair(&source, &transition));
			}
		}

		// Vérifier si toutes les transitions entrantes sont de même sortie
		string premiereSortie = (*listeTransitions.begin()).second->getSortie();
		cible.setSortie(premiereSortie);
		bool unique = true;
		for(pair<Etat*, Transition*> paire : listeTransitions)
		{
			if(paire.second->getSortie() != premiereSortie)
				unique = false;
		}

		// Si oui, transférer les sorties
		if(unique)
		{
			for(pair<Etat*, Transition*> paire : listeTransitions)
				paire.second->setSortie("");
		}
		// Sinon, créer autant d'états que de différentes sorties, puis modifier les transitions
		else
		{
			vector<string> sorties;
			sorties.push_back(premiereSortie);
			for(pair<Etat*, Transition*> paire : listeTransitions)
			{
				unique = true;
				for(string sortie : sorties)
				{
					if(sortie != paire.second->getSortie())
						unique = false;
				}
				if(unique)
					sorties.push_back(paire.second->getSortie());
			}

			for(string sortie : sorties)
			{
				if(sortie != premiereSortie)
				{
					Etat nouvelEtat = cible;
					nouvelEtat.setNumEtat(nbEtats);
					nbEtats++;
					nouvelEtat.majNum();
					nouvelEtat.setSortie(sortie);
					for(pair<Etat*, Transition*> paire : listeTransitions)
					{
						if(paire.second->getSortie() == sortie)
							paire.second->setEtatDestination(nouvelEtat.getNumEtat());
					}
					ListeEtats.push_back(nouvelEtat);
				}
			}

			for(pair<Etat*, Transition*> paire : listeTransitions)
				paire.second->setSortie("");
		}
	}
	type = Automate::MOORE;
}
