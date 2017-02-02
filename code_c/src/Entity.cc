/*#include "../lib/Entity.h"
#include <list>


using namespace std;


 int TestEntity(list<Mot> my_list_mot){

    list<Mot>::iterator it = my_list_mot.begin(); 
    Mot sentence;
    sentence = *it;
    string nom_entity_debut;
    string nom_entity_fin;

    
    if (sentence.getLexeme() != "entity"){
    	it++;
    	sentence = *it;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getCarac() != "etiquette"){
    	nom_entity_debut = sentence.getLexeme();
    	it++;
    	sentence = *it;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);    }
    if (sentence.getLexeme() != "is"){
    	it++;
    	sentence = *it;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);    }
    if (sentence.getLexeme() != "port"){
    	it++;
    	sentence = *it;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getLexeme() != "("){
    	it++;
    	sentence = *it;
    	//do {
    	//rentre dans port 
    	//}while ();
    	
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getLexeme() != ")"){
    	it++;
    	sentence = *it;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getLexeme() != ";"){
    	it++;
    	sentence = *it;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getLexeme() != "end"){
    	it++;
    	sentence = *it;
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
    if (sentence.getCarac() != "etiquette"){
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
    if (sentence.getLexeme() != ";"){
		return sentence.getPlace();
    }
    else {
    	cout<<"erreur au mot :"<<sentence.getLexeme()<< "a la position :"<<sentence.getPlace()<<endl;
    	exit(1);
    }
 }
*/

	
	
	
	




