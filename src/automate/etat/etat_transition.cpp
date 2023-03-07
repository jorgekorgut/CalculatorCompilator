#include "etat_transition.h"

#include "../automate.h"

void E_0::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case INT:
			automate.decalage_etat_terminal(new E_3(), symbole);
			break;
		case OPENPAR:
			automate.decalage_etat_terminal(new E_2(), symbole);
			break;
		case EXP:
			automate.decalage_etat_non_terminal(new E_1(), symbole);
			break;
		default:
			automate.declancher_erreur("'val' ou '(' attendue mais n'a pas été trouvée", automate.get_lexer_position());
			break;
	}
}

void E_1::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
			automate.decalage_etat_terminal(new E_4(), symbole);
			break;
		case MULT:
			automate.decalage_etat_terminal(new E_5(), symbole);
			break;
		case FIN:
			automate.terminer();
			break;
		default:
			automate.declancher_erreur("'+', '*' ou '$' attendue mais n'a pas été trouvée", automate.get_lexer_position());
			break;
	}
}

void E_2::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case INT:
			automate.decalage_etat_terminal(new E_3(), symbole);
			break;
		case OPENPAR:
			automate.decalage_etat_terminal(new E_2(), symbole);
			break;
		case EXP:
			automate.decalage_etat_non_terminal(new E_6(), symbole);
			break;
		default:
			automate.declancher_erreur("'val', '(' ou 'EXP' attendue mais n'a pas été trouvée", automate.get_lexer_position());
			break;
	}
}

void E_3::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
		{
			automate.reduction_constante();
		}
			break;
		case MULT:
		{
			automate.reduction_constante();
		}
			break;
		case CLOSEPAR:
		{
			automate.reduction_constante();
		}
			break;
		case FIN:
		{
			automate.reduction_constante();
		}
			break;
		default:
			automate.declancher_erreur("'+', '*', ')' ou '$' est attendue mais n'a pas été trouvée", automate.get_lexer_position());
			break;
	}
}

void E_4::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case INT:
			automate.decalage_etat_terminal(new E_3(), symbole);
			break;
		case OPENPAR:
			automate.decalage_etat_terminal(new E_2(), symbole);
			break;
		case EXP:
			automate.decalage_etat_non_terminal(new E_7(), symbole);
			break;
		default:
			automate.declancher_erreur("'val', '(' ou 'EXP' est attendue mais n'a pas été trouvée", automate.get_lexer_position());
			break;
	}
}

void E_5::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case INT:
			automate.decalage_etat_terminal(new E_3(), symbole);
			break;
		case OPENPAR:
			automate.decalage_etat_terminal(new E_2(), symbole);
			break;
		case EXP:
			automate.decalage_etat_non_terminal(new E_8(), symbole);
			break;
		default:
			automate.declancher_erreur("'val', '(' ou 'EXP' attendue mais n'a pas été trouvée", automate.get_lexer_position());
			break;
	}
}

void E_6::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
			automate.decalage_etat_terminal(new E_4(), symbole);
			break;
		case MULT:
			automate.decalage_etat_terminal(new E_5(), symbole);
			break;
		case CLOSEPAR:
			automate.decalage_etat_terminal(new E_9(), symbole);
			break;
		default:
			automate.declancher_erreur("'+', '*' ou ')' attendue mais n'a pas été trouvée", automate.get_lexer_position());
			break;
	}
}

void E_7::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
			automate.reduction_somme();
			break;
		case MULT:
			automate.decalage_etat_terminal(new E_5(), symbole);
			break;
		case CLOSEPAR:
			automate.reduction_somme();
			break;
		case FIN:
			automate.reduction_somme();
			break;
		default:
			automate.declancher_erreur("'+', '*', ')' ou '$' est attendue mais n'a pas été trouvée", automate.get_lexer_position());
			break;
	}
}

void E_8::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
			automate.reduction_multiplication();
			break;
		case MULT:
			automate.reduction_multiplication();
			break;
		case CLOSEPAR:
			automate.reduction_multiplication();
			break;
		case FIN:
			automate.reduction_multiplication();
			break;
		default:
			automate.declancher_erreur("'+', '*', ')' ou '$' attendue en position mais n'a pas été trouvée", automate.get_lexer_position());
			break;
	}
}

void E_9::transition(Automate & automate, Symbole * symbole)
{

	switch ((int) *symbole)
	{
		case PLUS:
			automate.reduction_parenthesis();
			break;
		case MULT:
			automate.reduction_parenthesis();
			break;
		case CLOSEPAR:
			automate.reduction_parenthesis();
			break;
		case FIN:
			automate.reduction_parenthesis();
			break;
		default:
			automate.declancher_erreur("'+', '*', ')' ou '$' attendue mais n'a pas été trouvée", automate.get_lexer_position());
			break;
	}
}
