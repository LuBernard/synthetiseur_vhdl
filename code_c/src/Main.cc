<<<<<<< HEAD
#include "../lib/Node.h"
#include "../lib/Mot.h"
#include "../lib/Entity.h"
#include "../lib/Chaine.h"
#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	//printf("hello world");
	Separateur_espace();
	
		
	
=======
#include "../lib/lecture_fichier.h"
using namespace std;

int main(void)
{	

	list<string> l;
	string chemin = "../../vhdl/test_line.txt";
	l = lecture_fichier(chemin);
>>>>>>> 85d857e62a40228847e26860d0c86f0f00b29180
	return 0;
}
