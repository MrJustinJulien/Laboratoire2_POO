#include <iostream>
#include "Fournisseur.h"

using namespace std;

Fournisseur::Fournisseur()
{
	initialize();
	for (int i = 0; i < 5; i++)
	{
		quantiteComposant[i] = 1000;
	}

	Compteur::ajouterConstructeur();
}

Fournisseur::Fournisseur(const Fournisseur& f)
{
	initialize();
	for (int i = 0; i < 5; i++)
	{
		quantiteComposant[i] = f.quantiteComposant[i];
	}

	Compteur::ajouterConstructeurCopie();
}

Fournisseur::~Fournisseur()
{
	Compteur::ajouterDestructeur();
}

list <Composant*> Fournisseur::commanderComposant(int idComposant, int quantite)
{
	list <Composant*> composants;

	for (int i = 0; i < quantite; i++)
	{
		Composant* composant = nullptr;

		switch (idComposant)
		{
		case 0:
			composant = produireComposant1();
			break;
		case 1:
			composant = produireComposant2();
			break;
		case 2:
			composant = produireComposant3();
			break;
		case 3:
			composant = produireComposant4();
			break;
		case 4:
			composant = produireComposant5();
			break;
		default:
			return composants;
		}

		if (composant != nullptr)
		{
			composants.push_back(composant);
		}
		else break;
	}

	return composants;
}

Composant1* Fournisseur::produireComposant1()
{
	if (quantiteComposant[0] <= 0) return nullptr;

	int qualite = recupererValeurAleatoire(90, 100);
	int prix = 30 + (100 - qualite);

	quantiteComposant[0]--;
	return new Composant1(qualite, prix);
}

Composant2* Fournisseur::produireComposant2()
{
	if (quantiteComposant[1] <= 0) return nullptr;

	int qualite = recupererValeurAleatoire(93, 99);
	int prix = recupererValeurAleatoire(33, 37);

	quantiteComposant[1]--;
	return new Composant2(qualite, prix);
}

Composant3* Fournisseur::produireComposant3()
{
	if (quantiteComposant[2] <= 0) return nullptr;

	int prix = recupererValeurAleatoire(38, 45);

	quantiteComposant[2]--;
	return new Composant3(prix);
}

Composant4* Fournisseur::produireComposant4()
{
	if (quantiteComposant[3] <= 0) return nullptr;

	int qualite = recupererValeurAleatoire(80, 100);

	quantiteComposant[3]--;
	return new Composant4(qualite);
}

Composant5* Fournisseur::produireComposant5()
{
	if (quantiteComposant[4] <= 0) return nullptr;

	int qualite = recupererValeurAleatoire(95, 100);
	int tempVariation = recupererValeurAleatoire(0, 10);
	int variation = tempVariation - 5;
	int prix = 33 + (100 - qualite);

	quantiteComposant[4]--;
	return new Composant5(variation, qualite, prix);
}
