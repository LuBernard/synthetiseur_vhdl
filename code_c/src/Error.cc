#include "../lib/Error.h"


/*Error::Error(string type_of_error, bool error){
	this->error = error;
	this->type_of_error = type_of_error;
}

Error::Error(){
	m_error = 0;
	m_type_of_error = "pas de type d'erreur definie.";
}*/

void Error::set_error(bool setError){
	m_error = setError;
}

bool Error::get_error(){
	return m_error;
}

void Error::set_type_of_error(string typeError){
	m_type_of_error = typeError;
}

string Error::get_type_of_error(){
	return m_type_of_error;
}
