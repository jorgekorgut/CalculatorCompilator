#include "automate.h"
#include "etat/etat_transition.h"
#include <stack>
#include <iostream>
#include <cassert>

Automate::Automate(string expression) :
		lexer(expression)
{
	states = new stack<Etat*>();
	symboles = new stack<Symbole*>();
}

void Automate::executer()
{
	Symbole * s = lexer.Consulter();
	states->push(new E_0());
	while (fin == 0)
	{

#ifdef DEBUG
		std::cout << "== Char read : ";
		s->Affiche();
		std::cout << std::endl;
#endif
		states->top()->transition(*this, s);
		s = lexer.Consulter();
	}
}

Automate::~Automate()
{
	while (!states->empty())
	{
		Etat * top = states->top();
		delete top;
		states->pop();
	}

	while (!symboles->empty())
	{
		Symbole * top = symboles->top();
		delete top;
		symboles->pop();
	}

	delete states;
	delete symboles;
}

void Automate::terminer()
{
#ifdef DEBUG
	std::cout << "== Starting the end" << std::endl;
#endif
	fin = 1;
}

int Automate::resultat()
{
	assert(fin == 1 && "Il y a un erreur de syntax");
	return symboles->top()->calculer();
}

bool Automate::tester_syntaxe()
{
	return (fin == 1);
}

void Automate::decalage_etat_terminal(Etat * etat, Symbole * symbole)
{
#ifdef DEBUG
	std::cout << "== Decalage Etat Terminal" << std::endl;
#endif
	avancer_lexer();
	empiler_etat(etat);
	empiler_symbole(symbole);
}

void Automate::decalage_etat_non_terminal(Etat * etat, Symbole * symbole)
{
#ifdef DEBUG
	std::cout << "== Decalage Etat Non Terminal" << std::endl;
#endif
	empiler_etat(etat);
	empiler_symbole(symbole);
}

void Automate::reduction_somme()
{
#ifdef DEBUG
	std::cout << "== Starting reduction of Sum" << std::endl;
#endif
	vector<Symbole*> * symboles_depiles = depiler_symbole(3);
	if ((int) *((*symboles_depiles)[0]) != EXP && (int) *((*symboles_depiles)[2]) != EXP
			&& (int) *((*symboles_depiles)[1]) != PLUS)
	{
		declancher_erreur("Not a sum expression.", get_lexer_position());
	}
	ExpressionPlus * exp = new ExpressionPlus((Expression*) ((*symboles_depiles)[0]),
			(Expression*) ((*symboles_depiles)[2]));
	depiler_etat(3);
	transition(exp);

	delete (*symboles_depiles)[1]; // libere la memoire pour '+'
	delete symboles_depiles;
}

void Automate::reduction_multiplication()
{
#ifdef DEBUG
	std::cout << "== Starting reduction of Multiplication" << std::endl;
#endif
	vector<Symbole*> * symboles_depiles = depiler_symbole(3);
	if ((int) *((*symboles_depiles)[0]) != EXP && (int) *((*symboles_depiles)[2]) != EXP
			&& (int) *((*symboles_depiles)[1]) != MULT)
	{
		declancher_erreur("Not a multiplication expression.", get_lexer_position());
	}
	ExpressionMult * exp = new ExpressionMult((Expression*) ((*symboles_depiles)[0]),
			(Expression*) ((*symboles_depiles)[2]));
	depiler_etat(3);
	transition(exp);

	delete (*symboles_depiles)[1]; // libere la memoire pour '*'
	delete symboles_depiles;
}

void Automate::reduction_parenthesis()
{
#ifdef DEBUG
	std::cout << "== Starting reduction of Parenthesis" << std::endl;
#endif
	vector<Symbole*> * symboles_depiles = depiler_symbole(3);
	if ((int) *((*symboles_depiles)[0]) != OPENPAR && (int) *((*symboles_depiles)[2]) != CLOSEPAR
			&& (int) *((*symboles_depiles)[1]) != EXP)
	{
		declancher_erreur("Not a parenthesis expression.", get_lexer_position());
	}
	Expression * exp = (Expression*) ((*symboles_depiles)[1]);
	depiler_etat(3);
	transition(exp);

	delete (*symboles_depiles)[0]; // libere la memoire pour '('
	delete (*symboles_depiles)[2]; // libere la memoire pour ')'
	delete symboles_depiles;
}

int Automate::get_lexer_position()
{
	return lexer.getPosition();
}

void Automate::reduction_constante()
{
#ifdef DEBUG
	std::cout << "== Starting reduction of Constant" << std::endl;
#endif
	vector<Symbole*> * symboles_depiles = depiler_symbole(1);
	ExpressionConst * exp = new ExpressionConst((*symboles_depiles)[0]->calculer());
	depiler_etat(1);
	transition(exp);

	delete symboles_depiles;
}

void Automate::empiler_etat(Etat * etat)
{
	states->push(etat);
#ifdef DEBUG
	std::cout << "== Empiler Etat - Nouveau ";
	states->top()->afficher();
	std::cout << std::endl;
#endif
}

void Automate::empiler_symbole(Symbole * symbole)
{
	symboles->push(symbole);
}

void Automate::avancer_lexer()
{
	lexer.Avancer();
}

vector<Symbole*>* Automate::depiler_symbole(int nombre_symboles)
{
	vector<Symbole*> * symboles_depiles = new vector<Symbole*>();
	for (int i = 0; i < nombre_symboles; i++)
	{
		symboles_depiles->push_back(symboles->top());
		symboles->pop();
	}
	return symboles_depiles;
}

void Automate::depiler_etat(int nombre_etats)
{
	for (int i = 0; i < nombre_etats; i++)
	{
		Etat * target = states->top();
		states->pop();
		delete target;
	}

#ifdef DEBUG
	std::cout << "== Depiler Etat - Nouveau ";
	states->top()->afficher();
	std::cout << std::endl;
#endif
}

void Automate::transition(Symbole * symbole)
{
#ifdef DEBUG
	std::cout << "== Commencer transition etat non terminal" << std::endl;
#endif
	states->top()->transition(*this, symbole);
}

void Automate::declancher_erreur(string message, int position)
{
	std::cout << "ERROR::POS=" << position << "::" << message << std::endl;
	fin = -1;
}
