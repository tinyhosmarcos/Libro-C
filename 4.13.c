#include <stdio.h>
#include <string.h>

void reverse(char [], int);

int main()
{
	char tstr[] = "Hello, world!";
	printf("%s\n", tstr);
	reverse(tstr, 0);
	printf("%s\n", tstr);
	return 0;
}

/* I don't really like having the "left" argument, but it is all I 
* could come up with without putting too much effort into the problem.
* and remaining a category 0 solution. */
void
	reverse(char s[], int left)
{
	int slen = strlen(s)-1; /* -1 is to compensate for \0. */
	char buf = s[left];
	if (left < slen) {
		reverse(s, left+1);
	}
	if (buf != '\0') {
		s[slen-left] = buf;
	}
	if (left == 0) {
		/* Once execution reaches this point, it is at the end of the
		* first recursion and the terminating char must be set to
		* close the string.
		*/
		s[slen+1] = '\0';
	}
}
