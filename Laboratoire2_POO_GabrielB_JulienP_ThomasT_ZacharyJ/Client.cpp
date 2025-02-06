#include <iostream>
#include "Client.h"

using namespace std;

Client::Client(string nom, int seuilQualite)
{
	this->nom = nom;
	this->seuilQualite = seuilQualite;
	reception = nullptr;
	preparerCommande2024();

	Compteur::ajouterConstructeur();
}

Client::Client(const Client& client)
{
	this->nom = client.nom;
	this->seuilQualite = client.seuilQualite;
	reception = nullptr;
	for (int i = 0; i < 4; i++)
	{
		commandesA2024[i] = new Commande(*client.commandesA2024[i]);
	}

	Compteur::ajouterConstructeurCopie();
}

Client::~Client()
{
	for (int i = 0; i < 4; i++)
	{
		delete commandesA2024[i];
	}

	Compteur::ajouterDestructeur();
}

void Client::recevoirCommande(Reception* reception)
{
	this->reception = reception;
}

void Client::consommerProduits()
{
	delete reception;
	reception = nullptr;
}

int Client::getSatisfactionProduit(int idProduit) const
{
	const list <Produit*>& produits = reception->getProduits(idProduit);
	const Commande* commande = getReception()->getBonCommande()->getCommande();
	int total = 0;

	for (const auto& produit : produits)
	{
		int qualite = produit->evaluerQualite();
		if (qualite > seuilQualite)
		{
			total += 5;
		}
		else if (qualite == seuilQualite)
		{
			total += 4;
		}
		else
		{
			total += 3;
		}
	}

	if (total == 0) return 0;
	return (total / commande->getQuantiteProduit(idProduit));
}

void Client::preparerCommande2024()
{
	int quantites[4][5] =
	{
		{3, 3, 3, 3, 3},  //Septembre
		{5, 3, 3, 3, 10}, //Octobre
		{-1, 0, 5, 5, 4}, //Novembre
		{1, 2, 12, 0, 0}  //Décembre
	};

	for (int i = 0; i < 4; i++)
	{
		commandesA2024[i] = new Commande(2024 + i, quantites[i]);
	}
}

ostream& operator<<(ostream& out, const Client& client)
{
	out << "--------------------------------------" << endl
		<< "CLIENT" << endl
		<< " Nom: " << client.nom << endl
		<< " Seuil de qualite: " << client.seuilQualite << endl
		<< "--------------------------------------" << endl;

	return out;
}
