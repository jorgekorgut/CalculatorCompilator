#include "symbole.h"
#include <iostream>

void Symbole::Affiche()
{
	cout << Etiquettes[ident];
}

void Entier::Affiche()
{
	Symbole::Affiche();
	cout << "(" << valeur << ")";
}

int Entier::calculer()
{
	return this->valeur;
}

int ExpressionMult::calculer()
{
	return this->expression1->calculer() * this->expression2->calculer();
}

int ExpressionPlus::calculer()
{
	return this->expression1->calculer() + this->expression2->calculer();
}

int ExpressionConst::calculer()
{
	return this->valeur;
}
