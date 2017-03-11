#include "A5.hpp"

using namespace std;

int main (void) {
    
    system("clear");

	vector<bool> vector_1 = {1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1};
	vector<bool> vector_2 = {0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0};
	vector<bool> vector_3 = {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1};

	vector<unsigned int> datos_v_1 = {14, 17, 18, 19, 9};
	vector<unsigned int> datos_v_2 = {21, 22, 11};
	vector<unsigned int> datos_v_3 = {8, 21, 22, 23, 11};

	a5 A(vector_1, datos_v_1, vector_2, datos_v_2, vector_3, datos_v_3);

	cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INICIO~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	A.imprimir_datos();
	A.generar();
	A.imprimir_datos ();
	getchar();
	A.generar();
	A.imprimir_datos ();
	getchar();
	A.generar();
	A.imprimir_datos ();
	getchar();
	A.generar();
	A.imprimir_datos ();
	getchar();
	A.generar();
	A.imprimir_datos ();
	getchar();
	A.generar();
	A.imprimir_datos ();
	cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}