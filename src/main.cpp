#include <iostream>
#include "automate/automate.h"

int main(void)
{

#ifdef DEBUG
	std::cout << "== Debug mode active ==" << std::endl;
#endif

	//string chaine("(1+34)*123");

	//string chaine("3*(((((1)+1)+1)+1))*3");

	string chaine("3*111+2");

	Automate automate(chaine);

	automate.executer();

	if(automate.syntaxCorrecte()){
		int resultat = automate.resultat();
		std::cout << "The result is : " << resultat << std::endl;
	}
}

