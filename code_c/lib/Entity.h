#include <iostream>
#include <string>
#include "Node.h"
#include "Signal.h"
#include "Mot.h"
#include <list>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//
// Entity - classe de base pour une entité.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity 
{
public:
  // Constructeurs/destructeur
  Entity () { }
  Entity (string name): _name (name) { }
  ~Entity () { cout << "destroying " << _name << std::endl; }
  //int TestEntity(list<Mot> my_list_mot);


public:
    string _name;
    list<Signal>  _signal;
};

#endif
  
    
