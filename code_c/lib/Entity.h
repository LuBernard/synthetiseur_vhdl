#include <iostream>
#include <string>
#include "Node.h"

/////////////////////////////////////////////////////////////////////////////
//
// Entity - classe de base pour une entité.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity : public Node
{
public:
  // Constructeurs/destructeur
  Entity () { }
  Entity (std::string name)
    : _name (name) { }

  virtual ~Entity () { std::cout << "destroying " << _name << std::endl; }

public:
  // Interface publique
  void drawEntity ()
  {
    // Dessine cette entité
    draw ();

    // Dessine l'entité suivante
    if (!isLastNode ())
      dynamic_cast<Entity *>(_nextNode)->drawEntity ();
  }

private:
  // Fonctions internes
  virtual void draw () { }

protected:
    std::string _name;
};

#endif
