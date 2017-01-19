#include "../lib/Mot.h"

///////////////////////////////////////////////////////////////////////////////
////////////////////Fonctions de la classe Mot/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

list<Mot> transfoStringMot(list<string> my_list)
{
	
}

void erreurOrthographe(list<Mot> my_list)
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
