#include <stdio.h>

unsigned invert(unsigned x, int p, int n){
	return x ^ (~(~0U << n) << p);
}


int main(){
	unsigned x;
	int p, n;
	
	for(x = 0; x < 700; x += 49)
		for(n = 0; n < 8; n++)
		for(p = 0; p < 8; p++)
		printf("%x, %d, %d: %x\n", x, p, n, invert(x, p, n));
	return 0;
}
