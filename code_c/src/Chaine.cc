#include "iostream"
#include "string"
#include "stdio.h"
#include "../lib/Chaine.h"
using namespace std;



list<string> Separateur_commentaire(list<string> my_list){
int i; 
int j;
//string chaine = "hello bel homme -- coucou";
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
			cout<<sentence<<endl;
		}
	list_inter.push_back(sentence);
	}	
	return list_inter;
}




void Separateur_espace(){
int i;
string chaine = "hello bel homme -- coucou";
//list<string>::iterator iterrator_of_my_list = l.begin();
	//for(iterrator_of_my_list = my_list.begin() ; iterrator_of_my_list != my_list.end() ; ++iterrator_of_my_list)
	//{
		for(i=0;chaine[i]!='\0';i++)
		{
   			if(chaine[i]!=' ')
    			{
         			printf("%c",chaine[i]);
     			}
    		 	else printf("\n");
		}
	//}
	//return l;
}
