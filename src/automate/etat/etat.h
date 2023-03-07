#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../symbole/symbole.h"

class Automate;

class Etat
{
	public:
		Etat(int valeur): id(valeur) {}
		virtual void transition(Automate & automate, Symbole * symbole) = 0;
		virtual ~Etat(){}
		virtual void afficher()
		{
			std::cout << "Etat: " << id;
		}
	private:
		int id;
};

#endif
