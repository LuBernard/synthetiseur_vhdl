#include "iostream"
#include "string"
#include "stdio.h"
#include "../lib/Chaine.h"
#include "../lib/Mot.h"
#include "../lib/lecture_fichier.h"
using namespace std;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////fonction suppression commentaire/////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
list<string> Separateur_commentaire(list<string> my_list){
int i = 0; 
list<string>::iterator iterrator_of_my_list = my_list.begin();
list <string> list_inter; 
string sentence;
for(iterrator_of_my_list = my_list.begin() ; iterrator_of_my_list != my_list.end() ; ++iterrator_of_my_list)
	{
	sentence = *iterrator_of_my_list;
		for (i=0; i<sentence.size();i++)
		{
			if((sentence[i]=='-' ) && (sentence[i+1]=='-'))
			{
				sentence = sentence.substr(0,i);
				i = sentence.size();
			}
		}
	list_inter.push_back(sentence);
	}	
	return list_inter;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////fonction separateur lexemes///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

list<string> Separateur(list<string> my_list, char a){
int i = 0;
int j = 0;
list<string>::iterator iterrator_of_my_list = my_list.begin();
list <string> list_inter;
list <string> list_inter2;
string sentence;
string sentenceInter;

//cout<<a<<endl;

for(iterrator_of_my_list = my_list.begin() ; iterrator_of_my_list != my_list.end() ; ++iterrator_of_my_list)
	{ 
	sentence = *iterrator_of_my_list;
	j = 0;

		for (i=0; i<sentence.size();i++)
		{
   			if(sentence[i]==a && i ==j)
    			{
				sentenceInter = sentence[i];
				list_inter.push_back(sentenceInter);
				j = i+1;
	
     			}
			else if(sentence[i]==a && i!=j)
			{
				sentenceInter = sentence.substr(j,i-j);
				list_inter.push_back(sentenceInter);
				sentenceInter = sentence[i];
				list_inter.push_back(sentenceInter);
				j=i+1;		
			}
			else if (sentence.find(a,0)==string::npos)
			{
				list_inter.push_back(sentence);
				i = sentence.size()-1;
			}
			else if (sentence[i]!=a && i == sentence.size()-1)
			{
				sentenceInter = sentence.substr(j,i-j+1);
				list_inter.push_back(sentenceInter);
			}

		}	
	
	}
return list_inter;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////fonction suppression des lignes vides/////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

list<string> SuppLignesVides(list<string> list_inter){
int i = 0;
int j = 0;
list <string> list_inter2;
string sentence;
string sentenceInter;


list<string>::iterator iterrator_of_list_inter = list_inter.begin();

for(iterrator_of_list_inter = list_inter.begin() ; iterrator_of_list_inter != list_inter.end() ; ++iterrator_of_list_inter)
	{
	sentenceInter = *iterrator_of_list_inter;
		if (sentenceInter[0] != 9 && sentenceInter[0] != 32 && sentenceInter[0] != 0)
		{
			list_inter2.push_back(*iterrator_of_list_inter);
		}
	}
return list_inter2;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Fonction qui transforme les majuscules en minuscules//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
list<string> Minuscule(list<string> my_list){
	int i = 0;
	list<string>::iterator iterrator_of_my_list = my_list.begin();
	list <string> list_inter;
	string sentence;
	string sentenceInter;

	for(iterrator_of_my_list = my_list.begin() ; iterrator_of_my_list != my_list.end() ; ++iterrator_of_my_list)
{
		sentence = *iterrator_of_my_list;
		sentenceInter = *iterrator_of_my_list;
		for (i=0; i<sentence.size();i++)
		{
   			if(sentence[i]>= 65 && sentence[i] <= 90)
    			{
				sentenceInter[i] = sentence[i] + 32;
				
			}
		}
	list_inter.push_back(sentenceInter);
	}	
	return list_inter;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
////////////////////Fonctions de la classe Mot/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

list<Mot> transfoStringMot(list<string> my_list)
{	list<Mot> listMot;
	list<string>::iterator iterrator_of_my_list = my_list.begin();
	
	string contenu;
	int i = 0;

	for(iterrator_of_my_list = my_list.begin(); iterrator_of_my_list != my_list.end(); iterrator_of_my_list ++)
	{
	i ++;
	ifstream fichier("../../vhdl/test_bench/Mots_clefs.txt");
		/*if ( file ) 
		{ 
			int lines = std::count( 
		 	std::istreambuf_iterator<char>( file ), 
		 	std::istreambuf_iterator<char>(), 
		 	'\n' ); 
		} */
		if (fichier)
		{
			string sentence = *iterrator_of_my_list;
			if (sentence.size() == 1) 
			{
				if (sentence[0] <97 || sentence[0]>122)
				{
					
					if (sentence [0]>47 && sentence[0]<57)
					{
						listMot.push_back(Mot(sentence, "etiquette", i));
					}
					else
					{
						listMot.push_back(Mot(sentence, "separateur", i));
					}
				}
				else 
				{
					listMot.push_back(Mot(sentence, "etiquette", i));
				}
			}
			else
			{
				int j = 0;
				while(getline(fichier, contenu))  // tant que l'on peut mettre la ligne dans "contenu"
				{

					if (sentence==contenu)
					{
						listMot.push_back(Mot(sentence, "mot clef",i));
						j = 1;
					}
					else if (sentence != contenu && contenu == "xox" && j==0)//dernier mot du fichier Mots_clefs.txt, dans notre cas xox
					{
						listMot.push_back(Mot(sentence, "etiquette",i));
					}
				}
			}
		}
	fichier.close();
	}
	return listMot;
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


