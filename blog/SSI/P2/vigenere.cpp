#include "vigenere.hpp"

vigenere::vigenere (void):
mensaje_(""),
clave_("")
{}

vigenere::vigenere (string clave_a_cifrar, string mensaje_sin_cifrar):
mensaje_(mensaje_sin_cifrar),
clave_(clave_a_cifrar)
{}

vigenere::~vigenere ()
{
	mensaje_.clear();
	clave_.clear();
}

void vigenere::corrector ()
{
    if ((mensaje_.length() >= clave_.length())) {
        for (int i = 0; i < mensaje_.length(); i++) {
            if (mensaje_[i] == ' ') {
                mensaje_[i] = '-';
            }
            mensaje_[i] = toupper(mensaje_[i]);
            if (!((mensaje_[i] <= 'Z') && (mensaje_[i] >= 'A'))) {
                if (mensaje_[i] != '-') {
                    mensaje_[i] = '*';
                }
            }
        }

        for (int i = 0; i <= clave_.length(); i++) {
            if (clave_[i] == ' ') {
                clave_[i] = '-';
            }
            clave_[i] = toupper(clave_[i]);
            if (!((clave_[i] <= 'Z') && (clave_[i] >= 'A'))) {
                if (clave_[i] != '-'){
                    clave_[i] = '*';
                }
            }
        }
    }
    else {
        cerr << "EL MENSAJE DEBE SER MAYOR O IGUAL A LA CLAVE!!!" << endl;
    }
}

string vigenere::mensaje_formateado ()
{
    return mensaje_;
}

string vigenere::clave_formateada ()
{
    return clave_;
}

void vigenere::mensaje_encriptado (string cifrado)
{
    mensaje_ = cifrado;
}

string vigenere::cifrar ()
{
    int j, caracter = 0, postexto, posclave;
    string mensaje_cifrado;
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    for (int i = 0; i < mensaje_.length(); i++) {
        if (j >= clave_.length()) {
            j = 0;
        }
        if (mensaje_[i] != '*') {
            if (mensaje_[i] == '-') {
               j--;
            }
            postexto = alfabeto.find(mensaje_[i]);
            posclave = alfabeto.find(clave_[j]);
            caracter = alfabeto[(postexto + posclave)%26];
            if (mensaje_[i] == '-') {
                caracter = mensaje_[i];
            }
        }
        else {
            caracter = mensaje_[i];
        }
        j++;
        mensaje_cifrado.append(string(1, (char)(caracter)));
    }
    return mensaje_cifrado;
}

string vigenere::descifrar ()
{
    int j, caracter = 0;
    string mensaje_descifrado;
    for (int i = 0; i < mensaje_.length(); i++) {
        
        if (j >= clave_.length()) {
            j = 0;
        }
        if (mensaje_[i] != '*') {
            if (mensaje_[i] == '-') {
                j--;
            }
            caracter = mensaje_[i] - clave_[j];
            if (caracter < 0) {
                caracter = caracter + 26;
            }
            caracter = caracter + 65;
            if (mensaje_[i] == '-') {
                caracter = ' ';
            }
        }
        else {
            caracter = mensaje_[i];
        }
        j++;
        mensaje_descifrado.append(string(1, (char)(caracter)));
    }
    return mensaje_descifrado;
}

/*
//Modificación de la práctica
string vigenere::cesar (void){
	string clave_cesar, mensaje_nuevo;
	int j=0;
	for (int i = 0; i < mensaje_.length(); i++) {
	    if (mensaje_[i] != '-') {
	        mensaje_nuevo.append(string(1,mensaje_[i]));
	    }
	    else {
	        mensaje_nuevo.append(string(1,mensaje_[i+1]));
	        i++;
	    }
	}
	for (int i=0; i<clave_.length();i++){
		for (int j=0; j<mensaje_nuevo.length();j+=clave_.length()){
			clave_cesar.append(string(1,mensaje_nuevo[i+j]));
		}
		clave_cesar.append(string(1,'\n'));
	}
	clave_cesar.erase(clave_cesar.length()-1);
	return clave_cesar;
}
*/