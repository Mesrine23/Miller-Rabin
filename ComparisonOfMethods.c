/* Εργασια 1 */

#include <stdio.h>
#include <time.h>
#define MINNUM 3990000000
#define MAXNUM 4010000000

int main()
{
  // Εναρξη ΝΤΕΤΕΡΜΙΝΙΣΤΙΚΟΥ τροπου
  
  	clock_t start_t, end_t;																// Δημιουργια clock 
	double total_t;

	unsigned short divider,tfD;															// Δηλωσεις Μεταβλητων τυπου unsigned short
	unsigned int numberD,square,totalD=0;												// Δηλωσεις Μεταβλητων τυπου unsigned int 
						
	start_t = clock();																	// Εναρξη της clock για τη χρονομετρηση της loopας 
	
	for (numberD=(MINNUM+1) ; numberD<=(MAXNUM-1) ; numberD+=2)							// Εναρξη loopας για number=3990000001 (γιατι θελουμε μονο περιττους).
	{
		tfD=0;																			// tf = TrueFalse, μεταβλητη -φρουρος- που παιρνει την τιμη "1" αν βρει εστω και εναν διαιρετη και σπαει τη loopα 
		
		if (numberD%3==0)																// Ελεγχος αν διαιρειται τελεια με το 3 
		{
			tfD=1;																		// Αν διαιρειται τελεια με το 3 τοτε το tf=1 και σπαει η επαναληψη και αρα ο number δεν ειναι πρωτος 
		}
		else
		{
			divider = 5;																// Ο επομενος διαιρετης που θα εξετασουμε ειναι ο 5 γιατι δεν εχει νοημα να check-αρουμε το 4 αφου οι αριθμοι ειναι περιττοι 
			square = 25;																// square = divider ^ 2, μια μεταβλητη που μας βοηθαει να συνεχισουμε στην loopα που ερχεται η να βγουμε απο αυτη  
			
			while (tfD==0 && square<=numberD)											// Η συνθηκη σπαει αν το tf=1 δηλαδη αν εχει βρει διαιρετη ή οταν το square γινει μεγαλυτερο απο το number (θεωρημα με ριζα) 
			{
				
				if (numberD%(divider+2)==0)												// Ελεγχουμε αν η διαιρεση ειναι τελεια 
				{
					tfD=1;																// Αν ειναι τοτε "ενεργοποιουμε" τη μεταβλητη-φρουρο 
				}
				else if (numberD%(divider)==0)											// Γινεται η ιδια διαδικασια αν η διαιρεση δεν ειναι τελεια αλλα με το διαιρετη αυξημενο κατα 2
				{
					tfD=1;																// Ενεργοποιηση της μεταβλητης-φρουρο 
				}
				else 
				{
					divider += 6;														// Η αυξηση του διαιρετη κατα 6 (και κατα 2 σε καθε συνθηκη) προκυπτει απο μια παρατηρηση για τους πρωτους αριθμους 
					square = divider * divider;											// Υπολογιζουμε το τετραγωνο του νεου διαιρετη για να δουμε αν ικανοποιειται η συνθηκη της loopας 
				}
				
			}
		}
		
		if (tfD==0)																		// Σε περιπτωση που η μεταβλητη φρουρος δεν εχει παρει την τιμη "1" σημαινει οτι δεν βρεθηκε κανενας καταλληλος διαιρετης 
		{
			++totalD;																	// Αν ισχυει η παραπανω συνθηκη τοτε αυξανεται το πληθος των πρωτον κατα 1 μοναδα 													
		}
		
	}
	end_t = clock();																	// Ληξη της χρονομετρησης του προγραμματος (loopας) μας 
	
	
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;								// Υπολογιζουμε τον χρονο εκτελεσης της loopας μας (τελος - αρχη) / clocks_per_sec

	
	// Ληξη ΝΤΕΤΕΡΜΙΝΙΣΤΙΚΟΥ τροπου
	
	
	
	// Εναρξη MILLER-RABIN τροπου
	
	clock_t start2_t, end2_t;															// Δημιουργεια της clock 
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
		while (tf==0) 																	// στη loopα αυτη βρισκουμε το r,d 
		{																
			d=(number-1)/t;
			if (d%2==0)
			{
				t *= 2; 																// t = 2^r                                       
				++r;
			}
			else 
			{
				tf=1;																	// Αν ο d ειναι περιττος τοτε το tf (μεταβλητη-φρουρος) γινεται 1 και σπαει η loopα
			}
		}
		
		tfN=0;																			// tfN=TrueFalseNumber : ειναι μια μεταβλητη φρουρος η οποια οσο ειναι 0 σημαινει οτι ο αριθμος ειναι πρωτος ενω αν γινει 1 ειναι συνθετος
		k=d;																			// k=d γιατι θα επεξεργαστουμε την k και θα αλλαξει η τιμη της (ενω θελουμε η τιμη του d να παραμεινει ιδια)
		x = 1;																			// x = a^d mod number
		a = a % number;																	// το a ειναι η βαση και στην προκειμενη περιπτωση α=2
		
		while (k>=1)																	// εναρξη loopας που θα μας βοηθησει να υπολογισουμε το x χωρις να γινει overflow (Modular Exponentiation)
		{
			if (k % 2 == 1)
			{
				x = (x*(unsigned long long)a) % number;
			}
			k = k / 2;
			a = ((unsigned long long)a * (unsigned long long)a) % number;
		}
		
		if (x==1)																		// Αν το χ=1 η χ=n-1 τοτε πηγαινουμε στο επομενο α (α=7)
		{
			a=7;
		}
		else if (x==number-1)															// Ο λογος που δεν χρησιμοποιηθηκε το or (||) ειναι γιατι αν χ=1 δε χρειαζεται να ελεγξει και τη συνθηκη x==n-1
		{
			a=7;
		}
		else																			// Αν δεν ισχυει καμια απο τις ζητουμενες συνθηκες
		{
			i=1;																		// i = μετρητης για τη while 
			tf=0;																		// tf = μεταβλητη φρουρος που γινεται "1" και σταματαει τη while οταν και αν το χ=n-1
			while (i<=(r-1) && tf==0)							
			{
				x = (unsigned long long)(x*x) % (unsigned long long)number;				// Υπολογιζουμε το x = x^2 mod n
				if (x==(number-1))														// Αν ικανοποιειται η συνθηκη τοτε ελεγχουμε το επομενο α
				{
					tf=1;
					a=7;
				}
				else
				{
					++i;
				}
			}
			if (tf==0)																	// Αν δεν ισχυει καμια απο τις παραπανω συνθηκες (δηλ χ<>1 και χ<>n-1 τοτε ο αριθμος ειναι συνθετος και δε χρειαζεται καν να ελεγξουμε τα αλλα "α"
			{
				tfN=1;																	// tfN = TrueFalseNumber = μεταβλητη φρουρος που μας δειχνει αν ο αριθμος ειναι συνθετος η πρωτος
			}
		}
		
		// για α=7 και α=61 ισχυουν οσα γραψαμε για α=2
		
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
		
		if (tfN==0)																		// Αν το tfN εχει παραμεινει 0 για καθε "α" τοτε ο αριθμος ειναι πρωτος																	
		{
			++total;																	// Αν ισχυει η συνθηκη αυξανουμε κατα μια μοναδα το πληθος των πρωτων
		}
		
	}
	end2_t = clock();																	// σταματαμε την clock
		
	total2_t = (double)(end2_t - start2_t) / CLOCKS_PER_SEC;							// υπολογιζουμε τον τελικο χρονο με την ιδια μεθοδο που καναμε και στο ντετερμινιστικο κομματι του κωδικα
	
	// Ληξη MILLER-RABIN τροπου
	
	printf ("Deterministic algorithm: Found %d primes in %f secs\n",totalD,total_t);	// Τυπωνουμε τη λυση για το Ντετερμινιστικο τροπο
	printf ("Miller-Rabin algorithm: Found %d primes in %f secs",total,total2_t);		// Τυπωνουμε τη λυση για τον Miller-Rabin τροπο
		
}
