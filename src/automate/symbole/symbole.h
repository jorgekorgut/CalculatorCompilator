#pragma once

#include <string>
using namespace std;

enum Identificateurs
{
	OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, EXP, ERREUR
};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "EXP", "ERREUR" };

class Symbole
{
	public:
		Symbole(int i) :
				ident(i)
		{
		}
		virtual ~Symbole()
		{
		}
		operator int() const
		{
			return ident;
		}
		virtual void Affiche();
		virtual int calculer()
		{
			return 0;
		}
	protected:
		int ident;
};

class Expression : public Symbole
{
	public:
		Expression() :
				Symbole(EXP)
		{

		}

	private:
};

class ExpressionConst : public Expression
{
	public:
		ExpressionConst(int v) :
				valeur(v)
		{
		}

		virtual int calculer();
	protected:
		int valeur;
};

class ExpressionBinaire : public Expression
{
	public:
		ExpressionBinaire(Expression * e1, Expression * e2)
		{
			expression1 = e1;
			expression2 = e2;
		}

		virtual ~ExpressionBinaire(){
			delete expression1;
			delete expression2;
		}

	protected:
		Expression * expression1;
		Expression * expression2;
};

class ExpressionMult : public ExpressionBinaire
{
	public:
		ExpressionMult(Expression * e1, Expression * e2) :
				ExpressionBinaire(e1, e2)
		{

		}
		int calculer();

};

class ExpressionPlus : public ExpressionBinaire
{
	public:
		ExpressionPlus(Expression * e1, Expression * e2) :
				ExpressionBinaire(e1, e2)
		{

		}
		int calculer();

};

class Entier : public Symbole
{
	public:
		Entier(int v) :
				Symbole(INT), valeur(v)
		{
		}

		int calculer();
		virtual void Affiche();
	protected:
		int valeur;
};

