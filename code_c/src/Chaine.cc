#include "iostream"
#include "string"
#include "stdio.h"
#include "../lib/Chaine.h"
using namespace std;



void Separateur_commentaire(){
	string chaine[] = " Je suis une phrase j'aimerai bien etre decoupe -- coucou"; 
	int i; 
	for (i=0; chaine[i]<j;i++)
	{
		if(chaine[i]=='-'&& chaine[i+1]=='-')
		{
			chaine.substr(0,i);
			j = chaine.size(i)
		}
	}	

}




void Separateur_espace(){

	char chaine[]="Je suis une phrase j'aimerai bien etre decoupe -- coucou";
int i;
	for(i=0;chaine[i]!='\0';i++)
	{
   	 	if(chaine[i]!=' ')
    		{
         		printf("%c",chaine[i]);
     		}
    		 else printf("\n");
	}
}
