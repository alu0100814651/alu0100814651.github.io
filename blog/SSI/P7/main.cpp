#include "DH.hpp"

using namespace std;

int main (void){
	int opt = 1;
	while (opt != 0)
	{
		system("clear");
		unsigned primo = 0;
		unsigned alfa = 0;
		unsigned secreto_a = 0;
		unsigned secreto_b = 0;
		cout << "Introduzca el número primo a utilizar:" << endl;
		cin >> primo;
		
		cout << "Introduzca el número α a utilizar:" << endl;
		cin >> alfa;
		
		cout << "El número secreto de A es:" << endl;
		cin >> secreto_a;
		
		cout << "El número secreto de B es:" << endl;
		cin >> secreto_b;
		
		DH A (primo, alfa, secreto_a);
		DH B (primo, alfa, secreto_b);
	
	    cout << endl << "\t\t\t==============================================";
		cout << endl << "\t\t\t-----------------DIFFIE-HELLMAN---------------";
	    cout << endl << "\t\t\t==============================================";
	    cout << endl;
		cout << "p = " << primo << "     ";
		cout << "α = " << alfa << "     ";
		cout << "xA = " << A.get_secreto () << "     ";
		cout << "xB = " << B.get_secreto () << "     ";
		cout << "yA = " << A.get_y () << "     ";
		cout << "yB = " << B.get_y () << "     ";
		cout << "k = " << A.exp_rapida (B.get_y(), A.get_secreto()) << " (para A)     ";
		cout << "k = " << B.exp_rapida (A.get_y(), B.get_secreto()) << " (para B)" << endl << endl << endl;
		
		cout << "Quiere realizar otra consulta? SI(1) NO(0)" << endl;
		cin >> opt;
	}
}
