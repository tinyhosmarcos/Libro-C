#include <stdio.h>
#include <string.h>

#define MAX_STR 1000

void itoa(int, char [], int);
void reverse(char []);

int main()
{
	int ibuf = -12345;
	char istr[MAX_STR];
	istr[0] = '\0';
	printf("Integer: %d\n", ibuf);
	itoa(ibuf, istr, 0);
	printf("String: %s\n", istr);
	return 0;
}

void itoa(int num, char s[], int pos)
{
	int abs = 0;
	int buf = 0;
	
	if (num < 0) {
		num *= -1;
		abs = EOF;
	}
	buf = num % 10;
	if (buf > 0) {
		buf += '0';
		s[pos++] = buf;
		if ((num / 10) > 0) {
			/* Reset the sign before recursion so that it is
			* available in the tail of the recursion.*/
			if (abs == EOF) {
				num *= -1;
			}
			itoa(num /= 10, s, pos);
		} else {
			if (abs == EOF) {
				s[pos++] = '-';
			}
			s[pos] = '\0';
		}
	}
	if (pos == 1) {
		reverse(s);
	};
}

void
	reverse (char s[])
{
	char c;
	int i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
