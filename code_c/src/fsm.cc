#include "../lib/fsm.h"

using namespace std; 


//fonction locale
list<Mot> fsm::add_entity(std::list<Mot> my_list_Mot)
{/*
    Mot sentence;
    
    sentence = *it;
    cout << "nom de l'entité : " <<endl;
    cout<< sentence.getLexeme() <<endl;
    _entities.push_back(Entity(sentence.getLexeme()));
    it ++;
    it ++;
    it ++;
    it ++;
    sentence = *it;
    cout << "nom de signal : " << endl;
    cout << sentence.getLexeme() <<endl;
    while (sentence.getLexeme() != ";")
    {
        while (sentence.getLexeme() != ")")
        {
            _entities.back()._signal.push_back(Signal(sentence.getLexeme()));
            it++;
            it++;
            sentence = *it;
            cout << "nom du signal : "<<endl;
                cout<< sentence.getLexeme() <<endl;
            _entities.back()._signal.back().setDirection(sentence.getLexeme());
            it++;
            sentence = *it;
            cout << "type du signal : "<<endl;
                cout<< sentence.getLexeme() <<endl;
            _entities.back()._signal.back().setType(sentence.getLexeme());
            it++;
            sentence = *it;
        }
        it++;
        
       sentence = *it;
    }*/
	return my_list_Mot;
}





list<Mot> fsm::add_librairy(std::list<Mot> my_list_Mot)
{/*
    Mot sentence;
    
    sentence = *it;
    _librairies.push_back(Librairy(sentence.getLexeme()));
    do {
	it++;
    sentence = *it;
    }while (sentence.getLexeme() != "use");
    
    
        while (sentence.getLexeme() != ";")
        {
        	it ++;
    		sentence = *it;
            _librairies.back()._use.push_back(Use(sentence.getLexeme()));
            it ++;
            it ++;
            sentence = *it;
            _librairies.back()._use.back().setPaquet(sentence.getLexeme());
            it ++;
            it ++;
            sentence = *it;
            _librairies.back()._use.back().setEnd(sentence.getLexeme());
            it++;
            sentence = *it;
        }
        it++;
       sentence = *it;*/
	return my_list_Mot;
}



/*std::list<Mot>::iterator add_architecture(std::list<Mot>::iterator it)
{    

    Mot sentence;
    
    sentence = *it;
    _architecture.push_back(Architecture(sentence.getLexeme()));
    it = it + 2;
    sentence = *it;
    _architecture.back().setEntityName(sentence.getLexeme());
    it = it + 2;
    sentence = *it;
        
    while (sentence != "end")
    {
        
    }
        it++;
       sentence = *it;
    }
        return sentence;

}

}*/


//fonction membre
void fsm::processList(){
/*    Mot sentence;
for(std::list<Mot>::iterator it = _liste.begin() ; it != _liste.end() ; ++it)
    {
        sentence = *it;
        int iPlace;
        
        bool Validation = 0; 
    	if (sentence.getLexeme() == "librairy")
        {
            ++it;
            //it = add_librairy(it);
        }
        else if (sentence.getLexeme() == "entity")
        {           
            Entity entity;
            iPlace = entity.TestEntity(it);
			for (int j = sentence.getPlace(); j<iPlace; j++){
				it++;
			}

        }
        else if (sentence.getLexeme() == "architecture")
        {
            ++it;
            //it = add_architecture(it);    
   		 }
	}*/
}

  
