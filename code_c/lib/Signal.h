#include <iostream>
#include <string>
#include <vector> 
#include "Node.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//
// Signal - classe de base pour une Signal.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _Signal_H_
#define _Signal_H_

class Signal
{
public:
  	// Constructeurs/destructeur
	Signal () { }
	Signal (string name, string type, string IO)
	{
		name_signal = name;
		type_signal = type;
		IO_signal = IO;
	}
	~Signal () {}
	void set_name(string name){name_signal = name;}
	void set_type(string type){type_signal = type;}
	void set_IO(string IO){IO_signal = IO;}
	string get_name(){return name_signal;}
	string get_type(){return type_signal;}
	string get_IO(){return IO_signal;}
private:
	string name_signal;
	string type_signal;
	string IO_signal;
};

#endif
  
