#include <vector>
#include <iostream>

using namespace std;

class a5 {

    private:
    	vector<bool> v1_;
    	vector<bool> v2_;
    	vector<bool> v3_;
    	vector<unsigned int> datos_v1_;
    	vector<unsigned int> datos_v2_;
    	vector<unsigned int> datos_v3_;

    public:
    	a5 ();
    	a5 (vector<bool> v1, vector<unsigned int> datos_v1, vector<bool> v2, vector<unsigned int> datos_v2, vector<bool> v3, vector<unsigned int> datos_v3);
    	~a5 ();
    	unsigned int calculo ();
    	bool generar ();
    	void imprimir_datos ();
    	a5 (vector<bool> vector1,vector<unsigned int> datos_vector1, vector<bool> vector2,vector<unsigned int> datos_vector2, vector<bool> vector3, vector<unsigned int> datos_vector3, unsigned int mod);
	    bool generar_mod(unsigned int registro);

};