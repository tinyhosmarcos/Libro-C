#include <stdio.h>
#include <limits.h>


int main(void)
{
	printf("El rango de caracter va de	%d	hasta	%d\n",SCHAR_MIN,SCHAR_MAX);
	printf("El rango de entero va de	%d	hasta	%d\n",INT_MIN,INT_MAX);
	printf("El rango de short va de	%d	hasta	%d\n",SHRT_MIN,SHRT_MAX);
	printf("El rango de entero va de	%d	hasta	%d\n",INT_MIN,INT_MAX);
	printf("El rango de entero va de	%ld	hasta	%ld\n",LONG_MIN,LONG_MAX);
	printf("El rango de un unsigned char llega hasta %u	\n",(unsigned) UCHAR_MAX);
	printf("El rango de un unsigned short llega hasta %u\n",(unsigned) USHRT_MAX);
	printf("Maximo valor del tipo signed char  %d\n", SCHAR_MAX);        
	printf("Minimo valor del typo signed char  %d\n\n", SCHAR_MIN);     
	
	
	
	return 0;
}
