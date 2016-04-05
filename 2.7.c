unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0U << n) << p);
}

/*
main driver added, in a hurry while tired, by RJH. Better test driver suggestions are welcomed!

main driver fixed by Flash Gordon as it was passing the parameters in the wrong order and
hex is a more useful output format than decimal for checking the result. Also start at 0
for n,p as they are valid inputs.
*/

#include <stdio.h>

int main(void)
{
	unsigned x;
	int p, n;
	
	for(x = 0; x < 700; x += 49)
		for(n = 0; n < 8; n++)
		for(p = 0; p < 8; p++)
		printf("%x, %d, %d: %x\n", x, p, n, invert(x, p, n));
	return 0;
}
