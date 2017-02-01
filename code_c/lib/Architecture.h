#include <iostream>
#include <string>
#include <list> 

#include "Process.h"
using namespace std;
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
  Architecture (string name) {name_architecture = name;}
  ~Architecture () { }
  void set_architecture_name(string name){ name_architecture = name; }
private:
    string name_architecture;
    string _name_entity;
    list<Process> instructions;
};

#endif
    
