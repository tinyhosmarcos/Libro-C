#include <iostream>
#include <stdio.h>


using namespace std;
void print(int contador,int palabra){
	printf("%d	",palabra);
	for(int i=0; i<contador;i++)
		printf("-");
	printf("\n");
	
}
int main(){
	int word=0;
	int count=0;
	int ingresar=getchar();
	
	while(ingresar!=10){
		if (ingresar==32){
			print(count,word+1);
			count=0;
			word++;}
		else
			count++;
		
		ingresar=getchar();
	}
	print(count,word+1);
	return 0;
	
}
