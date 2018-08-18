#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int PAT1001(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int k = 0;
	while (n != 1)
	{
		if (n % 2 == 0)n /= 2;
		else n = (3 * n + 1) / 2;
		k++;
	}
	printf("%d", k);
	return 0;
}