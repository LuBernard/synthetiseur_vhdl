#include "../lib/Node.h"
#include "../lib/Mot.h"
#include "../lib/VerifSyntaxique.h"
#include "../lib/Chaine.h"
#include "../lib/lecture_fichier.h"
#include "../lib/Entity.h"
#include "../lib/Librairy.h"
#include "../lib/Architecture.h"
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
    bool fichier_Non_Vide = 0;
    bool bFinSyntaxe = 0;
	list<string>::iterator iterrator_of_linter = linter.begin();
	list<string>::iterator iterrator_of_linter1 = linter1.begin();
	list<string>::iterator iterrator_of_lfinal = lfinal.begin();
	list<Mot>::iterator iterrator_of_lMot = lMot.begin();

	list<Entity>  list_entity;
	list<Entity>::iterator iterrator_of_list_entity = list_entity.begin();
	list<Signal>  list_signal;
	list<Signal>::iterator iterrator_of_list_siganl = list_signal.begin();
	list<Architecture>  list_archi;
	list<Librairy>  list_librairy;

	ofstream arbre_entity("../../vhdl/test_bench/results/arbre_entity.txt");  //on vide le fichier
        if(arbre_entity)  // si l'ouverture a réussi
        {       	
                arbre_entity.close();  
        }
	ofstream arbre_library("../../vhdl/test_bench/results/arbre_library.txt");  //on vide le fichier
        if(arbre_library)  // si l'ouverture a réussi
        {       	
                arbre_entity.close();  
        }
	
	string chemin = "../../vhdl/test_line.txt";
	l = lecture_fichier(chemin);
	char a[32];
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
	a[15]=46;
	a[16]=47;
	a[17]=58;
	a[18]=59;
	a[19]=60;
	a[20]=61;
	a[21]=62;
	a[22]=63;
	a[23]=91;
	a[24]=92;
	a[25]=93;
	a[26]=94;
	a[27]=96;
	a[28]=123;
	a[29]=124;
	a[30]=125;
	a[31]=126;

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
	
	
	iterrator_of_lMot = lMot.begin();
	while (bFinSyntaxe != 1) {
		fichier_Non_Vide = 1;
		if ((*iterrator_of_lMot).getLexeme() == "library"){
			int placeFinLibrary = VerifSyntaxe_Library(lMot,(*iterrator_of_lMot).getPlace());
			for (int j = (*iterrator_of_lMot).getPlace(); j<placeFinLibrary; j++){
				iterrator_of_lMot++;
			}
		}
		else if ((*iterrator_of_lMot).getLexeme() == "entity"){
			int placeFinEntity = VerifSyntaxe_Entity(lMot,(*iterrator_of_lMot).getPlace(), list_entity);
			for (int j = (*iterrator_of_lMot).getPlace(); j<placeFinEntity; j++){
				iterrator_of_lMot++;
				//cout<<"coucou"<<endl;
			}
		}
		else if ((*iterrator_of_lMot).getLexeme() == "architecture"){
			int placeFinArchitecture = VerifSyntaxe_Architecture(lMot,(*iterrator_of_lMot).getPlace(), list_entity);
			for (int j = (*iterrator_of_lMot).getPlace(); j<placeFinArchitecture; j++){
				iterrator_of_lMot++;
			}

		}
		else if ((*iterrator_of_lMot).getLexeme() == ";") {
			iterrator_of_lMot++;
			if (((*iterrator_of_lMot).getLexeme() != "library")&&((*iterrator_of_lMot).getLexeme() != "entity")&&((*iterrator_of_lMot).getLexeme() != "architecture")) {
				bFinSyntaxe = 1;
			}
			else {
				bFinSyntaxe = 0;
			}
		}
		else {
		cout<<"Erreur debut programme"<<endl;
		}
	}
	
	if (fichier_Non_Vide == 0) {
	
		cout<<"le fichier est vide"<<endl;
	}
	

///////////////////////////////////////////////////////////////////////////////////////

	//aficher_list_entity(list_entity);
}
