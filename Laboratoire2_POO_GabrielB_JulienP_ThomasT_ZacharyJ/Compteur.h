#ifndef COMPTEUR_H
#define COMPTEUR_H

#include <string>

using namespace std;

class Compteur
{
public:
	Compteur();
	Compteur(const Compteur& compteur);
	~Compteur();

	static void ajouterConstructeur() { constructeur++; }
	static void ajouterConstructeurCopie() { constructeurCopie++; }
	static void ajouterDestructeur() { destructeur++; }

	static int getNbConstructeurs() { return constructeur; }
	static int getNbConstructeursCopie() { return constructeurCopie; }
	static int getNbDestructeurs() { return destructeur; }

private:
	static int constructeur;
	static int constructeurCopie;
	static int destructeur;
};

#endif

