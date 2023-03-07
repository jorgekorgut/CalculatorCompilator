#include "symbole.h"
#include <iostream>

void Symbole::afficher()
{
	cout << Etiquettes[ident];
}

void Entier::afficher()
{
	Symbole::afficher();
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
