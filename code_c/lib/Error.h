#ifndef _ERROR_H_
#define _ERROR_H_

#include "iostream"
#include "string"
#include "stdio.h"

using namespace std;

class Error
{
public:
  // Constructeur/destructeur
	Error(string type_of_error, bool error):
		m_error(error),
		m_type_of_error(type_of_error)
	{
	}

	Error():
		m_error(0),
		m_type_of_error("pas d'erreur definie.")
	{
	}
    
	virtual ~Error ();
	
	void set_error(bool setError);
	bool get_error();
	void set_type_of_error(string type_of_error);
	string get_type_of_error();

protected :
	bool m_error;
	string m_type_of_error;



};
#endif
