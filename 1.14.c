#include <stdio.h>
#define ASCII 257
int main(){
	int caracteres[ASCII]={0};
	int ingresar=getchar();
	
	while(ingresar!=EOF){
		caracteres[ingresar]++;
		ingresar=getchar();
	}
	
	for (int i=0; i<ASCII;i++){
		if(caracteres[i]!=0){
			printf("%c	",i);
			for (int j=0; j<caracteres[i]; j++)
				printf("-");
			printf("\n");
		}
	}
	
	
	
	
}
