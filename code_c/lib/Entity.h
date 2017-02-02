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

	//int get_place_fin_entity(){return place_fin_entity;}
	//void set_place_fin_entity(int f_entity){place_fin_entity = f_entity;}
	void set_place_fin_signal(int f_signal){place_fin_signal = f_signal;}
	int get_place_fin_signal(){return place_fin_signal;}

	string get_name_entity(){return name_entity;}

	void set_numero_entity(int num_entity){numero_entity = num_entity;}
	int get_numero_entity(){return numero_entity;}

	list<Signal> get_l_signal(){return l_signal;}
	list<Signal> set_l_signal(list<Signal> list_signal){l_signal = list_signal;}	

protected:
    	string name_entity;
    	list<Signal>  l_signal;
	int numero_entity;
	int place_fin_signal;
};


#endif
  
    
