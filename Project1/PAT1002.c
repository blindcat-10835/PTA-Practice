#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int PAT1002(int argc, char const *argv[])
{
	long n = 0;
	scanf("%d", &n);
	long k = 0;
	while (n != 0)
	{
		k += n % 10;
		printf("%d", k);
		n /= 10;
		printf("%d", n);
	}
	printf("%d", k);
	return 0;
}