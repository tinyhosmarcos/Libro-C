
#include <stdio.h>
#define MAXIMO 50
#define FALSE 0
#define TRUE 1
using namespace std;

int palindrome(char *ptr_v,int counter){
	int x=(int)counter/(int)2;
	for(int i=0;i<=x;i++){
		counter--;
		if (*(ptr_v+i)!=*(ptr_v+counter)){
			return FALSE;
		}
		
	}
	return TRUE;
}

int main() {
	char palabra[MAXIMO];
	char *ptr_word=&palabra[0];
	int ingresar;
	int counter=0;
	while((ingresar=getchar())!='\n'){
		*(ptr_word+counter)=ingresar;
		counter++;
	}
	*(ptr_word+counter)='\0';

	printf("%d",palindrome(ptr_word,counter));
	
	return 0;
}

