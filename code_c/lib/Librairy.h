#include <iostream>
#include <string>
#include "Node.h"
#include "Use.h"

using namespace std; 

/////////////////////////////////////////////////////////////////////////////
//
// Librairy - classe de base pour une Librairie.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _LIBRAIRY_H_
#define _LIBRAIRY_H_

class Librairy
{
public:
  // Constructeurs/destructeur
  Librairy () { }
  Librairy (std::string name): _name (name) { }
  ~Librairy () { std::cout << "destroying " << _name << std::endl; }

public:
    string _name;
	list<Use>  _use;

};

#endif
  
    
