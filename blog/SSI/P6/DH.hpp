#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class DH
{
	private:
		unsigned primo_, alfa_, secreto_, y_;

	public:
		DH (void);
		DH (unsigned pr_, unsigned al_, unsigned sec_);
		~DH (void);
		
		bool es_primo (unsigned pr_);
		
		unsigned exp_rapida (unsigned base, unsigned exp_);
		
		unsigned get_y (void);
		unsigned get_secreto (void);

		void set(unsigned pr_, unsigned al_, unsigned sec_);
		void set_y(unsigned y);
};