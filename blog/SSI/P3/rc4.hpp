#include <vector>
#include <iostream>

using namespace std;

class rc4 {

	private:
		vector<unsigned char> S_;
		vector<unsigned char> K_;
		vector<unsigned char> secuencia_;
		int i_,j_,k_;
		unsigned z_;

	public:
		rc4 ();
		rc4(vector<unsigned char> semilla);
		~rc4 ();
		unsigned char prga ();
		vector<unsigned char> cifrar (vector<unsigned char> mensaje);
		vector<unsigned char> secuencia ();
		void imprimir ();
		
		vector<unsigned char> cifrar_spritz (vector<unsigned char> mensaje);
		unsigned char prga_spritz ();

};

