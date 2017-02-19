#include "vernam.hpp"

vernam::vernam (void) //Constructor
{}

vernam::vernam (string clave) //Constructor para coger la clave y convertirla a binario
{
	clavE = conversor (clave);
}

vernam::vernam (string clave, int num) //Constructor para coger solamente la clave
{
	clavE = clave;
}

vernam::~vernam(void) //Desctructor
{}

string vernam::encriptar (string mensaje) //Función de encriptar el mensaje q se le pasa por parámetro
{
	for (int i = 0; i < mensaje.length(); i++)
	{
		mensaje[i] = mensaje[i] ^ clavE[i]; //Se hace el XOR para cada elemento con la clave q le ha sido asignada (en el constructor)
		//cout << mensaje[i] << endl;
	}
	//cout << "El mensaje encriptado: " << mensaje << endl;
	return mensaje;
}

string vernam::desencriptar (string mensaje) //Función de desencriptar el mensaje q se le pasa por parámetro
{
	for (int i = 0; i < mensaje.length(); i++)
	{
		mensaje[i] = mensaje[i] ^ clavE[i]; //Se hace el XOR para cada elemento
	}
	return mensaje;
}

string vernam::conversor (string clave) //Función de convertir la clave q se le pasa por parámetro a binario
{
	if (clave.size()%8 != 0) //Comprobamos si la clave es de una tamaño apropiado
		cerr << "LA CLAVE ESTA MAL" << endl;

	string clave_ascii ("", clave.size()/8); //Creamos una variable en la q dividimos la clave binaria por partes (por letra), para poder desencriptarlo
	stringstream clave_stream (clave); //Creamos una variable q contiene la clave
	for (int i = 0; i < clave.size()/8; i++) //Pasamos de Bits a Unsigned, para luego pasarlo a un Caracter ASCII
	{
		bitset<8> clave_bit;
		clave_stream >> clave_bit;
		clave_ascii[i] = char(clave_bit.to_ulong());
		//cout << "Clave ASCII: " << clave_ascii[i] << endl;
	}
	//cout << "La Clave ASCII es: " << clave_ascii << endl;
	return clave_ascii;
}

string vernam::conversor_modif (string mensaje) //Función de convertir la clave q se pasa por parámetro a buleana (bits)
{
	string clave_bool;
	for(int i = 0; i < mensaje.size(); i++)
		clave_bool += (bitset<8>(mensaje.c_str()[i])).to_string();
	return clave_bool;
}

string vernam::imprimir (void)
{
	return clavE;
}
