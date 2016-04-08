#include <stdio.h>
#include <pilcrow.h> 
#define MAXLINE 1024
#define UP(N) ((N) >= 'A' && (N) <= 'Z')
#define LO(N) ((N) >= 'a' && (N) <= 'z')
#define NU(N) ((N) >= '0' && (N) <= '9')
#define AN(N) (UP(N) || LO(N) || NU(N))

int expand(char s1[], char s2[], int sz)
{
	int i, j, temp;
	
	j=0;
	for(i = 0; s1[i] != '\0'; i++) {
		if(j >= sz) return 0;                                   /* buffer overflow */
		if(i==0 || s1[i] != '-') {                              /* first character or not '-'*/
			s2[j++] = s1[i];
			continue;
		}
		if(s1[i] == '-' && (!AN(s1[i-1]) || !AN(s1[i+1]))) {    /* leading, trailing, isolated '-' */
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

int main(void)
{
	char in[MAXLINE], out[MAXLINE];
	
	while(getline(in,MAXLINE-1) > 1) {
		if(expand(in,out,MAXLINE-1))
			printf("%s",out);
		else
			printf("buffer overflow\n");
	}
	return 0;
}
