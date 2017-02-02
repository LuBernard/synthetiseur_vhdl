#include "iostream"
#include "string"
#include "stdio.h"
#include "Entity.h"
#include "Signal.h"
#include "Architecture.h"
#include <list>
#include "Mot.h"
using namespace std;


 int VerifSyntaxe_Entity(list<Mot> my_list_mot, int iPlace, list<Entity>  &l_entity);
 int VerifSyntaxe_Port(list<Mot> my_list_mot, int iPlace, int num_entity, list<Entity>  &l_entity);
 Entity VerifSyntaxe_Port2(list<Mot> my_list_mot, int iPlace, int num_entity, list<Entity>  l_entity);
 int VerifSyntaxe_PortArchi(list<Mot> my_list_mot, int iPlace);
 int VerifSyntaxe_Library(list<Mot> my_list_mot, int iPlace);
 int VerifSyntaxe_Use(list<Mot> my_list_mot, int iPlace);
 int VerifSyntaxe_Architecture(list<Mot> my_list_mot, int iPlace, list<Entity>  &l_entity);
 int VerifSyntaxe_Type(list<Mot> my_list_mot, int iPlace);
 int VerifSyntaxe_Component(list<Mot> my_list_mot, int iPlace, list<Entity>  &l_entity);
 int VerifSyntaxe_Signal(list<Mot> my_list_mot, int iPlace);
 int VerifSyntaxe_Variable(list<Mot> my_list_mot, int iPlace);
 int VerifSyntaxe_Process(list<Mot> my_list_mot, int iPlace);

void aficher_list_entity(list<Entity>  l_entity);
