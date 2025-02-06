#include <iostream>
#include "Client.h"
#include "Commande.h"
#include "Entrepot.h"
#include "Entreprise.h"
#include "Fournisseur.h"
#include "Inventaire.h"
#include "RapportAssuranceQualite.h"
#include "Reception.h"

using namespace std;

void commerce();
void afficherInformation();

int main()
{
	commerce();
	afficherInformation();
	return 0;
}

void commerce()
{
	Entreprise entreprise;
	Client client("ROGER", 90);
	cout << client << endl;
	for (int x = 0; x < 4; x++)
	{
		Commande commande(client.getCommande(x));
		cout << commande << endl;

		BonCommande* bonCommande = entreprise.traiterCommande(commande);
		cout << *bonCommande << endl;

		Reception* reception = entreprise.recupererCommande(bonCommande);
		cout << *reception << endl;

		client.recevoirCommande(reception);
		RapportAssuranceQualite aq;
		entreprise.validerSatisfaction(aq, client);
		cout << aq.genererRapport(client) << endl;

		client.consommerProduits();
	}
}

void afficherInformation()
{
	cout << endl << endl;
	cout << endl << "-------------------------------" << endl
		<< " NB constructeurs : " << Compteur::getNbConstructeurs() << endl
		<< " NB constructeurs copie : " << Compteur::getNbConstructeursCopie() << endl
		<< " NB destructeurs : " << Compteur::getNbDestructeurs() << endl;
	cin.get();
}