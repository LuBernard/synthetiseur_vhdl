#include "iostream"
#include "string"
#include "stdio.h"
#include "../lib/Chaine.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////////
///////////////////Fonction qui supprime les commentaires/////////////////////
//////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////
/////////////Fonction qui transforme les majuscules en minuscules/////////////
//////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

list<string> Separateur_espace(list<string> my_list){
int i = 0;
int j = 0;
list<string>::iterator iterrator_of_my_list = my_list.begin();
list <string> list_inter;
string sentence;
string sentenceInter;

for(iterrator_of_my_list = my_list.begin() ; iterrator_of_my_list != my_list.end() ; ++iterrator_of_my_list)
	{ 
	sentence = *iterrator_of_my_list;
	j = 0;
		for (i=0; i<sentence.size();i++)
		{
   			if(sentence[i]==' ')
    			{
				sentenceInter = sentence.substr(j,i-j);
				list_inter.push_back(sentenceInter);
				j = i+1;
	
     			}
			else if(sentence[i]!=' ' && i==sentence.size()-1)
			{
				sentenceInter = sentence.substr(j,i-1);
				list_inter.push_back(sentenceInter);
				
			}
		}	
	
	}
	return list_inter;
}





list<string> Separateur_tabulation(list<string> my_list){
int i = 0;
int j = 0;
list<string>::iterator iterrator_of_my_list = my_list.begin();
list <string> list_inter;
string sentence;
string sentenceInter;

for(iterrator_of_my_list = my_list.begin() ; iterrator_of_my_list != my_list.end() ; ++iterrator_of_my_list)
	{ 
	sentence = *iterrator_of_my_list;
	j = 0;
		for (i=0; i<sentence.size();i++)
		{
   			if(sentence[i]== 9)
    			{
				sentenceInter = sentence.substr(j,i-j);
				list_inter.push_back(sentenceInter);
				j = i+1;
	
     			}
			if(sentence[i]!= 9 && i==sentence.size()-1)
			{
				sentenceInter = sentence.substr(j,i-1);
				list_inter.push_back(sentenceInter);
				
			}
		}	
	
	}
	return list_inter;
}





