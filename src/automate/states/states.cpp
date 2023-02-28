#include "states.h"

#include "../automate.h"

void E_0::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case INT:
			automate.decalageEtatTerminal(new E_3(), symbole);
			break;
		case OPENPAR:
			automate.decalageEtatTerminal(new E_2(), symbole);
			break;
		case EXP:
			automate.decalageEtatNonTerminal(new E_1(), symbole);
			break;
		default:
			automate.raiseException("'val' ou '(' attendue mais n'a pas été trouvée", automate.getLexerPosition());
			break;
	}
}

void E_1::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
			automate.decalageEtatTerminal(new E_4(), symbole);
			break;
		case MULT:
			automate.decalageEtatTerminal(new E_5(), symbole);
			break;
		case FIN:
			automate.terminer();
			break;
		default:
			automate.raiseException("'+', '*' ou '$' attendue mais n'a pas été trouvée", automate.getLexerPosition());
			break;
	}
}

void E_2::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case INT:
			automate.decalageEtatTerminal(new E_3(), symbole);
			break;
		case OPENPAR:
			automate.decalageEtatTerminal(new E_2(), symbole);
			break;
		case EXP:
			automate.decalageEtatNonTerminal(new E_6(), symbole);
			break;
		default:
			automate.raiseException("'val', '(' ou 'EXP' attendue mais n'a pas été trouvée", automate.getLexerPosition());
			break;
	}
}

void E_3::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
		{
			automate.reductionConstante();
		}
			break;
		case MULT:
		{
			automate.reductionConstante();
		}
			break;
		case CLOSEPAR:
		{
			automate.reductionConstante();
		}
			break;
		case FIN:
		{
			automate.reductionConstante();
		}
			break;
		default:
			automate.raiseException("'+', '*', ')' ou '$' est attendue mais n'a pas été trouvée", automate.getLexerPosition());
			break;
	}
}

void E_4::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case INT:
			automate.decalageEtatTerminal(new E_3(), symbole);
			break;
		case OPENPAR:
			automate.decalageEtatTerminal(new E_2(), symbole);
			break;
		case EXP:
			automate.decalageEtatNonTerminal(new E_7(), symbole);
			break;
		default:
			automate.raiseException("'val', '(' ou 'EXP' est attendue mais n'a pas été trouvée", automate.getLexerPosition());
			break;
	}
}

void E_5::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case INT:
			automate.decalageEtatTerminal(new E_3(), symbole);
			break;
		case OPENPAR:
			automate.decalageEtatTerminal(new E_2(), symbole);
			break;
		case EXP:
			automate.decalageEtatNonTerminal(new E_8(), symbole);
			break;
		default:
			automate.raiseException("'val', '(' ou 'EXP' attendue mais n'a pas été trouvée", automate.getLexerPosition());
			break;
	}
}

void E_6::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
			automate.decalageEtatTerminal(new E_4(), symbole);
			break;
		case MULT:
			automate.decalageEtatTerminal(new E_5(), symbole);
			break;
		case CLOSEPAR:
			automate.decalageEtatTerminal(new E_9(), symbole);
			break;
		default:
			automate.raiseException("'+', '*' ou ')' attendue mais n'a pas été trouvée", automate.getLexerPosition());
			break;
	}
}

void E_7::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
			automate.reductionSomme();
			break;
		case MULT:
			automate.decalageEtatTerminal(new E_5(), symbole);
			break;
		case CLOSEPAR:
			automate.reductionSomme();
			break;
		case FIN:
			automate.reductionSomme();
			break;
		default:
			automate.raiseException("'+', '*', ')' ou '$' est attendue mais n'a pas été trouvée", automate.getLexerPosition());
			break;
	}
}

void E_8::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
			automate.reductionMultiplication();
			break;
		case MULT:
			automate.reductionMultiplication();
			break;
		case CLOSEPAR:
			automate.reductionMultiplication();
			break;
		case FIN:
			automate.reductionMultiplication();
			break;
		default:
			automate.raiseException("'+', '*', ')' ou '$' attendue en position mais n'a pas été trouvée", automate.getLexerPosition());
			break;
	}
}

void E_9::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
			automate.reductionParenthesis();
			break;
		case MULT:
			automate.reductionParenthesis();
			break;
		case CLOSEPAR:
			automate.reductionParenthesis();
			break;
		case FIN:
			automate.reductionParenthesis();
			break;
		default:
			automate.raiseException("'+', '*', ')' ou '$' attendue mais n'a pas été trouvée", automate.getLexerPosition());
			break;
	}
}
