#include <stdio.h>
#define MAXLINE 1000 /* tama�o m�ximo de la l�nea de entrada */ 
int getline(char line[], int maxline);
void copy(char to[],char from[]);
/* imprime la l�nea de entrada m�s larga */ 

int main( ){
	
	int len; /* longitud actual de la l�nea */
	int max; /*Maxima longitud vista hasta el momento */
	char line[MAXLINE]; /* l�nea de entrada actual */
	char longest[MAXLINE]; /* la l�nea m�s larga se guarda aqu� */
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0){ 
		if (len > max) 
		max = len;
		copy(longest, line);
	}
	if (max >0) /* hubo una l�nea */
		printf("%s", longest); 
	return 0;
}
	 /* getline: lee una l�nea en s, regresa su longitud */
int getline(char s[], int lim){
		 
	int c, i;
	for (i = 0; i<lim-1 && (c = getchar( )) !=EOF && c!='\n'; ++i) 
		s[i] = c;
	if (c == '\n'){ 
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
	 /* copy: copia 'from' en 'to'; supone que to es suficientemente grande */
void copy(char to[], char from[]){
	int i; 
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
