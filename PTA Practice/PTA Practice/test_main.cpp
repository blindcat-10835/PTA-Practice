#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

int main(int argc, char const *argv[])
{
	int length = 0, score[MAX];
	string name[MAX], number[MAX];
	cin >> length;
	int i = length;
	while (i--)
	{
		cin >> name[i] >> number[i] >> score[i];
	}
	int max = 0, min = 101, m = 0, n = 0;
	i = length;
	while (i--)
	{
		if (score[i] > max)
		{
			max = score[i];
			m = i;
		}
		if (score[i] < min)
		{
			min = score[i];
			n = i;
		}
	}
	cout << name[m] << " " << number[m] << endl;
	cout << name[n] << " " << number[n] << endl;

	return 0;
}