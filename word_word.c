#include <stdio.h>
int main(){
	
	int space=0,tab=0,blink=0;
	int ingresar=getchar();
	
	while(ingresar!=9){
		
		if (ingresar==32)
			printf("\n");
		else
			printf("%c",ingresar);
		ingresar=getchar();
	}		
	return 0;
	
	
	
}
