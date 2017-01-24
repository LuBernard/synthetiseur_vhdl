#include "../lib/Node.h"
#include "../lib/Mot.h"
#include "../lib/VerifSyntaxique.h"
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
	list<Mot> lMot;
	list<string>::iterator iterrator_of_linter = linter.begin();
	list<string>::iterator iterrator_of_linter1 = linter1.begin();
	list<string>::iterator iterrator_of_lfinal = lfinal.begin();
	list<Mot>::iterator iterrator_of_lMot = lMot.begin();
	string chemin = "../../vhdl/test_line.txt";
	l = lecture_fichier(chemin);
	char a[31];
	a[0]=9;
	a[1]=32;
	a[2]=33;
	a[3]=34;
	a[4]=35;
	a[5]=36;
	a[6]=37;
	a[7]=38;
	a[8]=39;
	a[9]=40;
	a[10]=41;
	a[11]=42;
	a[12]=43;
	a[13]=44;
	a[14]=45;
	a[15]=47;
	a[16]=58;
	a[17]=59;
	a[18]=60;
	a[19]=61;
	a[20]=62;
	a[21]=63;
	a[22]=91;
	a[23]=92;
	a[24]=93;
	a[25]=94;
	a[26]=96;
	a[27]=123;
	a[28]=124;
	a[29]=125;
	a[30]=126;

	linter = Separateur_commentaire(l);
	for (int i = 0; i <30;i++)
	{
		linter = Separateur(linter, a[i]);
	}
	linter1 = Minuscule(linter);	
	lfinal = SuppLignesVides(linter1);
	
	
	
	/*for(iterrator_of_lfinal = lfinal.begin() ; iterrator_of_lfinal != lfinal.end() ; ++iterrator_of_lfinal)
	{
		cout << *iterrator_of_lfinal <<endl;
	}*/
	

	lMot = transfoStringMot(lfinal);
	
	
	for(iterrator_of_lMot = lMot.begin() ; iterrator_of_lMot != lMot.end() ; ++iterrator_of_lMot)
	{
		cout << (*iterrator_of_lMot).getLexeme() << " "<<(*iterrator_of_lMot).getCarac()<<" "<<(*iterrator_of_lMot).getPlace() <<endl;
	}

	erreurOrthographe(lMot);

	int placeFinEntity = TestEntity(lMot);
	cout << placeFinEntity << endl;
}
