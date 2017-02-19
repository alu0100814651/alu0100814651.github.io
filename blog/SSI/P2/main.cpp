//Compilar usando g++ -std=c++11 main.cpp vigenere.cpp

#include "vigenere.hpp"
#include <cctype>
#include <cstdlib>

using namespace std;

int main (void){
    system("clear");
    int opt = 0;
    while (opt != 5) {
        cout << "Desea Cifrar (1), Descifrar (2), Ambos (3), César (4) o Salir (5)?" << endl;
        cin >> opt;
        switch (opt) {
            case 1: {
                string clave_a_cifrar;// = "MISION";
            	string mensaje_sin_cifrar;// = "Este mensaje se autodestruira";
            
            	cout << "Introduzca el \"Mensaje-para-cifrar\" y la \"CLAVE\"" << endl;
            	cin >> mensaje_sin_cifrar;
            	cin >> clave_a_cifrar;
            	vigenere A(clave_a_cifrar, mensaje_sin_cifrar);
            
            	cout << endl << "====================" << endl;
            	cout << "El mensaje sin formato es: " << mensaje_sin_cifrar << endl;
            	cout << "La clave de cifrado es: " << clave_a_cifrar << endl;
            	A.corrector ();
            	cout << "El mensaje con formato es: " << A.mensaje_formateado () << endl;
            	cout << "La clave con formato es: " << A.clave_formateada () << endl;
            	cout << "El mensaje cifrado es: " << A.cifrar () << endl;
            	cout << "====================" << endl;
                break;
            }
            case 2: {
                string clave_a_descifrar;// = "MISION";
            	string mensaje_cifrado;// = "QALM-ARZASRS-FQ-IMBCQQALZIVDI";
            	
            	cout << "Introduzca el \"CIFRADO-PARA-DESCIFRAR\" y la \"CLAVE\"" << endl;
            	cin >> mensaje_cifrado;
            	cin >> clave_a_descifrar;
            	vigenere A(clave_a_descifrar, mensaje_cifrado);
                A.corrector ();
            	cout << endl << "====================" << endl;
            	cout << "El cifrado es: " << mensaje_cifrado << endl;
            	cout << "La clave de cifrado es: " << clave_a_descifrar << endl;
            	cout << "El cifrado con formato es: " << A.mensaje_formateado () << endl;
            	cout << "La clave con formato es: " << A.clave_formateada () << endl;
            	cout << "El mensaje descifrado es: " << A.descifrar () << endl;
            	cout << "====================" << endl;
            	break;
            }
            case 3: //{
                string clave_a_cifrar;// = "MISION";
            	string mensaje_sin_cifrar;// = "Este mensaje se autodestruira";
            
            	cout << "Introduzca el \"Mensaje-para-cifrar\" y la \"CLAVE\"" << endl;
            	cin >> mensaje_sin_cifrar;
            	cin >> clave_a_cifrar;
            	vigenere A(clave_a_cifrar, mensaje_sin_cifrar);
            
            	cout << endl << "====================" << endl;
            	cout << "El mensaje sin formato es: " << mensaje_sin_cifrar << endl;
            	cout << "La clave de cifrado es: " << clave_a_cifrar << endl;
            	A.corrector ();
            	cout << "El mensaje con formato es: " << A.mensaje_formateado () << endl;
            	cout << "La clave con formato es: " << A.clave_formateada () << endl;
            	string cifrado = A.cifrar ();
            	cout << "El mensaje cifrado es: " << cifrado << endl;
            	A.mensaje_encriptado (cifrado);
            	cout << "El mensaje descifrado es: " << A.descifrar () << endl;
            	cout << "====================" << endl;
            /*	break;
            }
            case 4:
                //Modificación práctica
            	string clave_cifrar1; // = "SECRET";
            	string mensaje_sin_cifrar1; // ="THERE ARE NO SECRETS ANYMORE";
            	cout << "Introduzca el \"Mensaje-para-cifrar\" y la \"CLAVE\"" << endl;
            	cin >> mensaje_sin_cifrar1;
            	cin >> clave_a_cifrar1;
            	vigenere B(clave_cifrar1,mensaje_sin_cifrar1);
            	
            	cout << endl << "====================" << endl;
            	cout << "El mensaje sin formato es: " << mensaje_sin_cifrar_2 << endl;
            	cout << "La clave de cifrado es: " << clave_cifrar_2 << endl;
            	B.corrector ();
            	cout << "El mensaje con formato es: " << B.mensaje_formateado () << endl;
            	cout << "La clave con formato es: " << B.clave_formateada () << endl;
            	string cifrado = B.cifrar ();
            	cout << "El mensaje cifrado es: " << cifrado << endl;
            	B.mensaje_encriptado (cifrado);
            	cout << "El mensaje descifrado es: " << B.descifrar () << endl;
            	cout << "El mensaje César es: " << B.cesar () << endl;
            	cout << "====================" << endl;
            */
        }
    }
}