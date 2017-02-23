#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <locale>
#include <algorithm>

using namespace std;

class vigenere
{
    private:
        string clave_;
        string mensaje_;
    public:
        vigenere ();
        vigenere (string clave_a_cifrar, string mensaje_sin_cifrar);
        ~vigenere ();
        
        string mensaje_formateado ();
        string clave_formateada ();
        void mensaje_encriptado (string cifrado);

        void corrector ();
        
        string cifrar ();
        string descifrar ();