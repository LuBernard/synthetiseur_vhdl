#include "../lib/Mot.h"
#include "../lib/lecture_fichier.h"
///////////////////////////////////////////////////////////////////////////////
////////////////////Fonctions de la classe Mot/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/*
list<Mot> Mot::transfoStringMot(list<string> my_list)
{	list<Mot> listMot;
	list<string>::iterator iterrator_of_my_list = my_list.begin();
	ifstream fichier("../../vhdl/test_bench/Mots_clefs.txt");
	string contenu;
	int i = 0;

	for(iterrator_of_my_list = my_list.begin(); iterrator_of_my_list != my_list.end(); iterrator_of_my_list ++)
	{
	i ++;
		if (fichier)
		{
			string sentence = *iterrator_of_my_list;
			if (sentence.size() == 1 && sentence[0] <97 && sentence[0]>122)
			{
				listMot.push_back(Mot(sentence, "separateur", i));
			}
			while(getline(fichier, contenu))  // tant que l'on peut mettre la ligne dans "contenu"
			{
				if (*iterrator_of_my_list==contenu)
				{
					listMot.push_back(Mot(sentence, "mot clef",i));
				}
				else
				{
					listMot.push_back(Mot(sentence, "etiquette",i));
				}
			}
		}
	}
	return listMot;
}


void Mot::erreurOrthographe(list<Mot> my_list)
{

	list<Mot>::iterator iterrator_of_my_list = my_list.begin();
	string sentence = (*iterrator_of_my_list).getLexeme();

	for(iterrator_of_my_list = my_list.begin(); iterrator_of_my_list != my_list.end(); iterrator_of_my_list ++)
	{
		sentence = (*iterrator_of_my_list).getLexeme();
		
		//verification qu'on ne commence pas par un _
		if (sentence[0] == 95)
		{
			cout<<"erreur, le lexeme a la position : "<< (*iterrator_of_my_list).getPlace() <<"commence par un _"<<endl;
			exit(1);
		}

		for (int i =0; i<sentence.size()-1;i++)
		{
			//test si on a un @, un $ ou un  dans le code
			if(sentence[i] == 64 || sentence[i] == 36 || sentence[i] > 127 )
			{
				cout<<"erreur, le lexeme a la position : "<< (*iterrator_of_my_list).getPlace() <<"contient un :"<< sentence[i]<<endl;
				exit(1);
			}
		}
	}
}
*/

