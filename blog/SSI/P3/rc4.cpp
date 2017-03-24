#include "rc4.hpp"

using namespace std;

rc4::rc4 ():
S_(0),
K_(0),
i_(0),
j_(0),
k_(0)
{}

rc4::rc4 (vector<unsigned char> semilla):
S_(256, 0),
K_(256, 0),
i_(0),
j_(0),
k_(0)
{
	for (int i = 0; i < S_.size(); i++) {
		S_[i] = i;
		K_[i] = semilla[i % semilla.size()];

	}
	int j = 0;
	for (int i = 0; i < S_.size(); i++) {
		j = (j + S_[i] + K_[i]) % S_.size();
		swap(S_[i], S_[j]);
	}
}

rc4::~rc4() {

}

unsigned char rc4::prga () {
	unsigned t;
	i_ = (i_ + 1) % 256;
	j_ = (j_ + S_[i_]) % 256;
	swap(S_[i_], S_[j_]);
	t = (S_[i_] + S_[j_]) % 256;
	return (S_[t]);
}

vector<unsigned char> rc4::cifrar (vector<unsigned char> mensaje) {
	unsigned char cf;
	vector<unsigned char> mensaje_cifrado (mensaje.size(), 0);
	secuencia_.resize (mensaje.size(), 0);

	for (int i = 0; i < mensaje.size(); i++) {
		cf = prga ();
		secuencia_[i] = cf;
		mensaje_cifrado[i] = mensaje[i] ^ cf;
	}

	return mensaje_cifrado;
}

unsigned char rc4::prga_spritz () {
	int w = 5;
	i_ = (i_ + w) % 256;
	j_ = (k_ + S_[(j_ + S_[i_]) % 256]) % 256;
	k_ = (i_ + k_ + S_[j_]) % 256;
	swap(S_[i_], S_[j_]);
	z_ = S_[(j_ + S_[(i_ + S_[(z_ + k_) % 256]) % 256]) % 256];
	cout << z_ << endl;
	return (S_[z_]);
}

vector<unsigned char> rc4::cifrar_spritz (vector<unsigned char> mensaje) {
	unsigned char cf;
	vector<unsigned char> mensaje_cifrado (mensaje.size(), 0);
	secuencia_.resize (mensaje.size(), 0);

	for (int i = 0; i < mensaje.size(); i++) {
		cf = prga_spritz ();
		secuencia_[i] = cf;
		mensaje_cifrado[i] = mensaje[i] ^ cf;
	}

	return mensaje_cifrado;
}

vector<unsigned char> rc4::secuencia () {
	return secuencia_;
}

void rc4::imprimir () {
	cout << endl << "[";
	for (int i = 0; i < S_.size(); i++) {
		if ((i == 15) || (i == 31) || (i == 47) || (i == 63) || (i == 79) || (i == 95) || (i == 111) || (i == 127) || (i == 143) || (i == 159) || (i == 175) || (i == 191) || (i == 207) || (i == 223) || (i == 239)) {
			cout << endl;
		}
		if (i == S_.size()-1) {
			cout << int(S_[i]);
		}
		else {
			cout << int(S_[i]) << ", ";
		}
	}
	cout << "]";
}