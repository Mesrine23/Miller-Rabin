/* Miller-Rabin */

#include <stdio.h>
#include <time.h>
#define MINNUM 3990000000
#define MAXNUM 4010000000

int main()
{
	clock_t start_t, end_t;																/* Δημιουργεια της clock */
	double total_t;
	
	unsigned int tf,d,t,r,a,total=0,number,tfN,i,k;
	unsigned long long x;
	
	start_t = clock();	
	
	for (number=(MINNUM+1) ; number<=(MAXNUM-1) ; number+=2)
	{
		t=2;
		r=1;
		a=2;
		tf=0;
		while (tf==0) 												/* στη loopα αυτη βρισκουμε το r,d */
		{																
			d=(number-1)/t;
			if (d%2==0)
			{
				t *= 2;
				++r;
			}
			else 
			{
				tf=1;
			}
		}
		
		tfN=0;
		k=d;
		x = 1;
		a = a % number;	
		while (k>=1)
		{
			if (k % 2 == 1)
			{
				x = (x*(unsigned long long)a) % number;
			}
			k = k / 2;
			a = ((unsigned long long)a * (unsigned long long)a) % number;
		}
		
		if (x==1)
		{
			a=7;
		}
		else if (x==number-1)
		{
			a=7;
		}
		else
		{
			i=1;
			tf=0;
			while (i<=(r-1) && tf==0)
			{
				x = (unsigned long long)(x*x) % (unsigned long long)number;
				if (x==(number-1))
				{
					tf=1;
					a=7;
				}
				else
				{
					++i;
				}
			}
			if (tf==0)
			{
				tfN=1;
			}
		}
		
		if (tfN==0)
		{
			k=d;
			x = 1;
			a = a % number;
			
			while (k>=1)
			{
				if (k % 2 == 1)
				{
					x = (x*(unsigned long long)a) % number;
				}
				k = k / 2;
				a = ((unsigned long long)a * (unsigned long long)a) % number;
			}
			
			if (x==1) 
			{
				a=61;
			}
			else if (x==number-1)
			{
				a=61;
			}
			else
			{
				i=1;
				tf=0;
				while (i<=(r-1) && tf==0)
				{
					x = (unsigned long long)(x*x) % (unsigned long long)number;
					if (x==(number-1))
					{
						tf=1;
						a=61;
					}
					else
					{
						++i;
					}
				}
				if (tf==0)
				{
					tfN=1;
				}
			}
		}
			
		if (tfN==0)
		{
			k=d;
			x = 1;
			a = a % number;
			
			while (k>=1)
			{
				if (k % 2 == 1)
				{
				x = (x*(unsigned long long)a) % number;
				}
				k = k / 2;
				a = ((unsigned long long)a * (unsigned long long)a) % number;
			}
			a=61;
			
			if (x!=1 && x!=number-1)
			{
				if (x!=number-1)
				{
					i=1;
					tf=0;
					while (i<=(r-1) && tf==0)
					{
						x = (unsigned long long)(x*x) % (unsigned long long)number;
						if (x==(number-1))
						{
							tf=1;
						}
						else
						{
							++i;
						}
					}
					if (tf==0)
					{
						tfN=1;
					}
				}
			}
		}
		
		if (tfN==0)
		{
			++total;
		}
		
	}
	end_t = clock();
	
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	
	printf ("Found %d primes in %f secs",total,total_t);
}
