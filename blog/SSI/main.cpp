#include <iostream>

using namespace std;

int main ()
{
    system ("clear");
    int aux = 0;
    
    while (aux != 10)
    {
        cout << endl << "\t\t\t==============================================";
    	cout << endl << "\t\t\t|----------------Menú Principal--------------|";
        cout << endl << "\t\t\t|    Opciones de prácticas a acceder:        |";
        cout << endl << "\t\t\t|      1: Cifrado Vernam                     |";
        cout << endl << "\t\t\t|      2: Cifrado Vigenere                   |";
        cout << endl << "\t\t\t|      3: RC4                                |";
        cout << endl << "\t\t\t|      4: A5                                 |";
        cout << endl << "\t\t\t|      5: AES-------------(NA)---------------|";
        cout << endl << "\t\t\t|      6: Diffie - Hellman                   |";
        cout << endl << "\t\t\t|      7: Fiat - Shamir                      |";
        cout << endl << "\t\t\t|      8: RSA-------------(NA)---------------|";
        cout << endl << "\t\t\t|      9: Certificado SSL-(NA)---------------|";
        cout << endl << "\t\t\t|     10: EXIT / SALIR                       |";
        cout << endl << "\t\t\t==============================================";
        cout << endl << "\t\t--NA = Not Avalaible";
        
        cout << endl << endl;
        
        cout << "Introduzca el número de la práctica a acceder, o 10 para salir:" << endl;
        cin  >> aux;
        
        system("clear");
        
        if (aux == 1)
        {
            system ("cd P1/; ./a.out");
        }
        else
        {
            if (aux == 2)
            {
                system ("cd P2/; ./a.out");
            }
            else
            {
                if (aux == 3)
                {
                    system ("cd P3/; ./a.out");
                }
                else
                {
                    if (aux == 4)
                    {
                        system ("cd P4/; ./a.out");
                    }
                    else
                    {
                        if (aux == 6)
                        {
                            system ("cd P6/; ./a.out");
                        }
                        else
                        {
                            if (aux == 7)
                            {
                                system ("cd P7/; ./a.out");
                            }
                        }
                    }
                }
            }
        }
    }
}