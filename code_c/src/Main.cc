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
	list<string> lfinal;
	list<string>::iterator iterrator_of_linter = linter.begin();
	string chemin = "../../vhdl/test_line.txt";
	l = lecture_fichier(chemin);


	linter = Separateur_commentaire(l);
	
	for(iterrator_of_linter = linter.begin() ; iterrator_of_linter != linter.end() ; ++iterrator_of_linter)
	{
		cout << *iterrator_of_linter <<endl;
	}

	//Separateur_espace();
	
		
	


}
