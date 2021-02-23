/* ������� 1 */

#include <stdio.h>
#include <time.h>
#define MINNUM 3990000000
#define MAXNUM 4010000000

int main()
{
  // ������ ���������������� ������
  
  	clock_t start_t, end_t;																// ���������� clock 
	double total_t;

	unsigned short divider,tfD;															// �������� ���������� ����� unsigned short
	unsigned int numberD,square,totalD=0;												// �������� ���������� ����� unsigned int 
						
	start_t = clock();																	// ������ ��� clock ��� �� ������������ ��� loop�� 
	
	for (numberD=(MINNUM+1) ; numberD<=(MAXNUM-1) ; numberD+=2)							// ������ loop�� ��� number=3990000001 (����� ������� ���� ���������).
	{
		tfD=0;																			// tf = TrueFalse, ��������� -�������- ��� ������� ��� ���� "1" �� ���� ���� ��� ���� �������� ��� ����� �� loop� 
		
		if (numberD%3==0)																// ������� �� ���������� ������ �� �� 3 
		{
			tfD=1;																		// �� ���������� ������ �� �� 3 ���� �� tf=1 ��� ����� � ��������� ��� ��� � number ��� ����� ������ 
		}
		else
		{
			divider = 5;																// � �������� ��������� ��� �� ���������� ����� � 5 ����� ��� ���� ����� �� check-������ �� 4 ���� �� ������� ����� �������� 
			square = 25;																// square = divider ^ 2, ��� ��������� ��� ��� ������� �� ����������� ���� loop� ��� ������� � �� ������ ��� ����  
			
			while (tfD==0 && square<=numberD)											// � ������� ����� �� �� tf=1 ������ �� ���� ���� �������� � ���� �� square ����� ���������� ��� �� number (������� �� ����) 
			{
				
				if (numberD%(divider+2)==0)												// ��������� �� � �������� ����� ������ 
				{
					tfD=1;																// �� ����� ���� "�������������" �� ���������-������ 
				}
				else if (numberD%(divider)==0)											// ������� � ���� ���������� �� � �������� ��� ����� ������ ���� �� �� �������� �������� ���� 2
				{
					tfD=1;																// ������������ ��� ����������-������ 
				}
				else 
				{
					divider += 6;														// � ������ ��� �������� ���� 6 (��� ���� 2 �� ���� �������) ��������� ��� ��� ���������� ��� ���� ������� �������� 
					square = divider * divider;											// ������������ �� ��������� ��� ���� �������� ��� �� ����� �� ������������� � ������� ��� loop�� 
				}
				
			}
		}
		
		if (tfD==0)																		// �� ��������� ��� � ��������� ������� ��� ���� ����� ��� ���� "1" �������� ��� ��� ������� ������� ���������� ��������� 
		{
			++totalD;																	// �� ������ � �������� ������� ���� ��������� �� ������ ��� ������ ���� 1 ������ 													
		}
		
	}
	end_t = clock();																	// ���� ��� ������������� ��� ������������ (loop��) ��� 
	
	
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;								// ������������ ��� ����� ��������� ��� loop�� ��� (����� - ����) / clocks_per_sec

	
	// ���� ���������������� ������
	
	
	
	// ������ MILLER-RABIN ������
	
	clock_t start2_t, end2_t;															// ����������� ��� clock 
	double total2_t;
	
	unsigned int tf,d,t,r,a,total=0,number,tfN,i,k;
	unsigned long long x;
	
	start2_t = clock();	
	
	for (number=(MINNUM+1) ; number<=(MAXNUM-1) ; number+=2)
	{
		t=2;
		r=1;
		a=2;
		tf=0;
		while (tf==0) 																	// ��� loop� ���� ��������� �� r,d 
		{																
			d=(number-1)/t;
			if (d%2==0)
			{
				t *= 2; 																// t = 2^r                                       
				++r;
			}
			else 
			{
				tf=1;																	// �� � d ����� �������� ���� �� tf (���������-�������) ������� 1 ��� ����� � loop�
			}
		}
		
		tfN=0;																			// tfN=TrueFalseNumber : ����� ��� ��������� ������� � ����� ��� ����� 0 �������� ��� � ������� ����� ������ ��� �� ����� 1 ����� ��������
		k=d;																			// k=d ����� �� �������������� ��� k ��� �� ������� � ���� ��� (��� ������� � ���� ��� d �� ���������� ����)
		x = 1;																			// x = a^d mod number
		a = a % number;																	// �� a ����� � ���� ��� ���� ���������� ��������� �=2
		
		while (k>=1)																	// ������ loop�� ��� �� ��� �������� �� ������������ �� x ����� �� ����� overflow (Modular Exponentiation)
		{
			if (k % 2 == 1)
			{
				x = (x*(unsigned long long)a) % number;
			}
			k = k / 2;
			a = ((unsigned long long)a * (unsigned long long)a) % number;
		}
		
		if (x==1)																		// �� �� �=1 � �=n-1 ���� ���������� ��� ������� � (�=7)
		{
			a=7;
		}
		else if (x==number-1)															// � ����� ��� ��� ��������������� �� or (||) ����� ����� �� �=1 �� ���������� �� ������� ��� �� ������� x==n-1
		{
			a=7;
		}
		else																			// �� ��� ������ ����� ��� ��� ���������� ��������
		{
			i=1;																		// i = �������� ��� �� while 
			tf=0;																		// tf = ��������� ������� ��� ������� "1" ��� ��������� �� while ���� ��� �� �� �=n-1
			while (i<=(r-1) && tf==0)							
			{
				x = (unsigned long long)(x*x) % (unsigned long long)number;				// ������������ �� x = x^2 mod n
				if (x==(number-1))														// �� ������������� � ������� ���� ��������� �� ������� �
				{
					tf=1;
					a=7;
				}
				else
				{
					++i;
				}
			}
			if (tf==0)																	// �� ��� ������ ����� ��� ��� �������� �������� (��� �<>1 ��� �<>n-1 ���� � ������� ����� �������� ��� �� ���������� ��� �� ��������� �� ���� "�"
			{
				tfN=1;																	// tfN = TrueFalseNumber = ��������� ������� ��� ��� ������� �� � ������� ����� �������� � ������
			}
		}
		
		// ��� �=7 ��� �=61 ������� ��� ������� ��� �=2
		
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
			
			if (x!=1)
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
		
		if (tfN==0)																		// �� �� tfN ���� ���������� 0 ��� ���� "�" ���� � ������� ����� ������																	
		{
			++total;																	// �� ������ � ������� ��������� ���� ��� ������ �� ������ ��� ������
		}
		
	}
	end2_t = clock();																	// ��������� ��� clock
		
	total2_t = (double)(end2_t - start2_t) / CLOCKS_PER_SEC;							// ������������ ��� ������ ����� �� ��� ���� ������ ��� ������ ��� ��� ��������������� ������� ��� ������
	
	// ���� MILLER-RABIN ������
	
	printf ("Deterministic algorithm: Found %d primes in %f secs\n",totalD,total_t);	// ��������� �� ���� ��� �� ��������������� �����
	printf ("Miller-Rabin algorithm: Found %d primes in %f secs",total,total2_t);		// ��������� �� ���� ��� ��� Miller-Rabin �����
		
}
