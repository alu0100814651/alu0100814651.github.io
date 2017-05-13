#include "FS.hpp"

FS::FS()
{}

FS::FS (boost::multiprecision::mpz_int p, boost::multiprecision::mpz_int q, boost::multiprecision::mpz_int s)
{
	if (lehman (p)) //lehman comprueba si p es primo
	{
		p_ = p;
	}
	else
	{
		cout << "p: " << p << ", no es primo." << endl;
	}

	if (lehman (q)) //lehman comprueba si q es primo
	{
		q_ = q;
	}
	else
	{
		cout << "q: " << q << ", no es primo." << endl;
	}

	n_ = (p_) * (q_);

	if (euclides (n_, s, false) == 1) //Compruba si ambos son coprimos
	{
		s_ = s;
	}
	else
	{
		if (0 > s || n_ < s)
		{
			cout << "s: " << s << ", no se encuentra entre 0 y " << n_ << endl;
		}
		else
		{
			cout << "s: " << s << ", no es coprimo con " << n_ << endl;
		}
	}

	v_ = exp_rapida (s_, 2, n_); //s_ = base;	2 = exponente;	n_ = modulo
	x_ = 0;
}

FS::~FS ()
{}

boost::multiprecision::mpz_int FS::euclides (boost::multiprecision::mpz_int a, boost::multiprecision::mpz_int b, bool modo)
{
	boost::multiprecision::mpz_int z_1 = 0, z0 = 1, aux_z = z0;
	boost::multiprecision::mpz_int x0 = a, x1 = b, aux = b;

	while (x1 > 0)
	{
		z0 = (-x0 / x1) * z0 + z_1;
		z_1 = aux_z;
		aux_z = z0;

		x1 = (x0 % x1);
		x0 = aux;
		aux = x1;
	}

	if (x0 != 1)
	{
		cout << "Estos números no son coprimos" << endl;
	}
	else
	{
		if (modo)
		{
			if (z_1 < 0)
				return ((z_1 % a + a) % a);
			else
				return z_1;
		}
		else
			return x0;
	}
}

bool FS::lehman (boost::multiprecision::mpz_int p)
{
	vector<boost::multiprecision::mpz_int> ai (100);
	bool es_primo = true;

	for (int i = 0; i < ai.size (); i++)
	{
		ai[i] = aleatorio (1, p-1);
	}
	for (int i = 0; i < ai.size () && es_primo; i++)
	{
		if ((exp_rapida (ai[i], ((p - 1) / 2), p)) != 1 && (exp_rapida (ai[i], ((p - 1) / 2), p)) != p - 1)
		{
			es_primo = false;
		}
	}
	return es_primo;
}

boost::multiprecision::mpz_int FS::aleatorio (boost::multiprecision::mpz_int rg_1, boost::multiprecision::mpz_int rg_2)
{
	uint64_t rgg_1 = uint64_t (rg_1);
	uint64_t rgg_2 = uint64_t (rg_2);

	random_device rd; // obtain a random number from hardware
    mt19937 eng (rd ()); // seed the generator (http://www.cplusplus.com/reference/random/mersenne_twister_engine/)
    uniform_int_distribution<> distr (rgg_1, rgg_2); // define the range
    return distr (eng);
}

boost::multiprecision::mpz_int FS::exp_rapida (boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_, boost::multiprecision::mpz_int modulo)
{
	boost::multiprecision::mpz_int x = 1;
	boost::multiprecision::mpz_int b = exp_;
	boost::multiprecision::mpz_int y = base % modulo; //base es alfa

	while (b > 0 && y > 1)
	{
		if (b % 2 == 1)
		{
			x = (x * y) % modulo;
			b--;
		}
		else
		{
			y = (y * y) % modulo;
			b = b / 2;
		}
	}
	return x;
}

boost::multiprecision::mpz_int FS::get_n ()
{
	return n_;
}

boost::multiprecision::mpz_int FS::get_v ()
{
	return v_;
}

boost::multiprecision::mpz_int FS::get_a ()
{
	return exp_rapida (x_, 2, n_);
}

boost::multiprecision::mpz_int FS::get_x ()
{
	return x_;
}

boost::multiprecision::mpz_int FS::get_y (boost::multiprecision::mpz_int e)
{
	if (e != 0 && e != 1)
	{
		cout << "e: " << e << ", no es un bit" << endl;
	}

	if (e == 0)
		return exp_rapida (x_, 1, n_); //x_ = base; 1 = exponente; n_ = modulo
	else
		return exp_rapida ((x_ * s_), 1, n_); //(x_ * s_*) = base; 1 = exponente; n_ = modulo
}

void FS::set_x (boost::multiprecision::mpz_int x)
{
	if (0 > x || n_ < x)
	{
		cout << "x: " << x << ", no se encuentra entre 0 y " << n_ << endl;
	}
	x_ = x;
}

boost::multiprecision::mpz_int FS::pow_multiprecision (boost::multiprecision::mpz_int base, boost::multiprecision::mpz_int exp_)
{
	// (base)^(exponente)
	//En el caso de la verificación, se hace y^2
	boost::multiprecision::mpz_int resultado = 1;

	for (boost::multiprecision::mpz_int i = 0; i < exp_; i++)
	{
		resultado = resultado * base;
	}
	
	return resultado;
}

bool FS::verificacion (boost::multiprecision::mpz_int y, boost::multiprecision::mpz_int a, boost::multiprecision::mpz_int v, boost::multiprecision::mpz_int n, boost::multiprecision::mpz_int e)
{
	if (e == 0)
		return exp_rapida ((pow_multiprecision (y, 2)), 1, n) == exp_rapida (a, 1, n);
	else
		return exp_rapida ((pow_multiprecision (y, 2)), 1, n) == exp_rapida ((a * v), 1, n);
}