#include "lexer.h"
#include <iostream>

Symbole* Lexer::Consulter()
{
	if ((size_t) tete == flux.length())
		tampon = new Symbole(FIN);
	else
	{
		switch (flux[tete])
		{
			case '(':
				tampon = new Symbole(OPENPAR);

				break;
			case ')':
				tampon = new Symbole(CLOSEPAR);

				break;
			case '*':
				tampon = new Symbole(MULT);

				break;
			case '+':
				tampon = new Symbole(PLUS);

				break;
			default:
				if (flux[tete] <= '9' && flux[tete] >= '0')
				{
					int resultat = flux[tete] - '0';
					int i = 1;
					while (flux[tete + i] <= '9' && flux[tete + i] >= '0')
					{
						resultat = resultat * 10 + (flux[tete + i] - '0');
						++i;
					}
					tampon = new Entier(resultat);
				}
				else
				{
					tampon = new Symbole(ERREUR);
				}
		}
	}

	return tampon;
}

void Lexer::Avancer()
{
	int number_digits_count = 0;
	while (flux[tete + number_digits_count] <= '9' && flux[tete + number_digits_count] >= '0')
	{
		++number_digits_count;
	}

	if (number_digits_count > 0)
	{
		--number_digits_count;
	}
	tete = tete + 1 + number_digits_count;
}

int Lexer::getPosition()
{
	return tete;
}

