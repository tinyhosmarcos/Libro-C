#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1024
#define PREFIX 1
#define NUMBER 2
#define EXPONENT 3
#define EXP_DIG 4


int getline(char s[], int lim){
	
int c, i;
for (i = 0; i<lim-1 && (c = getchar( )) !=EOF && c!='\n'; ++i) 
	s[i] = c;
if (c == '\n') { 
	s[i] = c;
	++i;
	}
s[i] = '\0';
return i;
/* copy: copia 'from' en 'to'; supone que to es suficientemente grande */
}

int valid_float(char s[])
{
	/* a valid float may be preceded by whitespace (\s, \t, \n, etc) */
	/* leading optional + or - */
	/* decimal digits and one optional . */
	/* optional exponent (e/E,  optional + or -, 1 to 3 decimal digits) */
	/* I could do this in one line with a regex!  */
	
	
	int i, state, point, expct, ptct;
	state = PREFIX;
	point = 0;
	expct = 0;
	ptct  = 0;
	
	
	for(i=0; s[i] != '\n' && s[i] != '\0'; i++) {
		if (isspace(s[i])) {
			if(state == PREFIX) continue;
			return 0;							/* embedded  space */
		}
		if (isdigit(s[i])) {
			if(state == PREFIX || state == NUMBER) {
				state = NUMBER;
				continue;
			}
			if(state == EXPONENT || state == EXP_DIG) {
				if(++expct > 3) {
					return 0;					/* exp may not have more than 3 digits */
				}
				state = EXP_DIG;
				continue;
			}
		}
		switch(s[i]) {
		case '.':
			if(state == PREFIX || state == NUMBER) {
			if(++ptct > 1) {
				return 0;				/* only one decimal pt */
			}
			state = NUMBER;
			continue;
		}
		case 'e': case 'E':
			if(state == NUMBER) {
			state = EXPONENT;
			continue;
		}
		return 0;						/* misplaced 'e' */
		case '-': case '+':
			if(state == PREFIX) {
			state = NUMBER;
			continue;
		}
		if(state == EXPONENT) {
			state = EXP_DIG;
			continue;
		}
		return 0;						/* misplaced sign */
		default:
			return 0;						/* illegal character */
		}
	}
	return 1;									/* everything ok */
}

double atof(char s[])
{
	double val,power;
	int i,sign,sign2,exponent;
	
	for(i=0; isspace(s[i]); i++);
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val +(s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if(s[i] == 'e' || s[i] == 'E') {
		i++;
		sign2 = (s[i] == '-') ? -1 : 1;
		if(s[i] == '+' || s[i] == '-')
			i++;
		for(exponent = 0; isdigit(s[i]); i++)
			exponent = 10 * exponent + (s[i] - '0');
		if(sign2 ==  1) for(i = exponent; i > 0; --i, val *=10.0);
		if(sign2 == -1) for(i = exponent; i > 0; --i, val /=10.0);
	}
	return sign * val / power;
}

int main(void)
{
	char inp[MAXLINE+1];
	
	while(getline(inp, MAXLINE-1) > 1)	{	/* terminates on empty line */
		if(!valid_float(inp)) {
			printf("invalid input\n");
		}else
			printf("% 9.9g\n", atof(inp));
	}
	return 0;
}

