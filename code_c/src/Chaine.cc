#include "iostream"
#include "string"
#include "stdio.h"
#include "../lib/Chaine.h"
using namespace std;



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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


list<string> Separateur_espace(list<string> my_list){
int i = 0;
int j = 0;
list<string>::iterator iterrator_of_my_list = my_list.begin();
list <string> list_inter;
list <string> list_inter2;
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
			else if(sentence[i]!=' ' && i==sentence.size()-1 && j==0)
			{
				sentenceInter = sentence.substr(j,i+1);
				list_inter.push_back(sentenceInter);
				
			}
			else if(sentence[i]!=' ' && i==sentence.size()-1)
			{
				sentenceInter = sentence.substr(j,i+1);
				list_inter.push_back(sentenceInter);
				
			}

		}	
	
	}
list<string>::iterator iterrator_of_list_inter = list_inter.begin();

for(iterrator_of_list_inter = list_inter.begin() ; iterrator_of_list_inter != list_inter.end() ; ++iterrator_of_list_inter)
	{
	sentenceInter = *iterrator_of_list_inter;
		if (sentenceInter[0] != 32 && sentenceInter[0] != 0)
		{
			//cout<<sentenceInter<<endl;
			list_inter2.push_back(*iterrator_of_list_inter);
		}
	}
return list_inter2;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

list<string> Separateur_tabulation(list<string> my_list){
int i = 0;
int j = 0;
list<string>::iterator iterrator_of_my_list = my_list.begin();
list <string> list_inter;
list <string> list_inter2;
string sentence;
string sentenceInter;

for(iterrator_of_my_list = my_list.begin() ; iterrator_of_my_list != my_list.end() ; ++iterrator_of_my_list)
	{ 
	sentence = *iterrator_of_my_list;
	j = 0;
		for (i=0; i<sentence.size();i++)
		{
   			if(sentence[i]==9)
    			{
				sentenceInter = sentence.substr(j,i-j);
				list_inter.push_back(sentenceInter);
				j = i+1;
	
     			}
			else if(sentence[i]!=9 && i==sentence.size()-1 && j==0)
			{
				sentenceInter = sentence.substr(j,i+1);
				list_inter.push_back(sentenceInter);
				
			}
			else if(sentence[i]!=9 && i==sentence.size()-1)
			{
				sentenceInter = sentence.substr(j,i+1);
				list_inter.push_back(sentenceInter);
				
			}

		}	
	
	}
list<string>::iterator iterrator_of_list_inter = list_inter.begin();

for(iterrator_of_list_inter = list_inter.begin() ; iterrator_of_list_inter != list_inter.end() ; ++iterrator_of_list_inter)
	{
	sentenceInter = *iterrator_of_list_inter;
		if (sentenceInter[0] != 9 && sentenceInter[0] != 0)
		{
			//cout<<sentenceInter<<endl;
			list_inter2.push_back(*iterrator_of_list_inter);
		}
	}
return list_inter2;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/*
list<string> Separateur_tabulation(list<string> my_list){
int i = 0;
int j = 0;
list<string>::iterator iterrator_of_my_list = my_list.begin();
list <string> list_inter;
list <string> list_inter2;
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
*/
///////////////////////////////////////////////////////////////////////////////////////////////

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
/*list<string>::iterator iterrator_of_list_inter = list_inter.begin();

for(iterrator_of_list_inter = list_inter.begin() ; iterrator_of_list_inter != list_inter.end() ; ++iterrator_of_list_inter)
	{
	sentenceInter = *iterrator_of_list_inter;
		if (sentenceInter[0] != 9 && sentenceInter[0] != 32 && sentenceInter[0] != 0)
		{
			cout<<sentenceInter<<endl;
			list_inter2.push_back(*iterrator_of_list_inter);
		}
	}*/
return list_inter;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



list<string> SuppLignesVides(list<string> list_inter){
int i = 0;
int j = 0;
list <string> list_inter2;
string sentence;
string sentenceInter;

//cout<<a<<endl;


list<string>::iterator iterrator_of_list_inter = list_inter.begin();

for(iterrator_of_list_inter = list_inter.begin() ; iterrator_of_list_inter != list_inter.end() ; ++iterrator_of_list_inter)
	{
	sentenceInter = *iterrator_of_list_inter;
		if (sentenceInter[0] != 9 && sentenceInter[0] != 32 && sentenceInter[0] != 0)
		{
			//cout<<sentenceInter<<endl;
			list_inter2.push_back(*iterrator_of_list_inter);
		}
	}
return list_inter2;
}

