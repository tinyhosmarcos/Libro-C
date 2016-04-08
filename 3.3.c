#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1024
#define UP(N) ((N) >= 'A' && (N) <= 'Z')
#define LO(N) ((N) >= 'a' && (N) <= 'z')
#define NU(N) ((N) >= '0' && (N) <= '9')
#define AN(N) (UP(N) || LO(N) || NU(N))
int get_line(char s[],int lim){
	int c,i;
	for (i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i]=c;
	if (c=='\n'){
		s[i]=c;
		++i;
	}
	s[i]='\0';
	return i;
}
int expand(char s1[], char s2[], int sz)
{
	int i, j, temp;
	
	j=0;
	for(i = 0; s1[i] != '\0'; i++) {
		if(j >= sz) return 0;                                   
		if(i==0 || s1[i] != '-') {                              
			s2[j++] = s1[i];
			continue;
		}
		if(s1[i] == '-' && (!AN(s1[i-1]) || !AN(s1[i+1]))) { 
			s2[j++] = s1[i];
			continue;
		}
		if(s1[i] == '-' && (
					  (UP(s1[i-1]) && UP(s1[i+1]) && s1[i-1] < s1[i+1]-1) ||
					  (LO(s1[i-1]) && LO(s1[i+1]) && s1[i-1] < s1[i+1]-1) ||
					  (NU(s1[i-1]) && NU(s1[i+1]) && s1[i-1] < s1[i+1]-1))) {
			temp = s1[i-1]+1;
			while (temp < s1[i+1]) {
				s2[j++] = temp++;
			}
			continue;
		}
		s2[j++] = s1[i];                                         
	}
	s2[j] = '\0';
	return 1;
}

int main(){
	char in[MAXLINE], out[MAXLINE];
	
	while(get_line(in,MAXLINE-1) > 1) {
		if(expand(in,out,MAXLINE-1))
			printf("%s",out);
		else
			printf("buffer overflow\n");
	}
	return 0;
}
