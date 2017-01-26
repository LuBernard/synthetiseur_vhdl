#include "iostream"
#include "string"
#include "stdio.h"
#include <list>
#include "Mot.h"
using namespace std;


list<string> Separateur_commentaire(list<string>);
list<string> Separateur(list<string>, char a);
list<string> SuppLignesVides(list<string>);
list<string> Minuscule(list<string>);
list<Mot> transfoStringMot(list<string> my_list);
void erreurOrthographe(list<Mot> my_list);
