#include <sstream>
#include "RapportAssuranceQualite.h"

RapportAssuranceQualite::RapportAssuranceQualite()
{
	Compteur::ajouterConstructeur();

	idBonCommande = -1;
	noCommande = -1;
	nomClient = "INCONNU";
	for (int id = 0; id < 5; id++)
	{
		quantitesProduitsCommandes[id] = 0;
		quantitesProduitsRecus[id] = 0;
		satisfactionClient[id] = 0;
	}
}

RapportAssuranceQualite::~RapportAssuranceQualite()
{
	Compteur::ajouterDestructeur();
}

RapportAssuranceQualite::RapportAssuranceQualite(RapportAssuranceQualite& aq)
{
	Compteur::ajouterConstructeurCopie();

	nomClient = aq.nomClient;
	idBonCommande = aq.idBonCommande;
	noCommande = aq.noCommande;

	for (int id = 0; id < 5; id++)
	{
		quantitesProduitsCommandes[id] = aq.quantitesProduitsCommandes[id];
		quantitesProduitsRecus[id] = aq.quantitesProduitsRecus[id];
		satisfactionClient[id] = aq.satisfactionClient[id];
	}
}

int RapportAssuranceQualite::calculerSatisfactionGlobaleClient()
{
	int satisfactionGlobale = 0;

	for (int satisfaction : satisfactionClient)
		satisfactionGlobale += satisfaction;
	return int(satisfactionGlobale / 5);
}

string RapportAssuranceQualite::genererRapport(const Client& client)
{
	stringstream ss;

	ss << "----------------------------------------------" << endl;
	ss << "RAPPORT ASSURANCE QUALITE" << endl;
	ss << " Client          : " << nomClient << endl;
	ss << " No de commande : " << noCommande << endl;
	ss << " Bon de commande : " << idBonCommande << endl;
	ss << " Listes des produits" << endl;
	for (int id = 0; id < 5; id++)
	{
		ss << " - Produit{" << id << "} ("
			<< "COMM:" << quantitesProduitsCommandes[id] << "/"
			<< "RECU:" << quantitesProduitsRecus[id] << "/"
			<< "SATI:" << satisfactionClient[id] << ")" << endl;
	}
	ss << " Satisfaction globale : " << calculerSatisfactionGlobaleClient() << endl;
	ss << "----------------------------------------------" << endl;

	return ss.str();
}
