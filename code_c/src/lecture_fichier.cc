#include "../lib/lecture_fichier.h"
using namespace std;
//////////////////////////////////////////////////////////////////////////////
////////////////////////////Ouverture fichier VHDL////////////////////////////
//////////////////////////////////////////////////////////////////////////////
list<string> lecture_fichier(string nom)
{
	list<string> my_list;
	list<string>::iterator iterrator_of_my_list = my_list.begin();

        ifstream fichier("../../vhdl/test_bench/test_line.txt");  // on ouvre en lecture
 
        if(fichier)  // si l'ouverture a fonctionné
        {
		cout << "je suis rentre dans le fichier" <<endl;
                string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue

		while(getline(fichier, contenu))  // tant que l'on peut mettre la ligne dans "contenu"

	       	{
			//printf("je suis rentre dans le while\n");
			my_list.push_back(contenu);
		        //cout << contenu;  // on affiche la ligne

	       	}
		fichier.close();
	cout<<my_list.size()<<endl;

	for(iterrator_of_my_list = my_list.begin() ; iterrator_of_my_list != my_list.end() ; ++iterrator_of_my_list)
	{
		//printf("je suis rentre dans le while\n");
		cout << *iterrator_of_my_list <<endl;
	}


        }

		
	return my_list;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
///////////////////////Ouverture fichier Mots clefs///////////////////////////
//////////////////////////////////////////////////////////////////////////////
list<string> lecture_mots_clefs(string nom)
{
	list<string> my_list;
	list<string>::iterator iterrator_of_my_list = my_list.begin();

        ifstream fichier("../../vhdl/Mots_clefs/.txt");  // on ouvre en lecture
 
        if(fichier)  // si l'ouverture a fonctionné
        {
		cout << "je suis rentre dans le fichier" <<endl;
                string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue

		while(getline(fichier, contenu))  // tant que l'on peut mettre la ligne dans "contenu"

	       	{
			//printf("je suis rentre dans le while\n");
			my_list.push_back(contenu);
		        //cout << contenu;  // on affiche la ligne

	       	}
		fichier.close();
	cout<<my_list.size()<<endl;

	for(iterrator_of_my_list = my_list.begin() ; iterrator_of_my_list != my_list.end() ; ++iterrator_of_my_list)
	{
		//printf("je suis rentre dans le while\n");
		cout << *iterrator_of_my_list <<endl;
	}


        }

		
	return my_list;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
/////////////////////Ouverture fichier opérateurs/////////////////////////////
//////////////////////////////////////////////////////////////////////////////

list<string> lecture_mots_operateurs(string nom)
{
	list<string> my_list;
	list<string>::iterator iterrator_of_my_list = my_list.begin();

        ifstream fichier("../../vhdl/Mots_operateurs/.txt");  // on ouvre en lecture
 
        if(fichier)  // si l'ouverture a fonctionné
        {
		cout << "je suis rentre dans le fichier" <<endl;
                string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue

		while(getline(fichier, contenu))  // tant que l'on peut mettre la ligne dans "contenu"

	       	{
			//printf("je suis rentre dans le while\n");
			my_list.push_back(contenu);
		        //cout << contenu;  // on affiche la ligne

	       	}
		fichier.close();
	cout<<my_list.size()<<endl;

	for(iterrator_of_my_list = my_list.begin() ; iterrator_of_my_list != my_list.end() ; ++iterrator_of_my_list)
	{
		//printf("je suis rentre dans le while\n");
		cout << *iterrator_of_my_list <<endl;
	}


        }

		
	return my_list;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////



