#include <stdio.h>
#include <stdlib.h>

/* Here's a helper function to get Richard Heathfield around the problem of not
* having strchr
*/

int hexalpha_to_int(int c)
{
	char hexalpha[] = "aAbBcCdDeEfF";
	int i;
	int answer = 0;
	
	for(i = 0; answer == 0 && hexalpha[i] != '\0'; i++)
	{
		if(hexalpha[i] == c)
		{
			answer = 10 + (i / 2);
		}
	}
	
	return answer;
}

unsigned int htoi(const char s[])
{
	unsigned int answer = 0;
	int i = 0;
	int valid = 1;
	int hexit;
	
	if(s[i] == '0')
	{
		++i;
		if(s[i] == 'x' || s[i] == 'X')
		{
			++i;
		}
	}
	
	while(valid && s[i] != '\0')
	{
		answer = answer * 16;
		if(s[i] >= '0' && s[i] <= '9')
		{
			answer = answer + (s[i] - '0');
		}
		else
		{
			hexit = hexalpha_to_int(s[i]);
			if(hexit == 0)
			{
				valid = 0;
			}
			else
			{
				answer = answer + hexit;
			}
		}
		
		++i;
	}
	
	if(!valid)
	{
		answer = 0;
	}
	
	return answer;
}

/* Solution finished. This bit's just a test driver, so
* I've relaxed the rules on what's allowed.
*/

int main(void)
{
	char *endp = NULL;
	char *test[] =
	{
		"F00",
			"bar",
			"0100",
			"0x1",
			"0XA",
			"0X0C0BE",
			"abcdef",
			"123456",
			"0x123456",
			"deadbeef",
			"zog_c"
	};
	
	unsigned int result;
	unsigned int check;
	
	size_t numtests = sizeof test / sizeof test[0];
	
	size_t thistest;
	
	for(thistest = 0; thistest < numtests; thistest++)
	{
		result = htoi(test[thistest]);
		check = (unsigned int)strtoul(test[thistest], &endp, 16);
		
		if((*endp != '\0' && result == 0) || result == check)
		{
			printf("Testing %s. Correct. %u\n", test[thistest], result);
		}
		else
		{
			printf("Testing %s. Incorrect. %u\n", test[thistest], result);
		}
	}
	
	return 0;
}




And here's Marshall's:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
	
	long hchartoi (char hexdig, int pos);   /* converts a hex char to decimal knowing its 0 based place value */
long htoi (char hexstring[]);               /* converts a string of hex bits to integer ... */

int main(void)
{
	char *endp = NULL;
	char *test[] =
	{
		"F00",
			"bar",
			"0100",
			"0x1",
			"0XA",
			"0X0C0BE",
			"abcdef",
			"123456",
			"0x123456",
			"deadbeef",
			"zog_c"
	};
	
	long int result;
	long int check;
	
	size_t numtests = sizeof test / sizeof test[0];
	
	size_t thistest;
	
	for(thistest = 0; thistest < numtests; thistest++)
	{
		result = htoi(test[thistest]);
		check = strtol(test[thistest], &endp, 16);
		
		if((*endp != '\0' && result == -1) || result == check)
		{
			printf("Testing %s. Correct. %ld\n", test[thistest], result);
		}
		else
		{
			printf("Testing %s. Incorrect. %ld\n", test[thistest], result);
		}
	}
	
	return 0;
}

long htoi (char s[])
{
	
	char *p = &s[strlen(s)-1];
	long deci = 0, dig = 0;
	int pos = 0;
	
	while (p >= s) {
		
		if ((dig = hchartoi(*p, pos)) < 0 ) {
			printf("Error\n");
			return -1;
			
		}
		deci += dig;
		--p;
		++pos;
		
	}
	return deci;
}

/* convert hex char to decimal value */
long hchartoi (char hexdig, int pos)
{
	
	char hexdigits[] = "0123456789ABCDEF";
	char *p = &hexdigits[0];
	long deci = 0;
	int i;
	
	while (*p != toupper(hexdig) && deci < 16) {
		
		++p;
		++deci;
		
	}
	if (*p == toupper(hexdig)) {
		for (i = 0; i < pos; i++)
			deci *= 16;
		return deci;
		
	}
	return -1;
}
