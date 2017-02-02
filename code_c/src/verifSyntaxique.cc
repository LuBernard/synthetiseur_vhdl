#include "../lib/VerifSyntaxique.h"
#include <list>
#include <fstream>
 
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int VerifSyntaxe_Entity(list<Mot> my_list_mot, int iPos, list<Entity> &l_entity){

    list<Mot>::iterator it = my_list_mot.begin(); 
	list<Entity>::reverse_iterator reverse_itEntity = l_entity.rbegin();
	list<Entity>::iterator itEntity = l_entity.begin();

	Entity ent;
    Mot sentence;
    sentence = *it;
    string nom_entity_debut;
    string nom_entity_fin;
    int iPlaceReturn;
	
  	for (int j = sentence.getPlace(); j<iPos; j++){
		it++;
		sentence = *it;
	}
    
    if (sentence.getLexeme() == "entity"){
    	it++;
    	sentence = *it;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :  "<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getCarac() == "etiquette"){
    	nom_entity_debut = sentence.getLexeme();
    	it++;
    	sentence = *it;
	//cout<<"nom_entity_debut : "<<nom_entity_debut<<endl;
	l_entity.push_back(Entity(nom_entity_debut));
	itEntity++;	

	//cout<<"size l_entity : "<<l_entity.size()<<endl;
	//cout<<"name entity : "<<(*itEntity).get_name()<<endl;
	
	(*itEntity).set_numero_entity(l_entity.size());
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == "is"){
    	it++;
    	sentence = *it;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);    
	}
    if (sentence.getLexeme() == "port"){
    	it++;
    	sentence = *it;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getLexeme() == "("){


    		ent = VerifSyntaxe_Port2(my_list_mot,sentence.getPlace(), (*itEntity).get_numero_entity(), l_entity);
		list<Signal> s = ent.get_l_signal();
		list<Signal>::iterator its = s.begin();
		for (its;its != s.end() ;its++){
			(*itEntity).add_signal((*its));
		}
		/*list<Signal> ls = (*itEntity).get_l_signal();
		for (list<Signal>::iterator its = ls.begin(); its !=ls.end();its++)
		{
			cout<<(*its).get_name()<<" "<< (*its).get_type()<<" "<<(*its).get_IO()<<" "<<endl;
		}*/
	
		int iPlaceReturn = ent.get_place_fin_signal();
    		for (int j = sentence.getPlace(); j<iPlaceReturn; j++){
				it++;
				sentence = *it;
			}
		
		
    		
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getLexeme() == ")"){
    	it++;
    	sentence = *it;
	
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getLexeme() == ";"){
    	it++;
    	sentence = *it;    	
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getLexeme() == "end"){
    	it++;
    	sentence = *it;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getCarac() == "etiquette"){

    	nom_entity_fin = sentence.getLexeme();
    	if (nom_entity_debut == nom_entity_fin) {
    		it++;
    		sentence = *it;
    	}
    	else {
    		cout<<"erreur 	au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);
    	}
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getLexeme() == ";"){
		it++;
    		//sentence = *it;
		
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
	it--;

	////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////generation arbre entity/////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////

	//cout<<"name entity : "<<(*itEntity).get_name_entity()<<endl;

	list<Signal> ls = (*itEntity).get_l_signal();
	ofstream arbre_entity("../../vhdl/test_bench/results/arbre_entity.txt", ios::app);  // on ouvre le fichier en lecture
 
        if(arbre_entity)  // si l'ouverture a réussi
        {       
            	arbre_entity<<(*itEntity).get_name_entity()<<endl;
		for (list<Signal>::iterator its = ls.begin(); its !=ls.end();its++)
		{
			arbre_entity<<(*its).get_name()<<" "<< (*its).get_type()<<" "<<(*its).get_IO()<<" "<<endl;
		}
                arbre_entity.close();  
        }



	return sentence.getPlace();
 }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int VerifSyntaxe_Port(list<Mot> my_list_mot,int iPlace, int num_entity, list<Entity>  &l_entity){
    
    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string nom_signal;
	Signal sig;
	list<Entity>::iterator itEn = l_entity.begin();
	Entity ent = *itEn;
    	for (int k = 0; k<num_entity-1;k++)
	{
		itEn++;
		ent = *itEn;
	}
    for (int j = sentence.getPlace(); j<iPlace; j++){
		it++;
		sentence = *it;
	}	
	do {
		it++;
    	sentence = *it;
		if (sentence.getCarac() == "etiquette"){
			string nom_signal = sentence.getLexeme(); 
			sig.set_name(nom_signal);//ajout de signal
			it++;
    		sentence = *it;
		}
		else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    	if (sentence.getLexeme() == ":"){
			it++;
    		sentence = *it;
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}

    	if (sentence.getLexeme() == "in"||sentence.getLexeme() == "out"){
			it++;
			sig.set_IO(sentence.getLexeme());
    			sentence = *it;
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}   
    	if (sentence.getLexeme() == "bit"){
			it++;
			sig.set_type(sentence.getLexeme());
    		sentence = *it;
		}
		else if (sentence.getLexeme() == "bit_vector"){
			it++;
			sig.set_type(sentence.getLexeme());
    		sentence = *it;
			if (sentence.getLexeme() == "("){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getCarac() == "etiquette"){ //NUMBER PAR LA SUITE 
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getLexeme() == "to"){
				it++;
    			sentence = *it;
			}
    		else if (sentence.getLexeme() == "downto"){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getCarac() == "etiquette"){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
			if (sentence.getLexeme() == ")"){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}
	//On ajoute le signal a la liste de signaux 
	(*itEn).add_signal(sig);
	list<Signal> ls = (*itEn).get_l_signal();
    } 
    while (sentence.getLexeme() == ";");
 return sentence.getPlace();
 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int VerifSyntaxe_Library(list<Mot> my_list_mot, int iPos){
    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string nom_library;
    int iPlaceReturn;
	ofstream arbre_library("../../vhdl/test_bench/results/arbre_library.txt", ios::app);  //on vide le fichier
    for (int j = sentence.getPlace(); j<iPos; j++){
		it++;
		sentence = *it;
	}
	if (sentence.getLexeme() == "library"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
	if (sentence.getCarac() == "etiquette"){
	
        if(arbre_library)  // si l'ouverture a réussi
        {       	
		arbre_library<<"library : "<<sentence.getLexeme()<<endl;
		arbre_library.close(); 
                
        }
		string nom_library = sentence.getLexeme(); 
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == ";"){
    	it++;
    	sentence = *it;
    }
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == "use"){
  		iPlaceReturn = VerifSyntaxe_Use(my_list_mot,sentence.getPlace());
  		for (int j = sentence.getPlace(); j<iPlaceReturn; j++){
			it++;
			sentence = *it;
		}
    	
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
	
	return sentence.getPlace();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int VerifSyntaxe_Use(list<Mot> my_list_mot, int iPlace){
    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string name_library = "";
    for (int j = sentence.getPlace(); j<iPlace; j++){
		it++;
		sentence = *it;
	}
	
	do {
		if (sentence.getLexeme() == "use"){
			it++;
    		sentence = *it;
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
   	 		exit(1);  
   	 	}
    	if (sentence.getCarac() == "etiquette"){
			it++;
    		sentence = *it;
		name_library = sentence.getLexeme();
		

		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);  
   		}    
    	if (sentence.getLexeme() == "."){
			it++;
    		sentence = *it;
		name_library = name_library + sentence.getLexeme();

		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);  
    	}
    	if (sentence.getLexeme() == "all"){
			it++;
    		sentence = *it;
		name_library = name_library + sentence.getLexeme();

		}
		else if (sentence.getCarac() == "etiquette"){
			it++;
    		sentence = *it;	
		name_library = name_library + sentence.getLexeme();
    		if (sentence.getLexeme() == "."){
				it++;
    			sentence = *it;
			name_library = name_library + sentence.getLexeme();

			}
			else {
    			cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    			exit(1);  
    		}
    		if (sentence.getLexeme() == "all"){
				it++;
    			sentence = *it;
			name_library = name_library + sentence.getLexeme();

			}
			else {
    			cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    			exit(1);  
    		}
    		
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);  
    	}    
    	if (sentence.getLexeme() == ";"){
			it++;
    		sentence = *it;

		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);  
    	}    
	}
	while (sentence.getLexeme() == "use");
		it--;
    	sentence = *it;

 return sentence.getPlace();	
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int VerifSyntaxe_Architecture(list<Mot> my_list_mot, int iPos, list<Entity> &l_entity){

    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string nom_architecture;	
    string nom_entity;
    string nom_entityEnd;
    int iPlaceReturn;
	bool cond =0;
    for (int j = sentence.getPlace(); j<iPos; j++){
		it++;
		sentence = *it;
	}
    
    if (sentence.getLexeme() == "architecture"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
	if (sentence.getCarac() == "etiquette"){
        	nom_architecture = sentence.getLexeme();
		it++;
		sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    	}

	
    if (sentence.getLexeme() == "of"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
	if (sentence.getCarac() == "etiquette"){
		nom_entity = sentence.getLexeme();

		
	 	ifstream arbre_entity("../../vhdl/test_bench/results/arbre_entity.txt");  // on ouvre en lecture
		ofstream arbre_archi("../../vhdl/test_bench/results/arbre_archi.txt",ios::app);  // on ouvre en ecriture
		if(arbre_archi)  // si l'ouverture a fonctionné
		{
		        string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
			
			while(getline(arbre_entity, contenu))  // tant que l'on peut mettre la ligne dans "contenu"

		       	{
				cout<<contenu<<endl;
				if (nom_entity == contenu)
				{
					cout<<"cond a 1"<<endl;
					cond = 1;

					if(arbre_archi)  // si l'ouverture a réussi
					{       
						arbre_archi<<"Architecture : "<<nom_architecture<<endl;
						arbre_archi<<"Entitee associee : "<<nom_entity<<endl;
					}
				}
		       	}
		}
		if (cond ==1)
		{
			it++;
			sentence = *it;
		}
		else {
	    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
	    	exit(1);   
	    }
	}

	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == "is"){
        nom_entity = sentence.getLexeme();
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    do {
    	sentence = *it;
		if (sentence.getLexeme() == "type")  {
    		iPlaceReturn = VerifSyntaxe_Type(my_list_mot,sentence.getPlace());
    		for (int j = sentence.getPlace(); j<iPlaceReturn-2; j++){
				it++;
				/*sentence = *it;
				ofstream arbre_archi("../../vhdl/test_bench/results/arbre_archi.txt",ios::app);  //on vide le fichier
				if(arbre_archi)  // si l'ouverture a réussi
				{       
					arbre_archi<<sentence.getLexeme()<<" ";	
					arbre_archi.close();  
				}*/
			}
		it++;
		it++;
    	} 
   		else if (sentence.getLexeme() =="component")  {
    		iPlaceReturn = VerifSyntaxe_Component(my_list_mot,sentence.getPlace(), l_entity);
    		for (int j = sentence.getPlace(); j<iPlaceReturn; j++){
				it++;
			}

    } 
   		else if (sentence.getLexeme() =="signal")  {
    		iPlaceReturn = VerifSyntaxe_Signal(my_list_mot,sentence.getPlace());
    		for (int j = sentence.getPlace(); j<iPlaceReturn; j++){
				it++;
			}
    	} 
   		else if (sentence.getLexeme() =="variable")  {
    		iPlaceReturn = VerifSyntaxe_Variable(my_list_mot,sentence.getPlace());
    		for (int j = sentence.getPlace(); j<iPlaceReturn; j++){
				it++;
			}
    	}
    	else if (sentence.getCarac() != "mot clef"){
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);  
    	
    	}  
    }while ( sentence.getLexeme() != "begin");  
    int k = 0;
	while (sentence.getLexeme() != "architecture") {
    	it++;
		sentence = *it;
		k++;
		if (it==my_list_mot.end()){
			cout<<"Erreur : il n'y a pas de end architecture"<<endl;
			exit(1);
		}
		
    }
    it--;
    sentence = *it;
    if (sentence.getLexeme() == "end"){
        nom_architecture = sentence.getLexeme();
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }    
    if (sentence.getLexeme() == "architecture"){
			it++;
    		sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }     
    if (sentence.getLexeme() == ";"){
        nom_architecture = sentence.getLexeme();
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    } 
		it--;
    	sentence = *it;
	return sentence.getPlace();            
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int VerifSyntaxe_Component(list<Mot> my_list_mot, int iPlace, list<Entity> &l_entity){

	ofstream arbre_archi("../../vhdl/test_bench/results/arbre_archi.txt",ios::app);  //on vide le fichier
    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string nom_component_debut;
    string nom_component_fin;
    int iPlaceReturn;
    
    for (int j = sentence.getPlace(); j<iPlace; j++){
		it++;
		sentence = *it;
	}	
	do {
    
    	if (sentence.getLexeme() == "component"){
    		it++;
		if(arbre_archi)  // si l'ouverture a réussi
		{       
			arbre_archi<<sentence.getLexeme()<<" ";	
		}
    		sentence = *it;
    	}
    	else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :  "<<sentence.getPlace()<<endl;
    		exit(1);
   	 	}	
    	if (sentence.getCarac() == "etiquette"){
    		nom_component_debut = sentence.getLexeme();
    		it++;
		if(arbre_archi)  // si l'ouverture a réussi
		{       
			arbre_archi<<sentence.getLexeme()<<" ";	
		}
    		sentence = *it;
    	}
    	else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}
    	if (sentence.getLexeme() == "is"){
    		it++;
    		sentence = *it;
    	}
    	else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);    
		}
    	if (sentence.getLexeme() == "port"||sentence.getLexeme() == "generic"){
    		it++;
		if(arbre_archi)  // si l'ouverture a réussi
		{       
			arbre_archi<<sentence.getLexeme()<<endl;	
			
		}
    		sentence = *it;
    	}
    	else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);
    	}
    	if (sentence.getLexeme() == "("){
    		iPlaceReturn = VerifSyntaxe_PortArchi(my_list_mot,sentence.getPlace());
    		for (int j = sentence.getPlace(); j<iPlaceReturn; j++){
				it++;
				sentence = *it;
			}
    	
    	}
   	 	else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);
    	}
    	if (sentence.getLexeme() == ")"){
    		it++;
    		sentence = *it;
    	}
    	else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);
    	}
    	if (sentence.getLexeme() == ";"){
    		it++;
    		sentence = *it;    	
    	}
    	else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);
    	}
    	if (sentence.getLexeme() == "end"){
    		it++;
    		sentence = *it;
    	}
   	 	else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);
    	}
    	if (sentence.getLexeme() == "component"){
    		it++;
    		sentence = *it;
    	}
    	else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);
    	}
    	if (sentence.getLexeme() == ";"){
			it++;
    		sentence = *it;
    	}
    	else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);
    	}
    
	} while (sentence.getLexeme() == "component");	
	
	return sentence.getPlace();	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int VerifSyntaxe_Type(list<Mot> my_list_mot, int iPlace){

    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
	ofstream arbre_archi("../../vhdl/test_bench/results/arbre_archi.txt",ios::app);  //on vide le fichier
    for (int j = sentence.getPlace(); j<iPlace; j++){
		it++;
		sentence = *it;
		
	}
    do {
    
    	if (sentence.getLexeme() == "type"){
		it++;
		if(arbre_archi)  // si l'ouverture a réussi
		{       
			arbre_archi<<sentence.getLexeme()<<" ";	
		}
    	sentence = *it;
	}
		else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
   	 	if (sentence.getCarac() == "etiquette"){
		it++;
		if(arbre_archi)  // si l'ouverture a réussi
		{       
			arbre_archi<<sentence.getLexeme()<<" ";	
		}
    	sentence = *it;

	}
		else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    	if (sentence.getLexeme() == "is"){
		it++;
    	sentence = *it;
	}
		else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    	if (sentence.getLexeme() == "("){
    	do{
			it++;
    		sentence = *it;
    		if (sentence.getCarac() == "etiquette"){ //variable 
				it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	 
			}
    			sentence = *it;

		}

		else if (sentence.getLexeme() == "'"||sentence.getLexeme() == " \"" ){
			it++;
			sentence = *it;	
			if (sentence.getCarac() == "etiquette"){ //variable 
				it++;
				if(arbre_archi)  // si l'ouverture a réussi
				{       
					arbre_archi<<sentence.getLexeme()<<" ";	
				}
				sentence = *it;

			}
	    		else {
	    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
	    			exit(1);   
	    		}
	    		if (sentence.getLexeme() == "'"||sentence.getLexeme() == " \"" ){ 
				it++;
	    			sentence = *it;
	    		}
	    		else {
	    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
	    			exit(1);   
	    		}
	}
		else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    		}
    	}while (sentence.getLexeme() == ",");

	if(arbre_archi)  // si l'ouverture a réussi
		{       
			arbre_archi<<endl;	
		}
	}
	else if (sentence.getLexeme() == "array"){
		it++;
		if(arbre_archi)  // si l'ouverture a réussi
		{       
			arbre_archi<<sentence.getLexeme()<<" ";	
		}
    		sentence = *it;

    		if (sentence.getLexeme() == "("){
			it++;
    		sentence = *it;
		}
		else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    		if (sentence.getCarac() == "etiquette"){ //NUMBER PAR LA SUITE 
			it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	
			}
    			sentence = *it;

		}
		else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    	}
    		if (sentence.getLexeme() == "to"){
			it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	
			}
    			sentence = *it;

		}
    		else if (sentence.getLexeme() == "downto"){
			it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	
			}
    			sentence = *it;

		}
		else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    		if (sentence.getCarac() == "etiquette"){
			it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<endl;
				 
			}
    			sentence = *it;

		}
		else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
	}	
	else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    }
   		 if (sentence.getLexeme() == ")"){
			it++;
    		sentence = *it;
		}
		else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    	if (sentence.getLexeme() == ";"){
		it++;
    	sentence = *it;
	}
		else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    	exit(1);   
    }  

    } 
    while (sentence.getLexeme() == "type");	
	return sentence.getPlace();	
		
}  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int VerifSyntaxe_Signal(list<Mot> my_list_mot, int iPlace){

ofstream arbre_archi("../../vhdl/test_bench/results/arbre_archi.txt",ios::app);  //on vide le fichier
    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string nom_signal;
    
   for (int j = sentence.getPlace(); j<iPlace; j++){
		it++;
		sentence = *it;
	}	
	do {
		it++;
    	sentence = *it;
		if (sentence.getCarac() == "etiquette"){
			string nom_signal = sentence.getLexeme();
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				it--;
				sentence = *it;
				arbre_archi<<sentence.getLexeme()<<" ";	
				it ++;
				sentence = *it;
				arbre_archi<<sentence.getLexeme()<<" ";	
			} 
			it++;
    		sentence = *it;
		}
		else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    	if (sentence.getLexeme() == ":"){
			it++;
    		sentence = *it;
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}   
    	if (sentence.getLexeme() == "bit"){
			it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<endl;	
			}
    		sentence = *it;
		}
		else if (sentence.getLexeme() == "bit_vector"){
			it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	
			}
    		sentence = *it;
			if (sentence.getLexeme() == "("){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getCarac() == "etiquette"){ //NUMBER PAR LA SUITE 
				it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	
			}
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getLexeme() == "to"){
				it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	
			}
    			sentence = *it;
			}
    		else if (sentence.getLexeme() == "downto"){
				it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	
			}
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getCarac() == "etiquette"){
				it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<endl;
				
			}
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
			if (sentence.getLexeme() == ")"){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}   
    	it++;
		sentence = *it;
    
    } 
    while (sentence.getLexeme() == "signal");
	return sentence.getPlace();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int VerifSyntaxe_Variable(list<Mot> my_list_mot, int iPlace){

ofstream arbre_archi("../../vhdl/test_bench/results/arbre_archi.txt",ios::app);  //on vide le fichier
 list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    
   for (int j = sentence.getPlace(); j<iPlace; j++){
		it++;
		sentence = *it;
	}	
	do {
		it++;
    	sentence = *it;
		if (sentence.getCarac() == "etiquette"){
			string nom_signal = sentence.getLexeme(); 
			it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				it--;
				it--;//on récupère le mot vaiable
				sentence = *it;
				arbre_archi<<sentence.getLexeme()<<" ";	
				it++;//on réinstancie les itérateurs
				sentence = *it;
				arbre_archi<<sentence.getLexeme()<<" ";	
				it++;
			}
    		sentence = *it;
		}
		else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    	if (sentence.getLexeme() == ":"){
			it++;
    		sentence = *it;
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}   
    	if (sentence.getLexeme() == "bit"){
			it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<endl;	
			}
    		sentence = *it;
		}
		else if (sentence.getLexeme() == "bit_vector"){
			it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	
			}
    		sentence = *it;
			if (sentence.getLexeme() == "("){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getCarac() == "etiquette"){ //NUMBER PAR LA SUITE 
				it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	
			}
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getLexeme() == "to"){
				it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	
			}
    			sentence = *it;
			}
    		else if (sentence.getLexeme() == "downto"){
				it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<" ";	
			}
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getCarac() == "etiquette"){
				it++;
			if(arbre_archi)  // si l'ouverture a réussi
			{       
				arbre_archi<<sentence.getLexeme()<<endl;
				
			}
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
			if (sentence.getLexeme() == ")"){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}   
    	it++;
		sentence = *it;
    
    } 
    while (sentence.getLexeme() == "variable");

	return sentence.getPlace();



}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int VerifSyntaxe_Process(list<Mot> my_list_mot, int iPlace){
 	list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string nom_process;
    
 	for (int j = sentence.getPlace(); j<iPlace; j++){
		it++;
		sentence = *it;
	}	
 	if (sentence.getCarac() == "etiquette"){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
    	if (sentence.getLexeme() == ":"){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
		}
		else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    	if (sentence.getLexeme() == "process"){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
		}
		else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    		
	}
	else if (sentence.getLexeme() == "process"){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
		}
	else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}

  	if (sentence.getLexeme() == "("){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
		}
	else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    do{
    		if (sentence.getCarac() == "etiquette"){ //variable 
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    }while (sentence.getLexeme() == ",");
    
	if (sentence.getLexeme() == ")"){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
	}	
	else {
		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
	 	exit(1);   
    }
    while (sentence.getLexeme() != "begin"){
    	it++;
		sentence = *it;    
    }

	if (sentence.getLexeme() == "begin"){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
		}
	else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    while (sentence.getLexeme() != "process") {
    	it++;
		sentence = *it;
    }
    it--;
	sentence = *it;
	if (sentence.getLexeme() == "end"){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
		}
	else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
	if (sentence.getLexeme() == "process"){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
		}
	else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	} 
	if (sentence.getCarac() == "etiquette"){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
		}
	else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}  
	if (sentence.getLexeme() == ";"){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
		}
	else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    return sentence.getPlace();	
 }
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 int VerifSyntaxe_PortArchi(list<Mot> my_list_mot,int iPlace){
    
    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string nom_signal;

    for (int j = sentence.getPlace(); j<iPlace; j++){
		it++;
		sentence = *it;
	}	
	do {
		it++;
    	sentence = *it;
		if (sentence.getCarac() == "etiquette"){
			string nom_signal = sentence.getLexeme(); 
			it++;
    		sentence = *it;
		}
		else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    	if (sentence.getLexeme() == ":"){
			it++;
    		sentence = *it;
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}

    	if (sentence.getLexeme() == "in"||sentence.getLexeme() == "out"){
			it++;
    			sentence = *it;
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}   
    	if (sentence.getLexeme() == "bit"){
			it++;
    		sentence = *it;
		}
		else if (sentence.getLexeme() == "bit_vector"){
			it++;
    		sentence = *it;
			if (sentence.getLexeme() == "("){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getCarac() == "etiquette"){ //NUMBER PAR LA SUITE 
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getLexeme() == "to"){
				it++;
    			sentence = *it;
			}
    		else if (sentence.getLexeme() == "downto"){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getCarac() == "etiquette"){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
			if (sentence.getLexeme() == ")"){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}
    } 
    while (sentence.getLexeme() == ";");
 return sentence.getPlace();
 }
 ////////////////////////////////////////////////////////////////////////

void aficher_list_entity(list<Entity>  l_entity)
{
	//list<Entity>::iterator itEntity = l_entity.begin();
	//itEntity ++;
	//cout<<"name entity : "<<(*itEntity).get_name_entity()<<endl;
	//cout<<"numero entity : "<<(*itEntity).get_numero_entity()<<endl;
	/*list<Signal> ls = (*itEntity).get_l_signal();
	for (list<Signal>::iterator it = ls.begin(); it !=ls.end();it++)
	{
		cout<<(*it).get_name()<<" "<< (*it).get_type()<<" "<<(*it).get_IO()<<" "<<endl;
	}*/
}
 
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Entity VerifSyntaxe_Port2(list<Mot> my_list_mot,int iPlace, int num_entity, list<Entity>  l_entity){
    
    list<Mot>::iterator it = my_list_mot.begin();
    Mot sentence;
    sentence = *it;
    string nom_signal;
	Signal sig;
	list<Entity>::iterator itEn = l_entity.begin();
	Entity ent = *itEn;
    	for (int k = 0; k<num_entity-1;k++)
	{
		itEn++;
		ent = *itEn;
	}
    for (int j = sentence.getPlace(); j<iPlace; j++){
		it++;
		sentence = *it;
	}	
	do {
		it++;
    	sentence = *it;
		if (sentence.getCarac() == "etiquette"){
			string nom_signal = sentence.getLexeme(); 
			sig.set_name(nom_signal);//ajout de signal
			it++;
    		sentence = *it;
		}
		else {
    		cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    		exit(1);   
    	}
    	if (sentence.getLexeme() == ":"){
			it++;
    		sentence = *it;
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}

    	if (sentence.getLexeme() == "in"||sentence.getLexeme() == "out"){
			it++;
			sig.set_IO(sentence.getLexeme());
    			sentence = *it;
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}   
    	if (sentence.getLexeme() == "bit"){
			it++;
			sig.set_type(sentence.getLexeme());
    		sentence = *it;
		}
		else if (sentence.getLexeme() == "bit_vector"){
			it++;
			sig.set_type(sentence.getLexeme());
    		sentence = *it;
			if (sentence.getLexeme() == "("){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getCarac() == "etiquette"){ //NUMBER PAR LA SUITE 
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getLexeme() == "to"){
				it++;
    			sentence = *it;
			}
    		else if (sentence.getLexeme() == "downto"){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		if (sentence.getCarac() == "etiquette"){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
			if (sentence.getLexeme() == ")"){
				it++;
    			sentence = *it;
			}
			else {
    			cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère :  "<<sentence.getLexeme()<<endl;
    			exit(1);   
    		}
    		
		}
		else {
    		cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    		exit(1);   
    	}
	//On ajoute le signal a la liste de signaux 
	(*itEn).add_signal(sig);
	(*itEn).set_place_fin_signal(sentence.getPlace());
    } 
    while (sentence.getLexeme() == ";");
 return (*itEn);
 }

