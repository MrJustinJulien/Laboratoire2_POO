#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <list>
#include "Compteur.h"
#include "Commande.h"
#include "Reception.h"

using namespace std;

class Client
{
public:
	Client(string nom, int seuilQualite);
	Client(const Client& client);
	~Client();

	Commande getCommande(int id) const { return *commandesA2024[id]; }
	Reception* getReception() const { return reception; }
	int getSeuilQualite() const { return seuilQualite; }
	string getNom() const { return nom; }
	void recevoirCommande(Reception* reception);
	void consommerProduits();
	int getSatisfactionProduit(int idProduit) const;
	friend ostream& operator<<(ostream& out, const Client& client);


private:
	string nom;
	int seuilQualite;
	Commande* commandesA2024[4];
	Reception* reception;
	void preparerCommande2024();
};

#endif

