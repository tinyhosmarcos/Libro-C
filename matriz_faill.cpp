#include<stdio.h>
#include<stdlib.h>
int menu();
void leerv(int t,int *a);
void sumarv(int t,int *a);
void imprv(int t,int *a);
void leerm(int f,int c,int **a);
void imprm(int f,int c,int **a);
void sumam(int f,int c,int **a,int **b);
void multim(int m,int s,int **b,int **d,int **e);
int menu(){
	int x;
	do{
		printf("\tMENU\n");
		printf(" 1.- Suma de Vectores\n");
		printf(" 2.- Suma de Matrices\n");
		printf(" 3.- Multiplicacion de Matrices\n");
		printf(" 4.- Salir\n");
		printf(" Elige una opcion => ");
		scanf("%d",&x);
	}while(x<1&&x>4);
	return x;
}
void leerv(int t,int *a){
	for(int i=0;i<t;i++){
		printf("[%d]= ",i);
		scanf("%d",&a[i]);    
	}
}
void sumarv(int t,int *a,int *b){
	for(int i=0;i<t;i++){
		a[i]=a[i]+b[i];
	}
}
void imprv(int t,int *a){
	for(int i=0;i<t;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void leerm(int f,int c,int **a){
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			printf("[%d][%d] = ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void imprm(int f,int c,int **a){
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			printf("%d\t",*(*(a+i)+j));
		}
		printf("\n");
	}
}
void sumam(int f,int c,int **a,int **b){
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			a[i][j]=a[i][j]+b[i][j];
		}
	}
}
void multim(int m,int n,int s,int **b,int **d,int **e){
	for(int i=0;i<m;i++){
		for(int j=0;j<s;j++){
			for(int k=0;k<n;k++){
				e[i][j]=e[i][j]+b[i][k]*d[k][j];
			}
		}
	}
}
int main(){
	int c,f,i,j,x,t,m,n,q,s;
	int *a,**b,**e,*d,**g;
	x=menu();
	switch(x){
	case 1: printf("\nDame el tamaño del Vector = ");
	scanf("%d",&t);
	a=(int *)malloc(sizeof(int)*t);
	d=(int *)malloc(sizeof(int)*t); 
	printf("\nElementos del Vector A\n");
	leerv(t,a);
	printf("\nElementos del Vector B\n");
	leerv(t,d);
	printf("\nVector A\t");
	imprv(t,a);
	printf("Vector B\t");
	imprv(t,d);
	sumarv(t,a,d);
	printf("\n\tSuma=\t");
	imprv(t,a);
	break;
	case 2: printf("\nDame el Numero de Filas de la Matriz = ");
	scanf("%d",&f);
	printf("\nDame  el Numero de Columnas de la Matriz = ");
	scanf("%d",&c);
	b=(int **)malloc(sizeof(int *)*f);
	e=(int **)malloc(sizeof(int *)*f);
	for(j=0;j<c;j++){
		b[j]=(int *)malloc(sizeof(int)*c);
		e[j]=(int *)malloc(sizeof(int)*c);
	}
	printf("\nElementos de la Matriz A\n");
	leerm(f,c,b);
	printf("\nElementos de la Matriz B\n");
	leerm(f,c,e);
	printf("\n Matriz A\n");
	imprm(f,c,b);
	printf("\n Matriz B\n");
	imprm(f,c,e);
	sumam(f,c,b,e);
	printf("\nSuma es\n");
	imprm(f,c,b);
	break;
	case 3: do{
		printf("Numero de Filas de la Matriz A = ");
		scanf("%d",&m);
		printf("Numero de Columnas de la Matriz A = ");
		scanf("%d",&n);
		printf("Numero de Filas de la Matriz B = ");
		scanf("%d",&q);
		printf("Numero de Columnas de la Matriz B = ");
		scanf("%d",&s);
	}while(n!=q);
	b=(int **)malloc(sizeof(int *)*m);
	e=(int **)malloc(sizeof(int *)*q);
	g=(int **)malloc(sizeof(int *)*m);
	for(j=0;j<n;j++){
		b[j]=(int *)malloc(sizeof(int)*n);
	}
	for(j=0;j<s;j++){
		e[j]=(int *)malloc(sizeof(int)*s);
		g[j]=(int *)malloc(sizeof(int)*s);
	}
	for(i=0;i<m;i++){
		for(j=0;j<s;j++){
			g[i][j]=0;
		}
	}
	printf("\nElemetos de la Matriz A\n");
	leerm(m,n,b);
	printf("\nElementos de la Matriz B\n");
	leerm(q,s,e);
	multim(m,n,s,b,e,g);
	printf("\n");
	imprm(m,s,g);
	break;
	}  
	getchar();
}
