/////////////////////////////////////////////////////////////////////////////
//
// Node - noeud d'une liste doublement chaînée.
//
/////////////////////////////////////////////////////////////////////////////
#ifndef _NODE_H_
#define _NODE_H_

#include <stddef.h>

class Node
{
public:
  // Constructeur/destructeur
  Node ()
    : _nextNode (NULL), _prevNode (NULL), _isManager (false) { }
  virtual ~Node ();

public:
  // Interface publique
  bool isLastNode () { return (_nextNode ? false : true); }//test si la node est la last node
  bool isFirstNode () { return !isLastNode (); }//test si la node est la première node
  bool isAlone () { return ((_prevNode && _nextNode) ? false : true); }//test si la node est seule
  bool isManager () { return _isManager; }//Définit une node comme étant la manger

  void setManager (bool manager) { _isManager = manager; }
  void attach (Node *node);
  void unLink ();

protected:
  // Variables membres
  Node *_nextNode;
  Node *_prevNode;

bool _isManager;
};

#endif
