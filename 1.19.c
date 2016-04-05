#include <stdio.h>
#define MAXLINE 1000

int getline(char linea[],int limites);
void reverse(char line[],int maxline);

int main(){
	int len;
	char line[MAXLINE]; /* línea de entrada actual */
	while ((len = getline(line, MAXLINE)) > 0){
		reverse(line,len-1);
		
		
	} 
}
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
void reverse(char d[], int limite){
	char temporal;
	int lim=limite/2; 
	for(int i=0;i<=lim;++i){
		temporal=d[limite-i];
		d[limite-i]=d[i];
		d[i]=temporal;
		
	}
	printf("%s",d);
}
