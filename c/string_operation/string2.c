#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
	char a[4] = "111", b[6] = "222";
	char c[3] = {'3', '3'};
	printf("a=%s\n", a);
	printf("b=%s\n", b);
	printf("c=%s\n", c);
	//		char c[] = strcat(a,b);
	strcat(c, a);
	c[4] = '4';
	printf("strcat(a,b)=%s\n", strcat(a, b));
	printf("a'=%s\n", a);
	printf("la=%lu\n", sizeof(a) / sizeof(a[0]));
	printf("c'=%s\n", c);
	return 0;
}
