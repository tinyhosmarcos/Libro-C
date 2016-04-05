#include<stdio.h>

int main(){
	int condicion = 0; 
	int ingresar;
	while( (ingresar = getchar()) != EOF )
	{
		
		if (0 == condicion){ 
			if ( ingresar != '/') 
				printf("%c",ingresar);
			else{ 
				ingresar = getchar();
				
				if ( '*' == ingresar )
					condicion = 1;
				else{
					printf("/");
					printf("%c",ingresar);
				} 
			} 
		}  
		if (1 == condicion){ 
			if ( '*' == ingresar)
				if ((ingresar = getchar()) == '/')
			condicion = 0;
		}  
	}
	
	return 0;
}  
