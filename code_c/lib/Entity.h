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
	Entity (string name) {name_entity = name;}
	//~Entity () { cout << "destroying " << name_entity << std::endl; }
	~Entity () {}
	void add_signal(Signal mon_signal){l_signal.push_back(mon_signal);}
	int get_place_fin_entity(){return place_fin_entity;}
	void set_place_fin_entity(int f_entity){place_fin_entity = f_entity;}
	string get_name(){return name_entity;}

protected:
    	string name_entity;
    	list<Signal>  l_signal;
	int place_fin_entity;
};

#endif
  
    
