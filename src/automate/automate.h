#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stack>
#include <vector>
#include "states/state.h"
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
		bool syntaxCorrecte();

		void decalageEtatTerminal(State * etat, Symbole * symbole);
		void decalageEtatNonTerminal(State * etat, Symbole * symbole);
		void reductionSomme();
		void reductionMultiplication();
		void reductionParenthesis();
		void reductionConstante();
		int getLexerPosition();

		void raiseException(string message,int position);
	private:
		std::stack<State*> * states;
		std::stack<Symbole*> * symboles;
		Lexer lexer;

		void empiler_etat(State * etat);
		void empiler_symbole(Symbole * symbole);
		void avancer_lexer();
		void transition(Symbole * symbole);

		vector<Symbole*>* depiler_symbole(int i);
		void depiler_etat(int i);
		int fin = 0;
};

#endif
