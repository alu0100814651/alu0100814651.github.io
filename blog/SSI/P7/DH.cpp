#include "DH.hpp"

DH::DH (void):
primo_ (1),
alfa_ (0),
secreto_ (0),
y_ (0)
{}

DH::DH (unsigned pr_, unsigned al_, unsigned sec_):
secreto_ (sec_),
y_ (0)
{
	if (al_ < pr_)
	{
		alfa_ = al_;
		if (es_primo (pr_))
		{
			primo_ = pr_;
			y_ = exp_rapida (alfa_, sec_);
		}
		else
			cout << "P no es primo" << endl;
	}
	else
		cout << "α no es menor que P" << endl;
}

DH::~DH (void)
{}

bool DH::es_primo (unsigned pr_)
{
	unsigned a = 0;

	for(unsigned i = 1; i < (pr_+1); i++)
	{
		if(pr_ % i == 0)
			a++;
	}

	if(a != 2)
		return false;
	else
		return true;
}

unsigned DH::exp_rapida (unsigned base, unsigned exp_)
{
	unsigned y = base % primo_; //base es alfa
	unsigned b = exp_;
	unsigned x = 1;
	
	while ( (b > 0) && (y > 1) )
	{
		if (b % 2 == 1)
		{
			x = (x * y) % primo_;
			b--;
		}
		else
		{
			y = (y * y) % primo_;
			b = b / 2;
		}
	}
	return x;
}

unsigned DH::get_y (void)
{
	return y_;
}

unsigned DH::get_secreto (void)
{
	return secreto_;
}