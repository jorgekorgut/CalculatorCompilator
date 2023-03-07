#include <iostream>
#include "automate/automate.h"

int main(int argc, char *argv[])
{

#ifdef DEBUG
	std::cout << "== Debug mode active ==" << std::endl;
#endif

	if (argc != 2){
		std::cout << "== Pour utiliser la calculatrice veuillez appeller : " << std::endl;
		std::cout << "calculer \"[expression]\"" << std::endl;
		std::cout << "Operations permises : () * +" << std :: endl;
		return 1;
	}

	string chaine(argv[1]);
	std::cout << "Expression : " << chaine << std::endl;

	Automate automate(chaine);

	automate.executer();

	if(automate.tester_syntaxe())
	{
		int resultat = automate.resultat();
		std::cout << "Result : " << resultat << std::endl;
	}
	else
	{
		std::cout << "Result : Error" << std::endl;
		size_t i = 0;
		while( i < chaine.size() && i < (size_t)automate.get_lexer_position())
		{
			std::cout << chaine.at(i);
			i++;
		}

		std::cout << "\033[31m?\033[0m";

		while( i < chaine.size())
		{
			std::cout << chaine.at(i);
			i++;
		}
		std::cout << std::endl;
	}
	return 0;
}