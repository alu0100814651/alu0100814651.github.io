//Pasos a seguir:
//		--> sudo apt install libboost-all-dev
//		--> sudo apt install libgmp3-dev
//		--> g++ -std=c++11 main.cpp FS.cpp -lgmp

#include "FS.hpp"

using namespace std;

int main (void)
{
	system ("clear");
	
	boost::multiprecision::mpz_int p_a, q_a, d_a, s_a, p_b, q_b, d_b, x_a, x_b, e_a, e_b;
	unsigned iter;

    cout << endl << "\t\t\t==============================================";
	cout << endl << "\t\t\t-----------------DIFFIE-HELLMAN---------------";
    cout << endl << "\t\t\t==============================================";
    cout << endl << endl;
	cout << "p = ";
	cin >> p_a;
	cout << "q = ";
	cin >> q_a;
	cout << "s = ";
	cin >> s_a;
	cout << "i (número de iteraciones) = ";
	cin >> iter;
	cout << endl << "B utilizará los mismo valores que A." << endl << endl;
	FS A (p_a, q_a, s_a);
	FS B (p_a, q_a, s_a);
	cout << "La N de A es: " << A.get_n () << endl;
	cout << "La v de A es: " << A.get_v () << endl << endl;

	for (int i = 0; i < iter; i++)
	{
		cout << i + 1 << "ª iteracción: " << endl;
		cout << "x = ";
		cin >> x_a;
		A.set_x (x_a);
		cout << "e = ";
		cin >> e_b;
		cout << "\t===> a de A es: " << A.get_a () << endl;
		cout << "\t===> y de A es: " << A.get_y (e_b) << endl;
		cout << "\tVerificación de B en proceso..." << endl;
		
		if (B.verificacion (A.get_y (e_b), A.get_a (), A.get_v (), A.get_n (), e_b))
		{
			cout << "\tLa verificación por parte de B es válida" << endl;
		}
		else
		{
			cout << "\tLa información recibida para B no es válida" << endl;
		}
		cout << endl;
	}
}