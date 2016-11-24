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

class Mot : public Entity
{
public:
  // Constructeur
  Mot (std::string name)
    : Entity (name) { }

private:
  // Fonctions internes
  virtual void draw () { std::cout << "mot " << _name << std::endl; }
};

#endif
