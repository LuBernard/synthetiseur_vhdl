#include "../lib/VerifSyntaxique.h"
#include <list>


using namespace std;


 list<Entity> VerifSyntaxe_Entity(list<Mot> my_list_mot, list<Entity> list_entity){

	list<Mot>::iterator it = my_list_mot.begin(); 
	list<Entity>::iterator itEntity = list_entity.end(); 
	list<Entity>::reverse_iterator reverse_itEntity = list_entity.rbegin(); 
	Mot sentence;
	sentence = *it;
	string nom_entity_debut;
	string nom_entity_fin;
	int iPlace;


    if (sentence.getLexeme() == "entity"){
    	it++;
    	sentence = *it;	
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position : "<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getCarac() == "etiquette"){
    	nom_entity_debut = sentence.getLexeme();
    	it++;
    	sentence = *it;
	list_entity.push_back(Entity(nom_entity_debut));
	reverse_itEntity = list_entity.rbegin();
	cout<<"coucou "<<reverse_itEntity->get_name()<<endl;
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
    		iPlace = VerifSyntaxe_Signal(my_list_mot,sentence.getPlace());
    		for (int j = sentence.getPlace(); j<iPlace; j++){
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
		cout<<"ENTITY ALL IS GOOD "<<sentence.getPlace()<<endl;
		reverse_itEntity->set_place_fin_entity(sentence.getPlace());
		cout<<"coucou 2 "<< reverse_itEntity->get_place_fin_entity()<<endl;
		return list_entity;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
 }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 int VerifSyntaxe_Signal(list<Mot> my_list_mot,int iPlace){
    
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
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
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
    if (sentence.getLexeme() == "std_logic"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);   
    }   
    
    } 
    while (sentence.getLexeme() == ";");
    
 return sentence.getPlace();
 }
	
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	
	
int VerifSyntaxe_Library(list<Mot> my_list_mot){
    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string nom_library;
    
	if (sentence.getLexeme() == "library"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
	if (sentence.getCarac() == "etiquette"){
		string nom_library = sentence.getLexeme(); 
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == ";"){
    
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
	 return sentence.getPlace();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int VerifSyntaxe_Use(list<Mot> my_list_mot){







}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int VerifSyntaxe_Architecture(list<Mot> my_list_mot){
    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string nom_architecture;	
    string nom_entity;
    
    if (sentence.getLexeme() == "architecture"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getCarac() == "etiquette"){
        nom_architecture = sentence.getLexeme();
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == "of"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getCarac() == "etiquette"){
        nom_entity = sentence.getLexeme();
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == "is"){
        nom_entity = sentence.getLexeme();
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == "begin"){
        nom_entity = sentence.getLexeme();
		it++;
    	sentence = *it;
	}
	else if (sentence.getLexeme() == "type")  {
		   	/*do {
    		iPlace = TestSignal(it)
    		for (int j = sentence.getPlace(); j<iPlace; j++){
				it++;
			}
    	}while (sentence.getLexeme() == ";");*/
    } 
    else if (sentence.getLexeme() =="component")  {
		   	/*do {
    		iPlace = TestSignal(it)
    		for (int j = sentence.getPlace(); j<iPlace; j++){
				sentence = *it;
			}
    	}while (sentence.getLexeme() == "type");*/
    } 
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }     

	return sentence.getPlace();            
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 int VerifSyntaxe_Type(list<Mot> my_list_mot){

    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string nom_architecture;	
    string nom_entity;
    
    if (sentence.getLexeme() == "type"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getCarac() == "etiquette"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == "is"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == "("){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == ")"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }
    if (sentence.getLexeme() == ";"){
		it++;
    	sentence = *it;
	}
	else {
    	cout<<" erreur au mot :"<<sentence.getLexeme()<< " a la position :"<<sentence.getPlace()<<" Caractère"<<sentence.getLexeme()<<endl;
    	exit(1);   
    }  
	return sentence.getPlace();
}  



