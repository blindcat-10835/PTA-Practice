/*
1009 Product of Polynomials（25 point(s)）
This time, you are supposed to find A×B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N​1​​  a​N​1​​​​  N​2​​  a​N​2​​​​  ... N
​K​​  a​N ​K
​​
​​

where K is the number of nonzero terms in the polynomial, Ni
​​  and a​N​i​​
​​  (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10, 0≤N
​K
​​ <⋯<N
​2
​​ <N
​1
​​ ≤1000.

Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 3 3.6 2 6.0 1 1.6
*/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int k1, k2, e1[10] = { 0 }, e2[10] = { 0 };
	double c1[10] = { 0.0 }, c2[10] = { 0.0 };
	double r[2001] = { 0.0 };
	cin >> k1;
	for (int i = 0; i < k1; i++)
	{
		cin >> e1[i];
		cin >> c1[i];
	}
	cin >> k2;
	for (int i = 0; i < k2; i++)
	{
		cin >> e2[i];
		cin >> c2[i];
	}
	for (int i = 0; i < k1; i++)
	{
		for (int j = 0; j < k2; j++)
		{
			int e = e1[i] + e2[j];
			double  c = c1[i] * c2[j];
			r[e] += c;
		}
	}
	int count = 0;
	for (int i = 0; i < 2001; i++)
	{
		if (r[i] != 0.0)count++;
	}
	printf("%d", count);
	for (int i = 2000; i >= 0; i--)
	{
		if (r[i] != 0.0)printf(" %d %.1f", i, r[i]);
	}

	return 0;
}