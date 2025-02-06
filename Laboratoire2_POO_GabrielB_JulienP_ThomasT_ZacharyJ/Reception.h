#ifndef RECEPTION_H
#define RECEPTION_H

#include <string>
#include <list>
#include "Compteur.h"
#include "Produit.h"
#include "BonCommande.h"

using namespace std;

class Reception
{
public:
	Reception(BonCommande* bonCommande);
	Reception(const Reception& reception) = delete;
	~Reception();

	void ajouterProduit(Produit* produit, int id);
	BonCommande* getBonCommande() const { return bonCommande; }
	int getQuantiteProduitsRecus(int id) const { return static_cast<int>(produits[id].size()); }
	list <Produit*> getProduits(int idProduit) const { return produits[idProduit]; }
	friend ostream& operator<<(ostream& out, const Reception& reception);

private:
	list <Produit*> produits[5];
	BonCommande* bonCommande;
};

#endif
