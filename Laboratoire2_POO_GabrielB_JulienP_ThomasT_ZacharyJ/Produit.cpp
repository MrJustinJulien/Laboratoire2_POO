#include <iostream>
#include "Produit.h"

using namespace std;

Produit::Produit(string nom) :
	nom(nom)
{
	Compteur::ajouterConstructeur();
}

Produit::Produit(const Produit& p) :
	nom(p.nom)
{
	for (Composant* composant : p.composants)
	{
		composants.push_back(new Composant(*composant));
	}

	Compteur::ajouterConstructeurCopie();
}

Produit::~Produit()
{
	for (Composant* composant : composants)
	{
		delete composant;
	}

	Compteur::ajouterDestructeur();
}

int Produit::evaluerQualite() const
{
	int qualiteMoyenne = 0;
	int nbComposants = 0;
	for (Composant* composant : composants)
	{
		qualiteMoyenne += composant->getQualite();
		nbComposants++;
	}
	return (qualiteMoyenne / nbComposants);
}

int Produit::calculerPoids() const
{
	int poidsTotal = 0;
	for (Composant* composant : composants)
	{
		poidsTotal += composant->getPoids();
	}
	return poidsTotal;
}

int Produit::calculerPrix() const
{
	int prixTotal = 0;
	for (Composant* composant : composants)
	{
		prixTotal += composant->getPrix();
	}
	return prixTotal;
}

ostream& operator<<(ostream& out, const Produit& produit)
{
	out << produit.getNom() << " {" << produit.getDescription() << "} --> "
		<< "Poids: " << produit.calculerPoids() << " / Prix: " << produit.calculerPrix();

	return out;
}
