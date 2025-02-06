#ifndef BONCOMMANDE_H
#define BONCOMMANDE_H

#include <string>
#include "Compteur.h"
#include "Commande.h"

using namespace std;

class BonCommande
{
public:
	BonCommande(int idBonCommande, Commande* commande);
	BonCommande(const BonCommande& bonCommande);
	~BonCommande();

	void ajouterProduits(int quantite, int id);
	int getQuantiteProduits(int id) const { return quantiteProduits[id]; }
	Commande* getCommande() const { return commande; }
	int getIdBonCommande() const { return idBonCommande; }
	friend ostream& operator<<(ostream& out, const BonCommande& bonCommande);

private:
	int idBonCommande;
	int quantiteProduits[5];
	Commande* commande;
};

#endif

