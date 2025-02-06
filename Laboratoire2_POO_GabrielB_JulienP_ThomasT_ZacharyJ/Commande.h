#ifndef COMMANDE_H
#define COMMANDE_H

#include <string>
#include "Compteur.h"
#include "Produit.h"

using namespace std;

class Commande
{
public:
	Commande(int noCommande, int qteProduits[]);
	Commande(const Commande& commande);
	~Commande();

	int getNoCommande() const { return noCommande; }
	int getQuantiteProduit(int idProduit) const;
	friend ostream& operator<<(ostream& out, const Commande& commande);

private:
	int validerQuantite(int q);
	int noCommande;
	int quantiteProduits[5];

};
#endif

