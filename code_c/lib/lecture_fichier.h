#ifndef LECTURE_FICHIER_H_INCLUDED
#define LECTURE_FICHIER_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

list<string> lecture_fichier(string nom);
list<string> lecture_mots_clefs(string nom);
list<string> lecture_mots_operateurs(string nom);
 
#endif 



