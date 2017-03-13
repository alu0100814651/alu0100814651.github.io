#include "A5.hpp"

using namespace std;

a5::a5 ():
v1_(0),
v2_(0),
v3_(0)
{}

a5::a5 (vector<bool> v1, vector<unsigned int> datos_v1, vector<bool> v2, vector<unsigned int> datos_v2, vector<bool> v3 , vector<unsigned int> datos_v3):
v1_(v1),
v2_(v2),
v3_(v3),
datos_v1_(datos_v1),
datos_v2_(datos_v2),
datos_v3_(datos_v3)
{}

a5::~a5() {

}

unsigned int a5::calculo () {
	
	if (((v1_[datos_v1_.back()-1] == 1) && (v2_[datos_v2_.back()-1] == 1) && (v3_[datos_v3_.back()-1] == 1)) || ((v1_[datos_v1_.back()-1] == 0) && (v2_[datos_v2_.back()-1] == 0) && (v3_[datos_v3_.back()-1] == 0))) {
		return 123;
	}
	else if (((v1_[datos_v1_.back()-1] == 1) && (v2_[datos_v2_.back()-1] == 1) && (v3_[datos_v3_.back()-1] == 0)) || ((v1_[datos_v1_.back()-1] == 0) && (v2_[datos_v2_.back()-1] == 0) && (v3_[datos_v3_.back()-1] == 1))) {
		return 12;
	}
	else if (((v1_[datos_v1_.back()-1] == 1) && (v2_[datos_v2_.back()-1] == 0) && (v3_[datos_v3_.back()-1] == 0)) || ((v1_[datos_v1_.back()-1] == 0) && (v2_[datos_v2_.back()-1] == 1) && (v3_[datos_v3_.back()-1] == 1))) {
		return 23;
	}
	else {
		return 13;
	}
}

bool a5::generar () {
	unsigned int registro_mover = calculo ();
	bool aux, aux1, aux2, aux3;

	if (registro_mover != 123 && registro_mover != 12 && registro_mover != 23 && registro_mover != 13)
		cout << "\tREGISTRO ERRONEO!" << endl;
	else {
		aux = v1_.back() ^ v2_.back() ^ v3_.back();
		aux1 = v1_[datos_v1_[0]-1];
		aux2 = v2_[datos_v2_[0]-1];
		aux3 = v3_[datos_v3_[0]-1];
		cout << endl << "\t===============================================================" << endl;
		cout << "\t" << v1_.back() << " ^ " << v2_.back() << " ^ " << v3_.back() << " = " << aux << endl;

	}
	if (registro_mover == 123) {
	    
		for (int i = 1; i < datos_v1_.size()-1; i++) {
		    aux1 = aux1 ^ v1_[datos_v1_[i]-1];
		}
			
		for (int i = 1; i < datos_v2_.size()-1; i++) {
			aux2 = aux2 ^ v2_[datos_v2_[i]-1];
		}

		for (int i = 1; i < datos_v3_.size()-1; i++) {
			aux3 = aux3 ^ v3_[datos_v3_[i]-1];
		}

		v1_.erase(v1_.end());
		v1_.insert(v1_.begin(), aux1);
		v2_.erase(v2_.end());
		v2_.insert(v2_.begin(), aux2);
		v3_.erase(v3_.end());
		v3_.insert(v3_.begin(), aux3);
		cout << "\tSe mueven todos los registros." << endl;
		cout << "\tEn el registro 1 insertamos: " << aux1 << endl;
		cout << "\tEn el registro 2 insertamos: " << aux2 << endl;
		cout << "\tEn el registro 3 insertamos: " << aux3 << endl;
	}
	else if (registro_mover == 12) {
		
		for (int i = 1; i < datos_v1_.size()-1; i++) {
			aux1 = aux1 ^ v1_[datos_v1_[i]-1];
		}
		
		for (int i = 1; i < datos_v2_.size()-1; i++) {
			aux2 = aux2 ^ v2_[datos_v2_[i]-1];
		}

		v1_.erase(v1_.end());
		v1_.insert(v1_.begin(), aux1);
		v2_.erase(v2_.end());
		v2_.insert(v2_.begin(), aux2);
		cout << "\tSe mueven los registros 1 y 2." << endl;
		cout << "\tEn el registro 1 insertamos: " << aux1 << endl;
		cout << "\tEn el registro 2 insertamos: " << aux2 << endl;
	}
	else if (registro_mover == 13) {

		for (int i = 1; i < datos_v1_.size()-1; i++) {
			aux1 = aux1 ^ v1_[datos_v1_[i]-1];
		}

		for (int i = 1; i < datos_v3_.size()-1; i++) {
			aux3 = aux3 ^ v3_[datos_v3_[i]-1];
		}

		v1_.erase(v1_.end());
		v1_.insert(v1_.begin(), aux1);
		v3_.erase(v3_.end());
		v3_.insert(v3_.begin(), aux3);
		cout << "\tSe mueven los registros 1 y 3." << endl;
		cout << "\tEn el registro 1 insertamos: " << aux1 << endl;
		cout << "\tEn el registro 3 insertamos: " << aux3 << endl;
	}
	else {

		for (int i = 1; i < datos_v2_.size()-1; i++) {
			aux2 = aux2 ^ v2_[datos_v2_[i]-1];
		}

		for (int i = 1; i < datos_v3_.size()-1; i++) {
			aux3 = aux3 ^ v3_[datos_v3_[i]-1];
		}

		v2_.erase(v2_.end());
		v2_.insert(v2_.begin(), aux2);
		v3_.erase(v3_.end());
		v3_.insert(v3_.begin(), aux3);
		cout << "\tSe mueven los registros 2 y 3." << endl;
		cout << "\tEn el registro 2 insertamos: " << aux2 << endl;
		cout << "\tEn el registro 3 insertamos: " << aux3 << endl;
	}
	
	return aux;
}

void a5::imprimir_datos () {
	cout << "\t-----------------------------LFSR's----------------------------" << endl;
	cout << "\tEl vector 1 es: ";
	for (int i = 0; i < v1_.size(); i++) {
	    if (i == 8) {
	        cout << "\"" << v1_[i] << "\" ";
	    }
	    else {
		cout << v1_[i] << " ";
	    }
	}
	cout << endl << "\tEl vector 2 es: ";
	for (int i = 0; i < v2_.size(); i++) {
		if (i == 10) {
	        cout << "\"" << v2_[i] << "\" ";
	    }
	    else {
		cout << v2_[i] << " ";
	    }
	}
	cout << endl << "\tEl vector 3 es: ";
	for (int i = 0; i < v3_.size(); i++) {
		if (i == 10) {
	        cout << "\"" << v3_[i] << "\" ";
	    }
	    else {
		cout << v3_[i] << " ";
	    }
	}
	cout << endl;
}
