// g++ -std=c++11 main.cpp vernam.cpp

#include "vernam.hpp"

using namespace std;

int main(void)
{
    int opt = 0;
    string msg;     // SOL
    string clave;   // 001111000001100001110011
    string cad;     // [t
    string clave2;  // 0000111100100001
    string clave_encriptado;
    
    cout << "¿Desea Encriptar (1) o Desencriptar (2) o Modificación (3)? \n";
    cin  >> opt;
    switch (opt)
    {
    case 1:{
        cout << "Introduzca el mensaje a encriptar: " << endl;
        cin  >> msg;
        cout << "Introduzca la clave para el mensaje a encriptar: " << endl;
        cin  >> clave;
        
        cout << "==============================================" << endl;
        
        cout << "Entrada:" << endl;
        cout << "\t Nuestro mensaje a encriptar es: \t" << msg << endl;
        cout << "\t Nuestra clave para encriptar el mensaje es: \t" << clave << endl;
        vernam A(clave);
        cout << "Salida:" << endl;
        cout << "||==========================================================" << endl;
        cout << "||\t" << msg << "\n||\t\tXOR\n" << "||\t" << clave << "\n||\t___________________________________________\n";
        cout << "||\tNuestro mensaje encriptado es: " << A.encriptar(msg) << endl;
        cout << "||==========================================================" << endl;
        
        cout << "==============================================" << endl;
        
        cout << "Introduzca la clave para encriptar el mensaje encriptado: " << endl;
        cin  >> clave_encriptado;
        string encriptado = A.encriptar(msg);
        
        cout << "Entrada:" << endl;
        cout << "\t Nuestro mensaje a encriptar es: \t" << encriptado << endl;
        cout << "\t Nuestra clave para encriptar el mensaje es: \t" << clave_encriptado << endl;
        vernam B(clave_encriptado);
        cout << "Salida:" << endl;
        cout << "||==========================================================" << endl;
        cout << "||\t" << encriptado << "\n||\t\tXOR\n" << "||\t" << clave_encriptado << "\n||\t___________________________________________\n";
        cout << "||\tNuestro mensaje encriptado es: " << B.encriptar(encriptado) << endl;
        cout << "||==========================================================" << endl;
        break;
    }
    case 2:{
        cout << "Introduzca la cadena a desencriptar: " << endl;
        cin  >> cad;
        cout << "Introduzca la clave para la cadena a desencriptar: " << endl;
        cin  >> clave2;
        
        cout << "==============================================" << endl;
        
        cout << "Entrada:" << endl;
        cout << "\t Nuestra cadena a desencriptar es: " << cad << endl;
        cout << "\t Nuestra clave para desencriptar el mensaje es: " << clave2 << endl;
        vernam B(clave2);
        cout << "Salida:" << endl;
        cout << "||==========================================================" << endl;
        cout << "||\t" << cad << "\n||\t\tXOR\n" << "||\t" << clave2 << "\n||\t___________________________________________\n";
        cout << "||\t Nuestra cadena desencriptada es: " << B.desencriptar(cad) << endl;
        cout << "||==========================================================" << endl;
        break;
    }
    case 3:
        string mensaje_2 = "VERNAM";
        string clave3 = "SEGURO";
        vernam C(clave3,0);
        string mensaje_encriptado = C.encriptar(mensaje_2);
        cout << endl << "Nuestro mensaje es: " << mensaje_2 << endl;
        cout << "Nuestra clave es: " << clave3 << endl;
        cout << "Nuestro mensaje encriptado es: " << C.conversor_modif(mensaje_encriptado) << endl;
    }
}