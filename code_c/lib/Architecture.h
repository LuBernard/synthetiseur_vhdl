#include <iostream>
#include <string>
#include <vector> 
#include "Node.h"

/////////////////////////////////////////////////////////////////////////////
//
// Architecture - classe de base pour une Architecture.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _ARCHITECTURE_H_
#define _ARCHITECTURE_H_

class Architecture
{
public:
  // Constructeurs/destructeur
  Architecture () { }
  Architecture (std::string name): _name (name) { }
  ~Architecture () { std::cout << "destroying " << _name << std::endl; }
  void setEntityName(std::string name){ _name_entity = name; }
private:
    std::string _name;
    std::string _name_entity;
    std::vector<string> _instructions;
};

#endif
    