#include "iostream"
#include "string"
#include "stdio.h"
#include <list>
#include "Mot.h"
#include "Entity.h"
#include "Signal.h"
using namespace std;


 list<Entity> VerifSyntaxe_Entity(list<Mot> my_list_mot, list<Entity> list_entity);
 int VerifSyntaxe_Signal(list<Mot> my_list_mot, int iPlace);
 int VerifSyntaxe_Library(list<Mot> my_list_mot);
 int VerifSyntaxe_Use(list<Mot> my_list_mot);
 int VerifSyntaxe_Architecture(list<Mot> my_list_mot);
 int VerifSyntaxe_Type(list<Mot> my_list_mot);
 int VerifSyntaxe_Component(list<Mot> my_list_mot);
