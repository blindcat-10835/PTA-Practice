/*7-2 一元多项式的乘法与加法运算（20 point(s)）
设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0*/
#include <iostream>
using namespace std;
typedef struct PloyNode* Ploynomial;
struct PloyNode
{
	int coef;
	int expon;
	Ploynomial link;
};
/*here we need to change the value of Rear so that it could point to the last node, so we should use pointer to Rear */
void Attach(int c, int e, Ploynomial * pRear)
{
	Ploynomial P = (Ploynomial)malloc(sizeof(struct PloyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;
}
Ploynomial	ReadPloy()
{
	int length, c, e;
	Ploynomial P, Rear, t;
	P = (Ploynomial)malloc(sizeof(struct PloyNode));
	P->link = NULL;
	Rear = P;
	cin >> length;
	if (!length)return NULL;
	while (length--)
	{
		cin >> c >> e;
		Attach(c, e, &Rear);
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}
Ploynomial Mult(Ploynomial P1, Ploynomial P2)
{
	Ploynomial Head, Rear, t1 = P1, t2 = P2, t;
	int c, e;
	if (!P1 || !P2)return NULL;
	Head = (Ploynomial)malloc(sizeof(struct PloyNode));
	Head->link = NULL;
	Rear = Head;
	/*firstly, multiplity the first P1 with P2 ,get P*/
	while (t2)
	{
		Attach(t1->coef*t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->link;
	}

	t1 = t1->link;
	while (t1)
	{
		t2 = P2, Rear = Head;
		while (t2)
		{
			e = t1->expon + t2->expon;
			c = t1->coef *t2->coef;
			while (Rear->link&&Rear->link->expon > e)Rear = Rear->link;

			if (Rear->link == NULL)
			{
				Attach(c, e, &Rear);
			}
			else if (Rear->link->expon == e)
			{
				Rear->link->coef += c;
			}
			else if (Rear->link->expon < e)
			{
				t = (Ploynomial)malloc(sizeof(struct PloyNode));
				t->coef = c;
				t->expon = e;
				t->link = Rear->link;
				Rear->link = t;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}

	t = Head;
	Head = Head->link;
	free(t);
	return Head;
}
Ploynomial Add(Ploynomial L1, Ploynomial L2)
{
	Ploynomial Head = (Ploynomial)malloc(sizeof(Ploynomial));
	Head->link = NULL;
	Ploynomial Rear = Head;

	while (L1 != NULL && L2 != NULL)
	{
		if (L1->expon > L2->expon)
		{
			Rear->link = (Ploynomial)malloc(sizeof(Ploynomial));
			Rear = Rear->link;
			Rear->coef = L1->coef;
			Rear->expon = L1->expon;
			Rear->link = NULL;
			L1 = L1->link;
		}
		else if (L1->expon < L2->expon)
		{
			Rear->link = (Ploynomial)malloc(sizeof(Ploynomial));
			Rear = Rear->link;
			Rear->coef = L2->coef;
			Rear->expon = L2->expon;
			Rear->link = NULL;
			L2 = L2->link;
		}
		else if (L1->expon == L2->expon)
		{
			int tmp_coef = L1->coef + L2->coef;
			if (tmp_coef == 0)
			{
				L1 = L1->link;
				L2 = L2->link;
			}
			else
			{
				Rear->link = (Ploynomial)malloc(sizeof(Ploynomial));
				Rear = Rear->link;
				Rear->coef = tmp_coef;
				Rear->expon = L1->expon;
				Rear->link = NULL;
				L1 = L1->link;
				L2 = L2->link;
			}
		}
	}
	while (L1 != NULL)
	{
		Rear->link = (Ploynomial)malloc(sizeof(Ploynomial));
		Rear = Rear->link;
		Rear->coef = L1->coef;
		Rear->expon = L1->expon;
		Rear->link = NULL;
		L1 = L1->link;
	}
	while (L2 != NULL)
	{
		Rear->link = (Ploynomial)malloc(sizeof(Ploynomial));
		Rear = Rear->link;
		Rear->coef = L2->coef;
		Rear->expon = L2->expon;
		Rear->link = NULL;
		L2 = L2->link;
	}

	Rear = Head;
	Head = Head->link;
	free(Rear);
	return Head;
}

/*create  a List of length*/
Ploynomial Make_List(int length)
{
	if (length == 0)
	{
		return	NULL;
	}
	Ploynomial head = (Ploynomial)malloc(length * sizeof(struct PloyNode));
	Ploynomial temp;
	temp = head;
	/*for (int i = 0; i < length; i++)
	{
	printf("%p\n", temp++);
	}
	temp = head;
	*/
	for (int i = 0; i < length; i++)
	{
		//t2 = temp + 1;
		temp->coef = 0;
		temp->expon = 0;
		temp->link = temp + 1;
		//printf("%p\t %d \t%d \n", temp, temp->coef, temp->expon);
		temp += 1;
	}
	(temp - 1)->link = NULL;
	/*temp = head;
	while (temp != NULL)
	{
	printf("%p\n", temp);
	temp = temp->next;
	}*/
	return head;
}
Ploynomial Read_List(Ploynomial Head)
{
	Ploynomial temp = Head;
	while (temp != NULL)
	{
		cin >> temp->coef >> temp->expon;
		temp = temp->link;
	}
	return Head;
}
Ploynomial Print_List(Ploynomial Head)
{
	if (!Head)
	{
		cout << "0 0" << endl;
		return 0;
	}
	Ploynomial temp = Head;
	bool isNone = true;
	while (temp != NULL)
	{
		if (temp->link != NULL && temp->coef != 0)
		{
			printf("%d %d ", temp->coef, temp->expon);
			isNone = false;
		}
		else if (temp->coef != 0)
		{
			printf("%d %d\n", temp->coef, temp->expon);
			isNone = false;
		}
		temp = temp->link;
	}
	if (isNone)cout << "0 0" << endl;
	return Head;
}
Ploynomial Plus_List(Ploynomial L1, Ploynomial L2)
{
	Ploynomial tmp1 = (Ploynomial)malloc(sizeof(Ploynomial));
	tmp1->link = NULL;
	Ploynomial head = tmp1;

	while (L1 != NULL && L2 != NULL)
	{
		if (L1->expon > L2->expon)
		{
			tmp1 = tmp1->link;
			tmp1 = (Ploynomial)malloc(sizeof(Ploynomial));
			tmp1->coef = L1->coef;
			tmp1->expon = L1->expon;
			tmp1->link = NULL;
			L1 = L1->link;
		}
		else if (L1->expon < L2->expon)
		{
			tmp1 = tmp1->link;
			tmp1 = (Ploynomial)malloc(sizeof(Ploynomial));
			tmp1->coef = L2->coef;
			tmp1->expon = L2->expon;
			tmp1->link = NULL;
			L2 = L2->link;
		}
		else if (L1->expon == L2->expon)
		{
			int tmp_coef = L1->coef + L2->coef;
			if (tmp_coef == 0)
			{
				L1 = L1->link;
				L2 = L2->link;
			}
			else
			{
				tmp1 = tmp1->link;
				tmp1 = (Ploynomial)malloc(sizeof(Ploynomial));
				tmp1->coef = tmp_coef;
				tmp1->expon = L1->expon;
				tmp1->link = NULL;
				L1 = L1->link;
				L2 = L2->link;
			}
		}
	}
	while (L1 != NULL)
	{
		tmp1 = tmp1->link;
		tmp1 = (Ploynomial)malloc(sizeof(Ploynomial));
		tmp1->coef = L1->coef;
		tmp1->expon = L1->expon;
		tmp1->link = NULL;
		L1 = L1->link;
	}
	while (L2 != NULL)
	{
		tmp1 = tmp1->link;
		tmp1 = (Ploynomial)malloc(sizeof(Ploynomial));
		tmp1->coef = L2->coef;
		tmp1->expon = L2->expon;
		tmp1->link = NULL;
		L2 = L2->link;
	}
	tmp1 = head;
	head = tmp1->link;
	free(tmp1);
	Print_List(head);
	return head;
}
int main(int argc, char const *argv[])
{
	//int length1, length2;
	//cin >> length1;
	//Ploynomial List1;
	//List1 = Make_List(length1);
	//Read_List(List1);
	//cin >> length2;
	//Ploynomial List2;
	//List2 = Make_List(length2);
	//Read_List(List2);
	////Ploynomial List3 = Plus_List(List1, List2);
	//Ploynomial List3;
	//List3 = Mult(List1, List2);
	//Print_List(List1);
	//Print_List(List2);
	//cout << "***********" << endl;
	//Print_List(List3);
	Ploynomial P1, P2, PP, PS;
	P1 = ReadPloy();
	P2 = ReadPloy();
	PP = Mult(P1, P2);
	Print_List(PP);
	PS = Add(P1, P2);
	Print_List(PS);
	return 0;
}

/*the second method using array.*/
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define N 10000
//
///*输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数
//（绝对值均为不超过1000的整数）。数字间以空格分隔。
//输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
//数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。*/
//int main()
//{
//	int a[N] = { 0 };
//	int b[N] = { 0 };
//	int c[N] = { 0 };  //求积
//	int d[N] = { 0 };  //求和
//	int i, j;
//	int x, z; //系数  指数
//	int cnt = 0;
//
//	scanf("%d", &i);  //读入第一个单项式
//	while (i--)
//	{
//		scanf("%d %d", &x, &z);
//		a[z] += x;   //指数为z的系数放在z位置上
//	}
//
//	scanf("%d", &i);  //读入第二个单项式
//	while (i--)
//	{
//		scanf("%d %d", &x, &z);
//		b[z] += x;
//	}
//
//	//多项式乘法
//	for (i = N - 1; i >= 0; i--)
//	{
//
//		if (a[i])
//		{
//			for (j = 0; j<N; j++)
//			{
//				if (b[j])
//				{
//					c[i + j] += a[i] * b[j];
//				}
//			}
//		}
//	}
//
//	//输出多项式乘法结果
//	for (i = N - 1; i >= 0; i--)
//	{
//
//		if (c[i])
//		{
//			if (cnt)
//			{
//				//处理结尾不能有多余空格
//				printf(" ");
//			}
//			printf("%d %d", c[i], i);
//			cnt++;
//		}
//	}
//	if (!cnt)
//	{
//		printf("0 0");
//	}
//	printf("\n");
//
//	//多项式加法
//	for (i = N - 1; i >= 0; i--)
//	{
//		if (a[i])
//		{
//			d[i] += a[i];
//		}
//	}
//	for (j = N - 1; j >= 0; j--)
//	{
//		if (b[j])
//		{
//			d[j] += b[j];
//		}
//	}
//
//	//输出多项式加法结果
//	cnt = 0;
//	for (i = N - 1; i >= 0; i--)
//	{
//		if (d[i])
//		{
//			if (cnt)
//			{
//				printf(" ");
//			}
//			printf("%d %d", d[i], i);
//			cnt++;
//		}
//	}
//	if (!cnt)
//	{
//		printf("0 0");
//	}
//
//	return 0;
//}