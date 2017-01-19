#include <iostream>
#include <string>
#include "Entity.h"
using namespace std;


#ifndef _ENTITY_H_
#define _ENTITY_H_

class Mot 
{
public:
	// Constructeur
	Mot (string lexeme, string caracteristique, int place)
	{
		this->lexeme = lexeme;
		this->caracteristique = caracteristique;
		this->place = place;
	}
	//constructeur par défaut
	Mot()
	{
	lexeme = "";
	caracteristique = "";
	place = -1;
	}

	//accesseurs et mutateurs
	void setLexeme(string lexeme){this->lexeme = lexeme;}
	void setCarac(string caracteristique){this->caracteristique = caracteristique;}
	void setPlace(int place){this->place = place;}

	string getLexeme{return lexeme;}
	string getCarac{return caracteristique;}
	string getPlace{return place;}

private:
	// Fonctions internes
	//virtual void draw () { std::cout << "mot " << _name << std::endl; }

protected:

	string lexeme;
	string caracteristique;
	int place;
};

#endif
