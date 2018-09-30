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
/*交换两个元素*/
void SwapElement(ElementType& A, ElementType& B)
{
	ElementType t = A;
	A = B;
	B = t;
}
/*数据输出*/
void CoutVector(vector<ElementType>A)
{
	for (int i = 0; i < A.size() - 1; i++)
	{
		cout << A[i] << ' ';
	}
	cout << A.back() << endl;
}
/*创建堆*/
typedef vector<ElementType> Vec;
typedef Vec Heap;
typedef int PtrToHeap;
/*将向量A的数据构建成大顶堆*/
void BuildMaxHeap(Vec &A)
{
	int N = A.size();
	PtrToHeap Root = 0,
		Parent = Root,
		LeftChild = Parent * 2 + 1,
		RightChild = Parent * 2 + 2;
	int Parent, Child;
	ElementType X;

	X = A[Root]; /* 取出根结点存放的值 */
	for (Parent = Root; (Parent * 2 + 1) < N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child] < A[Child + 1]))
			Child++;  /* Child指向左右子结点的较大者 */
		if (X >= A[Child]) break; /* 找到了合适位置 */
		else  /* 下滤X */
			A[Parent] = A[Child];
	}
	A[Parent] = X;
	return;
}

void PercDown(Vec A, int p, int N)
{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
  /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
	int Parent, Child，Root = 1;
	ElementType X;

	X = A[p]; /* 取出根结点存放的值 */
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child] < A[Child + 1]))
			Child++;  /* Child指向左右子结点的较大者 */
		if (X >= A[Child]) break; /* 找到了合适位置 */
		else  /* 下滤X */
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}
/*堆排序*/
vector<ElementType> HeapSort(vector<ElementType> A)
{
	int N = A.size();
	Vec B(N);
	//for (i = N / 2 - 1; i >= 0; i--)/* 建立最大堆 */
	//	PercDown(A, i, N);
	BuildMaxHeap(A);
	for (int i = N - 1; i > 0; i--)
	{
		/* 删除最大堆顶 */
		SwapElement(A[0], A[i]); /* 见代码7.1 */
		B.push_back(A.back());
		A.pop_back();
		//PercDown(A, 0, i);
		BuildMaxHeap(A);
	}
	return B;
}

/*二分查找，传入数组，待查找元素，数组长度，返回该元素所在位置下标,找不到则返回-1*/
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
/*桶排序
时间复杂度O（M+N） M为数据范围，N为数据数
空间复杂度
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
/*冒泡排序
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
/*插入排序
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
/*选择排序*/
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
/*希尔排序*/
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