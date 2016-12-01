#include "../lib/lecture_fichier.h"
using namespace std;

int main(void)
{	

	list<string> l;
	string chemin = "../../vhdl/test_line.txt";
	l = lecture_fichier(chemin);
	return 0;
}
