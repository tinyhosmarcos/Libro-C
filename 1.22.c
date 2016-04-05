
#include<stdio.h>
#define COLUMNA 50
#define VALOR_TAB 8

char line[COLUMNA];

void printline(int pos){
	int limit;
	for(limit = 0; limit < pos; ++limit)
		putchar(line[limit]);
	if( pos > 0)
		printf("\n");
}

int expandir_linea(int pos){
	line[pos] = ' ';
	
	for(++pos; (pos < COLUMNA)&&((pos % VALOR_TAB)!= 0); ++pos)
		line[pos] = ' ';
	
	if( pos >= COLUMNA)
	{
		printline(pos);
		return 0;
	}
	else
		return pos;
}



int vaciar(int pos){
	if( pos > 0)
		while( line[pos] != ' ')
		--pos;
	if(pos == 0)
		return COLUMNA;
	else
		return pos + 1;
}
int reordenar( int pos){
	int i,j;
	
	if(pos <= 0 || pos >= COLUMNA)
		return 0;
	else{
		i = 0;
		for(j=pos;j < COLUMNA; ++j,++i)
			line[i] = line[j];  
	}
	return i;
}

int main(){
	int pos,c;
	pos = 0;
	
	while((c=getchar())!=EOF){
		line[pos] = c;
		
		if( c == '\t')
			pos = expandir_linea(pos);
		if( c == '\n'){
			printline(pos);
			pos = 0;
		}
		else if( ++pos >= COLUMNA ){
			pos = vaciar(pos);
			printline(pos);
			pos = reodernar(pos);
		}
	}
	return 0;
}




