/*7-2 һԪ����ʽ�ĳ˷���ӷ����㣨20 point(s)��
��ƺ����ֱ�������һԪ����ʽ�ĳ˻���͡�

�����ʽ:
�����2�У�ÿ�зֱ��ȸ�������ʽ������ĸ���������ָ���ݽ���ʽ����һ������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���

�����ʽ:
�����2�У��ֱ���ָ���ݽ���ʽ����˻�����ʽ�Լ��Ͷ���ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո������ʽӦ���0 0��

��������:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
�������:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0*/
#include <iostream>
using namespace std;
typedef struct List* PtrToList;
struct List
{
	int xisu;
	int zhishu;
	PtrToList next;
};
PtrToList Make_List()
{
	int length1;
	cin >> length1;
	List S1[length1];
	for (int i = 0; i < length1; i++)
	{
		cin >> S1[i].xishu >> S1[i].zhishu;
	}
}
int main(int argc, char const *argv[])
{
	cin >> length2;
	List S2[length2];
	for (int i = 0; i < length2; i++)
	{
		cin >> S2[i].xishu >> S2[i].zhishu;
	}
	return 0;
}