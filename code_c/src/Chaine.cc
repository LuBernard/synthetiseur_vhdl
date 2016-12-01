#include "iostream"
#include "string"
#include "stdio.h"
#include "../lib/Chaine.h"
using namespace std;



void Separateur_commentaire(){
int i; 
int j;
string chaine = "hello bel homme -- coucou";
//list<string>::iterator iterrator_of_my_list = l.begin();
string sentence;
//for(iterrator_of_my_list = my_list.begin() ; iterrator_of_my_list != my_list.end() ; ++iterrator_of_my_list)
	//{
		for (i=0; i<chaine.size();i++)
		{
			if((chaine[i]=='-' ) && (chaine[i+1]=='-'))
			{
				sentence = chaine.substr(0,i);
				i = chaine.size();
			}
			printf("%c",chaine[i]);
		}
	//}	
	//return l;
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
