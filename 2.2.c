#include <stdio.h>

#define MAXIMO 100

int main(){
	
	int rango = 0;
	int limite=MAXIMO;
	int ingresar;
	char valores_ingresados[MAXIMO];
	for (int i=0; i<3;i++)
		printf("Hola");
	while (rango < (limite - 1)){
		
		ingresar = getchar();
		if (ingresar == EOF)
			break;
		else if (ingresar == '\n')
			break;
		valores_ingresados[rango++] = ingresar;
	}
	
	valores_ingresados[rango] = '\0';
	
	return 0;
}
