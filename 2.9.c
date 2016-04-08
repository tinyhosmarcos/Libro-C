#include <stdio.h>
int contar_bits(unsigned var_1){
	int mult;
	
	for (mult = 0; var_1 != 0; var_1 &= (var_1-1))
		mult++;
	return mult;
}
int main(){
	printf("%d",contar_bits(00012312));
	
}
