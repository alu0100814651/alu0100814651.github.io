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

	a5 A (vector_1, datos_v_1, vector_2, datos_v_2, vector_3, datos_v_3);
	
	int opt = 0;

	cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INICIO~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\tCuántas iteraciones desea realizar?" << endl;
	cout << "\t\t";
	cin  >> opt;
	for (int i = 0; i < 10; i++) {
		A.generar ();
		A.imprimir_datos ();
	}
	cout << endl << "Semilla inicial:" << endl;
	A.imprimir_datos();
	for (int i = 0; i < opt; i++) {
		cout << endl << "Iteración: " << i+1;
	    A.generar();
    	A.imprimir_datos ();
    	getchar();
	}
	cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
	//MODIFICACION PRACTICA
	vector<bool> vector_1_mod = {1,0,0,0,1,0,1,1,0,0,0,1,0,0,0,1,0,0,1};
	vector<bool> vector_2_mod = {0,1,0,1,1,0,0,1,0,0,0,1,1,1,1,0,0,1,1,0,1,0};
	vector<bool> vector_3_mod = {1,1,1,1,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,1,1,0,1};
	vector<unsigned int> datos_vector_1_mod = {14,17,18,19,9};
	vector<unsigned int> datos_vector_2_mod = {21,22,11};
	vector<unsigned int> datos_vector_3_mod = {8,21,22,23,11};
	a5 B(vector_1_mod, datos_vector_1_mod, vector_2_mod, datos_vector_2_mod, vector_3_mod, datos_vector_3_mod,0);

}