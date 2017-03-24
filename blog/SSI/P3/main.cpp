#include "rc4.hpp"

using namespace std;

int main (void) {
	//system("clear");

	vector<unsigned char> semilla (2, 0);
	semilla[0] = 2;
	semilla[1] = 5;

	vector<unsigned char> msg (2, 0);
	msg[0] = 1;
	msg[1] = 34;
	vector<unsigned char> msg_cifrado (2, 0);
	vector<unsigned char> sec_cifrado;
	
	rc4 A (semilla);
	msg_cifrado = A.cifrar (msg);

    cout << endl << "\t\t\t==============================================";
	cout << endl << "\t\t\t-----------------Inicialización---------------";
    cout << endl << "\t\t\t==============================================";
    cout << endl << "\tEntrada:";
	cout << endl << "El texto original es: ";
	for (int i = 0; i < msg.size(); i++) {
		if (i == msg.size()-1) {
			cout << int(msg[i]);
		}
		else {
			cout << int(msg[i]) << ", ";
		}
	}

	cout << endl << "La semilla es: ";
	for (int i = 0; i < semilla.size(); i++) {
		if (i == semilla.size()-1) {
			cout << int(semilla[i]);
		}
		else {
			cout << int(semilla[i]) << ", ";
		}
	}
	cout << endl << "\tProceso:";
	A.imprimir();

	sec_cifrado = A.secuencia ();
	cout << endl << "\tSalida:";
	cout << endl << "La secuencia cifrante es: ";
	for (int i = 0; i < sec_cifrado.size(); i++) {
		if (i == sec_cifrado.size()-1) {
			cout << int(sec_cifrado[i]);
		}
		else {
			cout << int(sec_cifrado[i]) << ", ";
		}
	}

	cout << endl << "El texto cifrado es: ";
	for (int i = 0; i < msg_cifrado.size(); i++) {
		if (i == msg_cifrado.size()-1) {
			cout << int(msg_cifrado[i]) << endl;
		}
		else {
			cout << int(msg_cifrado[i]) << ", ";
		}
	}

///////////////////////////////////////////////////////////////////////////////////////////////////

	cout << endl << "\t\t\t==============================================";
	cout << endl << "\t\t\t--------------------SPRITZ--------------------";
	cout << endl << "\t\t\t==============================================";
	cout << endl << "\tSalida:";
	cout << endl;
	
	vector<unsigned char> msg_cifrado_3 (2, 0);
	vector<unsigned char> sec_cifrado_3;

	rc4 C (semilla);
	msg_cifrado_3 = C.cifrar_spritz (msg);
	

	sec_cifrado_3 = C.secuencia ();
	
	cout << endl << "La secuencia cifrante es: ";

	for (int i = 0; i < sec_cifrado_3.size(); i++) {
		if (i == sec_cifrado_3.size()-1) {
			cout << int(sec_cifrado_3[i]);
		}
		else {
			cout << int(sec_cifrado_3[i]) << ", ";
		}
	}
	cout << endl << endl;

///////////////////////////////////////////////////////////////////////////////////////////////////
	//getchar();

	std::vector<unsigned char> semilla_2 (8, 0);
	semilla_2 = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};

	std::vector<unsigned char> msg_2 (8, 0);
	msg_2 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	std::vector<unsigned char> msg_cifrado_2 (8, 0);
	std::vector<unsigned char> sec_cifrado_2;

	rc4 B (semilla_2);
	msg_cifrado_2 = B.cifrar (msg_2);

	cout << endl << "\t\t\t==============================================";
	cout << endl << "\t\t\t-------EJEMPLO DE CLASE EN HEXADECIMAL--------";
	cout << endl << "\t\t\t==============================================";
	cout << endl << "\tEntrada:";
	cout << endl << "La semilla es: ";
	for (int i = 0; i < semilla_2.size(); i++) {
		if (i == semilla_2.size()-1) {
			cout << hex << int(semilla_2[i]);
		}
		else {
			cout << hex << int(semilla_2[i]) << ", ";
		}
	}
	cout << endl << "\tProceso:";
	B.imprimir();
	
	sec_cifrado_2 = B.secuencia ();
	cout << endl << "\tSalida:";
	cout << endl << "La secuencia cifrante es: ";
	for (int i = 0; i < sec_cifrado_2.size(); i++) {
		if (i == sec_cifrado_2.size()-1) {
			cout << hex << int(sec_cifrado_2[i]);
		}
		else {
			cout << hex << int(sec_cifrado_2[i]) << ", ";
		}
	}
	
	cout << endl << endl;

}