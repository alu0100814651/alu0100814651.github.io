#include <iostream>
#include <bitset>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

class vernam{
private:
	string clavE;
public:
	vernam (void);
	vernam (string clave);
	vernam (string clave, int num);
	~vernam (void);
	string encriptar (string mensaje);
	string desencriptar (string mensaje);
	string conversor (string clave);
	string conversor_modif (string clave);
	string imprimir (void);
};