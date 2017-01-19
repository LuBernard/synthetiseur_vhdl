#include <iostream>
#include <string>
#include "Entity.h"

/////////////////////////////////////////////////////////////////////////////
//
// Monster - entité "mot".
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _ENTITY_H_
#define _ENTITY_H_

class Mot 
{
public:
  // Constructeur
  Mot (std::string name)
    : Entity (name) { }
	
	void setLexeme();
	void setCarac();
	void setPlace();
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
