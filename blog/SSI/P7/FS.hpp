#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <ctype.h>
#include <boost/multiprecision/gmp.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

class FS
{
	private:
		boost::multiprecision::mpz_int p_;
		boost::multiprecision::mpz_int q_;
		boost::multiprecision::mpz_int s_;
		boost::multiprecision::mpz_int n_;
		boost::multiprecision::mpz_int v_;
		boost::multiprecision::mpz_int x_;
	
	public:
		FS ();
		FS (boost::multiprecision::mpz_int p, boost::multiprecision::mpz_int q, boost::multiprecision::mpz_int s);
		~FS ();
		
		boost::multiprecision::mpz_int euclides (boost::multiprecision::mpz_int a, boost::multiprecision::mpz_int b, bool modo);
		bool lehman (boost::multiprecision::mpz_int p);
		boost::multiprecision::mpz_int aleatorio (boost::multiprecision::mpz_int rg_1, boost::multiprecision::mpz_int rg_2);
		boost::multiprecision::mpz_int exp_rapida (boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_, boost::multiprecision::mpz_int modulo);
		
		boost::multiprecision::mpz_int get_n ();
		boost::multiprecision::mpz_int get_v ();
		boost::multiprecision::mpz_int get_a ();
		boost::multiprecision::mpz_int get_y (boost::multiprecision::mpz_int e);
		boost::multiprecision::mpz_int get_x ();
		
		boost::multiprecision::mpz_int pow_multiprecision (boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_);
		void set_x (boost::multiprecision::mpz_int x);
		bool verificacion (boost::multiprecision::mpz_int y, boost::multiprecision::mpz_int a, boost::multiprecision::mpz_int v, boost::multiprecision::mpz_int n, boost::multiprecision::mpz_int e);
};