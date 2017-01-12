#include "../lib/Node.h"
#include "../lib/Mot.h"
#include "../lib/Entity.h"
#include "../lib/Chaine.h"
#include "../lib/lecture_fichier.h"
#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	list<string> l;
	list<string> linter;
	list<string> linter1;
	list<string> lfinal;
	list<string>::iterator iterrator_of_linter = linter.begin();
	list<string>::iterator iterrator_of_linter1 = linter1.begin();
	list<string>::iterator iterrator_of_lfinal = lfinal.begin();
	string chemin = "../../vhdl/test_line.txt";
	l = lecture_fichier(chemin);


	linter = Minuscule(l);
	
	for(iterrator_of_linter = linter.begin() ; iterrator_of_linter != linter.end() ; ++iterrator_of_linter)
	{
		cout << *iterrator_of_linter <<endl;
	}
	/*linter1 = Minuscule(linter);
	
	for(iterrator_of_linter1 = linter1.begin() ; iterrator_of_linter1 != linter1.end() ; ++iterrator_of_linter1)
	{
		cout << *iterrator_of_linter1 <<endl;
	}*/

	//linter1 = Separateur_tabulation(linter);
	
	/*for(iterrator_of_linter1 = linter1.begin() ; iterrator_of_linter1 != linter1.end() ; ++iterrator_of_linter1)
	{
		cout << *iterrator_of_linter1 <<endl;
	}*/

	/*lfinal = Minuscule(linter);
	
	for(iterrator_of_lfinal = lfinal.begin() ; iterrator_of_lfinal != lfinal.end() ; ++iterrator_of_lfinal)
	{
		cout << *iterrator_of_lfinal <<endl;
	}*/	
	


}
