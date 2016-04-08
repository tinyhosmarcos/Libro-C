#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 10
#define TRUE 1
#define FALSE 0
int normalizar_letras(int input){
		return (input-32);
	
	
}
int main(){
	int ingresar;
	char input_hex[MAXIMO];
	char *p;
	int num_hexa;
	int contador_entrada,contador_bucle;
	contador_entrada=contador_bucle=0;
	
	while((ingresar=getchar())!='\n'){
		if (ingresar>='A' && ingresar<='F'){
			contador_entrada++;
		}
		if (ingresar>='a' && ingresar<='f'){
			ingresar=normalizar_letras(ingresar);
			contador_entrada++;
		}
		if (ingresar>='0' && ingresar<='9'){
			contador_entrada++;
		}
		if (contador_entrada==1){
			input_hex[contador_bucle]=ingresar;
			contador_bucle++;
		}
		contador_entrada=0;
	}
	
	input_hex[contador_bucle]='\0';
	num_hexa=strtol(input_hex, &p, 16);
	printf("%d",num_hexa);
	return 0;
}

