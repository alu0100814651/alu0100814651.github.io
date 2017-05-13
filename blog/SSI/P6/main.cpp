#include "DH.hpp"

using namespace std;

int main (void){
	int opt = 1;
	int usu = 1;
	while (opt != 0)
	{
		system("clear");
		cout << "¿Desean conectarse 2 usuarios (1) o más (2)?" << endl;
		cin >> usu;
		if (usu == 1) {
			unsigned primo = 0;
			unsigned alfa = 0;
			unsigned secreto_a = 0;
			unsigned secreto_b = 0;
			cout << "Introduzca el p a utilizar:" << endl;
			cin >> primo;
			
			cout << "Introduzca el α a utilizar:" << endl;
			cin >> alfa;
			
			cout << "El secreto del usuario A es:" << endl;
			cin >> secreto_a;
			
			cout << "El secreto del usuario B es:" << endl;
			cin >> secreto_b;
			
			DH A (primo, alfa, secreto_a);
			DH B (primo, alfa, secreto_b);
		
		    cout << endl << "\t\t\t==============================================";
			cout << endl << "\t\t\t-----------------DIFFIE-HELLMAN---------------";
		    cout << endl << "\t\t\t==============================================";
		    cout << endl;
			cout << "p = " << primo << "     ";
			cout << "α = " << alfa << "     ";
			cout << "xA = " << A.get_secreto () << "     ";
			cout << "xB = " << B.get_secreto () << "     " << endl;
			cout << "(" << alfa << " ^ " << A.get_secreto () << " ) mod " << primo << " = " << A.get_y () << "     ";
			cout << "(" << alfa << " ^ " << B.get_secreto () << " ) mod " << primo << " = " << B.get_y () << "     " << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			cout << "(" << B.get_y () << " ^ " << A.get_secreto () << " ) mod " << primo << " = " << A.exp_rapida (B.get_y (), A.get_secreto ()) << "     ";
			cout << "(" << A.get_y () << " ^ " << B.get_secreto () << " ) mod " << primo << " = " << B.exp_rapida (A.get_y (), B.get_secreto ()) << "     " << endl;
			
		}

		else {
			unsigned pers;
			unsigned primo_2;
			unsigned alfa_2;
			cout << "Introduzca la cantidad de personas a comunicar:" << endl;
			cin >> pers;
			cout << "Introduzca el p a utilizar:" << endl;
			cin >> primo_2;
			cout << "Introduzca el α a utilizar:" << endl;
			cin >> alfa_2;

			unsigned secreto_2[pers];
			DH Personas_[pers];

			for (int i = 0; i < pers; i++)
			{
				cout << "El secreto del usuario " << i+1 << " es: ";
				cin >> secreto_2[i];
				Personas_[i].set (primo_2, alfa_2, secreto_2[i]);
				cout << endl << "=====> " << Personas_[i].get_y () << endl;
			}
			cout << "=====" << endl;

			unsigned aux;

			for (int i = 0; i < pers; i++)
			{
				aux = Personas_[i + 1].exp_rapida (Personas_[i].get_y (), secreto_2[i + 1]);
			
				cout << Personas_[i].get_y () << endl;
			
				Personas_[i].set_y (aux);
			
				cout << "====> " << Personas_[i].get_y () << endl;
			}

			cout << "K: " << Personas_[pers - 1].exp_rapida (Personas_[pers - 2].get_y (), secreto_2[pers - 1]) << endl;
		}

		cout << endl << "Quiere realizar otra consulta? SI(1) NO(0)" << endl;
		cin >> opt;
	}
}