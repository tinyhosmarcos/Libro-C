#include <stdio.h>
#define MAXLINE 1000

int getline(char line[],int maxline);

int main(){
	int len;
	char line[MAXLINE]; /* línea de entrada actual */
	while ((len = getline(line, MAXLINE)) > 0)
		printf("%s",line);
	
}
int getline(char s[], int lim){
	int c, i;
	for (i = 0; i<lim-1 && (c = getchar( )) !=EOF && c!='\n'; i++) {
		if (c!=' ')
			s[i] = c;
		else
			i--;
			
	} 
	if (c == '\n'){ 
		if(s[i-1]==' ' || s[i-1]=='\t'){
			s[i-1]='\n';
		}
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
