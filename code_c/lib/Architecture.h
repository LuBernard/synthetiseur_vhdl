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
  Architecture (string name) {name_architecture = name;}
  ~Architecture () { }
	void set_architecture_name(string name){ name_architecture = name; }
	string get_architecture_name(){ return name_architecture;}

	void set_name_entity(string name_e){ name_entity = name_e; }
	string get_name_entity(){ return name_entity;}

	void add_variable(string variable){l_variables.push_back(variable);}

private:
    string name_architecture;
    string name_entity;
	list<string> l_variables;
    //list<Process> instructions;
};

#endif
    
