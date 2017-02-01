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
  Librairy (std::string name): name_lib (name) { }
  ~Librairy () {/* std::cout << "destroying " << _nameLib << std::endl;*/}
	void addPaquet(string Paquet) { list_paquet.push_back(Paquet);}
	list<string> get_list_pacquet(){return list_paquet;}
	
	void set_pos_end(int end) { pos_end = end;}
	int get_pos_end() { return pos_end;}

	void set_name_lib(string name) { name_lib = name;}
	string get_name_lib() { return name_lib;}
 
private:
    string name_lib;
    list<string> list_paquet;
    int pos_end;
};

#endif
  
    
