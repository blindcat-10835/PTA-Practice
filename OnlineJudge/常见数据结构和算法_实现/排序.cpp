#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef int ElementType;

const ElementType INF = 0x7fffffff;
/*��������Ԫ��*/
void SwapElement(ElementType& A, ElementType& B)
{
	ElementType t = A;
	A = B;
	B = t;
}
/*�������*/
void CoutVector(vector<ElementType>A)
{
	for (int i = 0; i < A.size() - 1; i++)
	{
		cout << A[i] << ' ';
	}
	cout << A.back() << endl;
}
/*������*/
typedef vector<ElementType> Vec;
typedef Vec Heap;
typedef int PtrToHeap;
/*������A�����ݹ����ɴ󶥶�*/
void BuildMaxHeap(Vec &A)
{
	int N = A.size();
	PtrToHeap Root = 0,
		Parent = Root,
		LeftChild = Parent * 2 + 1,
		RightChild = Parent * 2 + 2;
	int Parent, Child;
	ElementType X;

	X = A[Root]; /* ȡ��������ŵ�ֵ */
	for (Parent = Root; (Parent * 2 + 1) < N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child] < A[Child + 1]))
			Child++;  /* Childָ�������ӽ��Ľϴ��� */
		if (X >= A[Child]) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			A[Parent] = A[Child];
	}
	A[Parent] = X;
	return;
}

void PercDown(Vec A, int p, int N)
{ /* �ı����4.24��PercDown( MaxHeap H, int p )    */
  /* ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ���� */
	int Parent, Child��Root = 1;
	ElementType X;

	X = A[p]; /* ȡ��������ŵ�ֵ */
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child] < A[Child + 1]))
			Child++;  /* Childָ�������ӽ��Ľϴ��� */
		if (X >= A[Child]) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}
/*������*/
vector<ElementType> HeapSort(vector<ElementType> A)
{
	int N = A.size();
	Vec B(N);
	//for (i = N / 2 - 1; i >= 0; i--)/* �������� */
	//	PercDown(A, i, N);
	BuildMaxHeap(A);
	for (int i = N - 1; i > 0; i--)
	{
		/* ɾ�����Ѷ� */
		SwapElement(A[0], A[i]); /* ������7.1 */
		B.push_back(A.back());
		A.pop_back();
		//PercDown(A, 0, i);
		BuildMaxHeap(A);
	}
	return B;
}

/*���ֲ��ң��������飬������Ԫ�أ����鳤�ȣ����ظ�Ԫ������λ���±�,�Ҳ����򷵻�-1*/
ElementType BinarySearch(const vector<ElementType> A, ElementType X)
{
	int Left = 0, Right = A.size(), Mid = (Left + Right) / 2;
	while (Left <= Right || X != A[Mid])
	{
		Mid = (Left + Right) / 2;
		if (X > A[Mid])
		{
			Left = Mid + 1;
		}
		else if (X < A[Mid])
		{
			Right = Mid - 1;
		}
	}
	if (Left > Right)
	{
		return -1;
	}
	else
	{
		return Mid;
	}
}
/*Ͱ����
ʱ�临�Ӷ�O��M+N�� MΪ���ݷ�Χ��NΪ������
�ռ临�Ӷ�
*/
vector<ElementType> BucketSort(vector<ElementType> A)
{
	vector<bool> T(A.size(), false);
	for (auto iter : A)
	{
		T[iter] = true;
	}
	A.clear();
	for (int i = 0; i != T.size(); i++)
	{
		if (T[i])
		{
			A.push_back(i);
		}
	}
	return A;
}
/*ð������
*/
vector<ElementType> BubbleSort(vector<ElementType> A)
{
	for (int i = A.size() - 1; i >= 0; i--)
	{
		bool hasNoSwap = true;
		for (int j = 0; j < i; j++)
		{
			if (A[j] > A[j + 1])
			{
				SwapElement(A[j], A[j + 1]);
				hasNoSwap = false;
			}
		}
		if (hasNoSwap)
		{
			break;
		}
	}
	return A;
}
/*��������
*/
vector<ElementType> InsertionSort(vector<ElementType> A)
{
	for (int P = 0; P < A.size(); P++)
	{
		ElementType Tmp = A[P];
		int i = P;
		while (i >= 1 && Tmp < A[i - 1])
		{
			A[i] = A[i - 1];
			i--;
		}
		A[i] = Tmp;
	}
	return A;
}
/*ѡ������*/
vector<ElementType> SelectionSort(vector<ElementType> A)
{
	for (int i = 0; i < A.size(); i++)
	{
		ElementType Min = INF, MinIndex = -1;
		for (int j = i; j < A.size(); j++)
		{
			if (A[j] < Min)
			{
				MinIndex = j;
				Min = A[j];
			}
		}
		SwapElement(A[i], A[MinIndex]);
	}
	return A;
}
/*ϣ������*/
vector<ElementType> ShellSort(vector<ElementType> A)
{
	for (int D = A.size() / 2; D > 0; D /= 2)
	{
		for (int P = 0; P < A.size(); P++)
		{
			ElementType Tmp = A[P];
			int i = P;
			while (i >= D && Tmp < A[i - D])
			{
				A[i] = A[i - D];
				i -= D;
			}
			A[i] = Tmp;
		}
	}
	return A;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	while (N--)
	{
		cin >> A[N];
	}
	B = SelectionSort(A);
	CoutVector(B);
	B = BubbleSort(A);
	CoutVector(B);
	B = InsertionSort(A);
	CoutVector(B);
	sort(A.begin(), A.end());
	CoutVector(A);
	return 0;
}