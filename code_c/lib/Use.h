#include <iostream>
#include <string>
#include <vector> 
#include "Node.h"

/////////////////////////////////////////////////////////////////////////////
//
// Use - classe de base pour un use.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _USE_H_
#define _USE_H_

class Use
{
public:
  // Constructeurs/destructeur
  Use () { }
  Use (std::string name): _nameLib (name) { }
  ~Use () { std::cout << "destroying " << _nameLib << std::endl; }
  void setPaquet(std::string Paquet) { _namePaquet = Paquet;}
  void setEnd(std::string end) { _nameEnd = end;}
 
private:
    std::string _nameLib;
    std::string _namePaquet;
    std::string _nameEnd;
};

#endif
  