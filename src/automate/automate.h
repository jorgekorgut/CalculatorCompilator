#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stack>
#include <vector>
#include "etat/etat.h"
#include "symbole/symbole.h"
#include "lexer.h"

class Automate
{
	public:
		Automate(string expression);
		~Automate();

		void executer();
		void terminer();
		int resultat();
		bool tester_syntaxe();

		void decalage_etat_terminal(Etat * etat, Symbole * symbole);
		void decalage_etat_non_terminal(Etat * etat, Symbole * symbole);
		void reduction_somme();
		void reduction_multiplication();
		void reduction_parenthesis();
		void reduction_constante();
		int get_lexer_position();

		void declencher_erreur(string message,int position);
	private:
		std::stack<Etat*> * states;
		std::stack<Symbole*> * symboles;
		Lexer lexer;

		void empiler_etat(Etat * etat);
		void empiler_symbole(Symbole * symbole);
		void avancer_lexer();
		void transition(Symbole * symbole);

		vector<Symbole*>* depiler_symbole(int i);
		void depiler_etat(int i);
		int fin = 0;
};

#endif
