#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	char c[41][81], tmp;
	int i = 0, j = 0;
	while ((tmp = getchar()) != '\n')
	{
		if (tmp == ' ')
		{
			c[i++][j] = '\0';
			j = 0;
		}
		else c[i][j++] = tmp;
	}
	c[i][j] = '\0';
	cout << c[i--];
	while (i >= 0)
	{
		cout << ' ' << c[i--];
	}
	return 0;
}