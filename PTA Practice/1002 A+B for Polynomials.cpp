/*
1002 A+B for Polynomials（25 point(s)）
This time, you are supposed to find A+B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N​1 ​  a
​N
​1
​​
​​  N
​2
​​  a
​N
​2
​​
​​  ... N
​K
​​  a
​N
​K
​​
​​

where K is the number of nonzero terms in the polynomial, N
​i
​​  and a
​N
​i
​​
​​  (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10，0≤N
​K
​​ <⋯<N
​2
​​ <N
​1
​​ ≤1000.

Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 2 1.5 1 2.9 0 3.2
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct result
{
	double c = 0;
};
int main(int argc, char const *argv[])
{
	int k1, e1;
	result r[1001];
	int k2;
	double tmp;
	cin >> k1;
	while (k1--)
	{
		cin >> e1;
		cin >> r[e1].c;
	}
	cin >> k2;
	while (k2--)
	{
		cin >> e1;
		if (r[e1].c == 0)cin >> r[e1].c;
		else { cin >> tmp; r[e1].c += tmp; }
	}
	int count = 0;
	for (int i = 0; i < 1001; i++)
	{
		if (r[i].c != 0)
		{
			count++;
		}
	}
	cout << count;
	k1 = 0;
	for (int i = 1000; i >= 0 && k1 < count; i--)
	{
		if (r[i].c != 0.0)
		{
			printf(" %d %.1f", i, r[i].c);
			k1++;
		}
	}

	return 0;
}