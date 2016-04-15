/*	Escriba la función any(sl,s2), que regresa la primera posición de
	la cadena si en donde se encuentre cualquier carácter de la cadena s2, o -1 si 
	si no contiene caracteres de s2. (La función de biblioteca estándar strpbrk hace
	el mismo trabajo pero regresa un apuntador a la posición encontrada.)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMO 50
void llenar_arrays(char llenado[]){
	int ingresar,i;
	for(i=0; i<MAXIMO && (ingresar=getchar())!='\n';i++)
		llenado[i]=ingresar;
	llenado[i]='\0';
}
int revisar_2(char comparar, char rev[]){
	for (int i=0; i < strlen(rev) ; i++){
		if (comparar==rev[i])
			return (i+1);
	}
	return 0;
}

void revisar(char rev_1[], char rev_2[]){
	int posicion=strlen(rev_2);
	int temp;
	   for (int i=0; i < strlen(rev_2) ; i++){
		   temp=revisar_2(rev_2[i],rev_1);
		   if(temp<posicion)
			   posicion=temp;
			   
	   }
	   printf("Posicion %d",posicion);
}
int main(){
	char mat_1[MAXIMO],mat_2[MAXIMO];
	llenar_arrays(mat_1);
	llenar_arrays(mat_2);
	
	printf("%s",mat_1);
	printf("%s",mat_2);
	
	revisar(mat_1,mat_2);
}
