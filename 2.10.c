#include <stdio.h>

unsigned char llower(char);

int main(void)
{
	int i;
	char mat_variables[] = "AaBbCcdDeE1234ZzyY";
	i = 0;
	puts(mat_variables);
	while(mat_variables[i] != '\0')putchar(llower(mat_variables[i++]));
	putchar('\n');
}

unsigned char llower(char x)
{
	return (x >= 'A' && x <= 'Z') ? x = x - 'A' +'a' : x;
}
