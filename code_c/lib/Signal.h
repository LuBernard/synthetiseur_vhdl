#include <iostream>
#include <string>
#include <vector> 
#include "Node.h"
#include <list>

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
	~Signal () { cout << "destroying " << name_signal << std::endl; }
 
private:
	string name_signal;
	string type_signal;
	string IO_signal;
};

#endif
  
