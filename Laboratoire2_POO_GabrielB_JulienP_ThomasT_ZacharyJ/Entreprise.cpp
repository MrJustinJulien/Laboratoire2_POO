#include <iostream>
#include "Entreprise.h"

using namespace std;

int Entreprise::numeroBonCommande = 0;

BonCommande* Entreprise::traiterCommande(Commande& commande)
{
	BonCommande* bonCommande = new BonCommande(genererNoBonCommande(), &commande);
	for (int idProduit = 0; idProduit < 5; idProduit++)
	{
		int quantiteProduit = commande.getQuantiteProduit(idProduit);
		switch (idProduit)
		{
		case 0:
			for (int q = 0; q < quantiteProduit; q++)
				inventaire.ajouterProduit(produireProduitA());
			bonCommande->ajouterProduits(quantiteProduit, idProduit);
			break;
		case 1:
			for (int q = 0; q < quantiteProduit; q++)
				inventaire.ajouterProduit(produireProduitB());
			bonCommande->ajouterProduits(quantiteProduit, idProduit);
			break;
		case 2:
			for (int q = 0; q < quantiteProduit; q++)
				inventaire.ajouterProduit(produireProduitC());
			bonCommande->ajouterProduits(quantiteProduit, idProduit);
			break;
		case 3:
			for (int q = 0; q < quantiteProduit; q++)
				inventaire.ajouterProduit(produireProduitD());
			bonCommande->ajouterProduits(quantiteProduit, idProduit);
			break;
		case 4:
			for (int q = 0; q < quantiteProduit; q++)
				inventaire.ajouterProduit(produireProduitE());
			bonCommande->ajouterProduits(quantiteProduit, idProduit);
			break;
		}
	}
	return bonCommande;
}


ProduitA* Entreprise::produireProduitA()
{
	int quantiteNecessaire[] = { 3, 2, 4, 5, 6 };
	ProduitA* produit = new ProduitA();

	for (int idComposant = 0; idComposant < 5; idComposant++)
	{
		if (quantiteNecessaire[idComposant] > entrepot.getQuantiteComposants(idComposant))
			commanderComposantsFournisseur(idComposant, quantiteNecessaire[idComposant]);
		for (int q = 0; q < quantiteNecessaire[idComposant]; q++)
			produit->ajouterComposant(entrepot.recupererComposant(idComposant));
	}
	return produit;
}

ProduitB* Entreprise::produireProduitB()
{
	int quantiteNecessaire[] = { 4, 1, 1, 9, 3 };
	ProduitB* produit = new ProduitB();

	for (int idComposant = 0; idComposant < 5; idComposant++)
	{
		if (quantiteNecessaire[idComposant] < entrepot.getQuantiteComposants(1))
			commanderComposantsFournisseur(idComposant, quantiteNecessaire[idComposant]);
		for (int q = 0; q < quantiteNecessaire[idComposant]; q++)
			produit->ajouterComposant(entrepot.recupererComposant(idComposant));
	}
	return produit;
}

ProduitC* Entreprise::produireProduitC()
{
	int quantiteNecessaire[] = { 10, 0, 0, 3, 1 };
	ProduitC* produit = new ProduitC();

	for (int idComposant = 0; idComposant < 5; idComposant++)
	{
		if (quantiteNecessaire[idComposant] < entrepot.getQuantiteComposants(2))
			commanderComposantsFournisseur(idComposant, quantiteNecessaire[idComposant]);
		for (int q = 0; q < quantiteNecessaire[idComposant]; q++)
			produit->ajouterComposant(entrepot.recupererComposant(idComposant));
	}
	return produit;
}

ProduitD* Entreprise::produireProduitD()
{
	int quantiteNecessaire[] = { 4, 4, 2, 12, 0 };
	ProduitD* produit = new ProduitD();

	for (int idComposant = 0; idComposant < 5; idComposant++)
	{
		if (quantiteNecessaire[idComposant] < entrepot.getQuantiteComposants(3))
			commanderComposantsFournisseur(idComposant, quantiteNecessaire[idComposant]);
		for (int q = 0; q < quantiteNecessaire[idComposant]; q++)
			produit->ajouterComposant(entrepot.recupererComposant(idComposant));
	}
	return produit;
}

ProduitE* Entreprise::produireProduitE()
{
	int quantiteNecessaire[] = { 5, 4, 3, 4, 5 };
	ProduitE* produit = new ProduitE();

	for (int idComposant = 0; idComposant < 5; idComposant++)
	{
		if (quantiteNecessaire[idComposant] < entrepot.getQuantiteComposants(4))
			commanderComposantsFournisseur(idComposant, quantiteNecessaire[idComposant]);
		for (int q = 0; q < quantiteNecessaire[idComposant]; q++)
			produit->ajouterComposant(entrepot.recupererComposant(idComposant));
	}
	return produit;
}

void Entreprise::commanderComposantsFournisseur(int idComposant, int quantiteNecessaire)
{
	entrepot.ajouterComposants(fournisseur.commanderComposant(idComposant, quantiteNecessaire + 10), idComposant);
}

Reception* Entreprise::recupererCommande(BonCommande* bonCommande)
{
	Reception* reception = new Reception(bonCommande);

	for (int idProduit = 0; idProduit < 5; idProduit++)
	{
		int quantiteProduits = bonCommande->getQuantiteProduits(idProduit);
		for (int noProduit = 0; noProduit < quantiteProduits; noProduit++)
			reception->ajouterProduit(inventaire.recupererProduit(idProduit), idProduit);
	}
	return reception;
}

void Entreprise::validerSatisfaction(RapportAssuranceQualite& aq, Client& client)
{
	aq.setNomClient(client.getNom());
	aq.setNoCommande(client.getReception()->getBonCommande()->getCommande()->getNoCommande());
	aq.setIdBonCommande(client.getReception()->getBonCommande()->getIdBonCommande());

	for (int id = 0; id < 5; id++)
	{
		aq.setQuantiteProduitCommande(client.getReception()->getBonCommande()->getCommande()->getQuantiteProduit(id), id);
		aq.setQuantiteProduitRecu(client.getReception()->getQuantiteProduitsRecus(id), id);
		aq.setSatisfactionClient(client.getSatisfactionProduit(id), id);
	}
}
