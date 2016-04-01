#include<stdio.h>

int convertir( int fahr )	{    
	return (5.0/9.0)*(fahr - 32);
}  

int main()
{      
	
	float fa, celsius;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	fa = lower;
	
	printf("	Grados Fahrenheit	||	grados Celcius\n");
	printf("				||					\n");
	
	while ( fa <= upper ){   
		celsius = convertir( fa);
		printf("	%10.0f		||	%11.1f\n", fa, celsius );
		fa = fa + step;
	}   
	
	return 0;
}       

