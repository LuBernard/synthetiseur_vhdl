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
  Signal (std::string name): _name (name) { }
  ~Signal () { std::cout << "destroying " << _name << std::endl; }
  void setType(std::string type) { _type = type;}
  void setDirection(std::string io) { _IO = io;}
 
private:
    std::string _name;
    std::string _type;
    std::string _IO;
};

#endif
  