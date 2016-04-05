#include <stdio.h>

int atoi(char s[]){
	int i,n;
	n=0;
	for (i=0; s[i] >='0' && s[i] <='9';i++)
		n=10 * n + (s[i]-'0');
	return n;
}
int main() {
	char d[3]={'1','2','h'};
	printf("%d",atoi(d));
	
	return 0;
}

