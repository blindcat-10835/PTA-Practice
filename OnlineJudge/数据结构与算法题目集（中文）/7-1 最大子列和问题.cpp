#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int length;
	int sum = 0, max_sum = 0;
	int temp = 0;
	cin >> length;
	while (length--)
	{
		cin >> temp;
		sum += temp;
		if (sum < 0)
		{
			sum = 0;
		}
		if (max_sum < sum)
		{
			max_sum = sum;
		}
	}
	cout << max_sum;
	return 0;
}