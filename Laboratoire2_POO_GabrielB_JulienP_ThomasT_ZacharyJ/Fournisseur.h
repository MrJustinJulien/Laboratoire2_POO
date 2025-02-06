#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <list>
#include "Compteur.h"
#include "Hasard.h"

#include "Composant1.h"
#include "Composant2.h"
#include "Composant3.h"
#include "Composant4.h"
#include "Composant5.h"

using namespace std;

class Fournisseur
{
public:
	Fournisseur();
	Fournisseur(const Fournisseur& f);
	~Fournisseur();

	list <Composant*> commanderComposant(int idComposant, int quantite);

private:
	int quantiteComposant[5];
	Composant1* produireComposant1();
	Composant2* produireComposant2();
	Composant3* produireComposant3();
	Composant4* produireComposant4();
	Composant5* produireComposant5();
};

#endif

