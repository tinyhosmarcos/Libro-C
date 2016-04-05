# define CONDICION 0
# define ERROR -1
# define FALSO 0
# define VERDADERO 1
# define LLENA 1
# define PILAMAX 100
# define ADENTRO 1
# define AFUERA 0
# include <stdio.h>

int superior = -1; 
int pila[PILAMAX];

int empujar( int nuevo ){          
	if ( superior + 1 >= PILAMAX )
		return( LLENA);

	pila[ ++superior ] = nuevo;
	return(CONDICION);
}           


int extraer(){              
	return( pila[superior--] );
}               

int vacio(){            
	if( superior < 0 )
		return(VERDADERO);
	
	return(FALSO);
} 

int Revisa_Parentesis( int datos[]){
	int i;
	int comentario = AFUERA;
	for ( i = 0; datos[i] !=  0; i++ ){                
		
		switch( datos[i]){ 
		case '{':
		case '[':
		case '(':
			if ( AFUERA == comentario ){
				empujar( datos[i]);
				break;
		}
		case '}':
			if ( AFUERA == comentario){
				if (vacio() || extraer() != '{')
				return (ERROR);
				break;
		}
		case ']':
			if ( AFUERA == comentario ){
				if (vacio() || extraer() != '[')
					return (ERROR);
				break;
		}
		case ')':
			if ( AFUERA == comentario) {
				if (vacio() || extraer() != '(')
					return (ERROR);
				break;
			}
		case '/':
			if ( AFUERA == comentario ){	
				if ( '*' == datos[i + 1]  )
					comentario = ADENTRO;
			}
		if (ADENTRO == comentario)
			if ( '*' == datos[ i - 1])			
				comentario = AFUERA;
			break;
		}            
	}	
	if ( ADENTRO == comentario )
		return (ERROR);
	if ( vacio())
		return (CONDICION);
	
	return (ERROR);
}         


int main(){
	int cadena[PILAMAX];
	int c;
	int x = 0;
	int j;
	printf("	---Ingrese una linea de comandos, para verificar sus sintaxis---	\n");
	while( (c = getchar()) != EOF )
		
		cadena[ x++ ] = c;
	
	j = Revisa_Parentesis( cadena);
	
	if ( CONDICION == j  )
		printf("\nLa sintaxis es Correcta.\n");
	
	else
		if( ERROR == j )
			printf("\nLa sintaxis es incorrecta.\n");
	return 0;
}         
