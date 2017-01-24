#include <string>
#include <iostream>
#include "Entity.h"
#include "Architecture.h"
#include "Librairy.h"
#include "Mot.h"
#include <list>

using namespace std;


/////////////////////////////////////////////////////////////////////////////
//
// fsm - classe de base pour une fsm.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _FSM_H_
#define _FSM_H_

class fsm
{
public:
  // Constructeurs/destructeur
  fsm () { }
  fsm (list<Mot> liste): _liste (liste) { } 
  ~fsm () { }
  void processList();
  list<Mot> add_entity(std::list<Mot> listMot);
  list<Mot> add_librairy(std::list<Mot> listMot);

private:
    list<Mot> _liste;
    list<Entity> _entities;
    list<Architecture> _architectures;
	list<Librairy> _librairies;

};

#endif
    
