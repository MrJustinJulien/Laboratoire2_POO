#ifndef RAPPORTASSURANCEQUALITE_H
#define RAPPORTASSURANCEQUALITE_H

#include <string>
#include "Compteur.h"
#include "Client.h"

using namespace std;

class RapportAssuranceQualite
{
private:
	string nomClient;
	int noCommande;
	int idBonCommande;
	int quantitesProduitsCommandes[5];
	int quantitesProduitsRecus[5];
	int satisfactionClient[5];

	int calculerSatisfactionGlobaleClient();
public:
	RapportAssuranceQualite();
	~RapportAssuranceQualite();
	RapportAssuranceQualite(RapportAssuranceQualite& aq);

	void setNomClient(string nomClient) { this->nomClient = nomClient; }
	void setNoCommande(int noCommande) { this->noCommande = noCommande; }
	void setIdBonCommande(int idBonCommande) { this->idBonCommande = idBonCommande; }
	void setQuantiteProduitCommande(int quantite, int idProduit) { quantitesProduitsCommandes[idProduit] = quantite; }
	void setQuantiteProduitRecu(int quantite, int idProduit) { quantitesProduitsRecus[idProduit] = quantite; }
	void setSatisfactionClient(int satisfaction, int idProduit) { satisfactionClient[idProduit] = satisfaction; }
	string genererRapport(const Client& client);
};

#endif

