#include<iostream>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
struct sch
{
	string name;
	float score = 0;
	int stu = 0;
}arr[100005];//����������С�㣬ѧУ��ô������ô��
bool cmp(sch A, sch B)
{
	if ((int)A.score != (int)B.score) return (int)A.score > (int)B.score;//������ͬ��˭��˭��ǰ
	else if (A.stu != B.stu) return A.stu < B.stu;       //������ͬ��ѧ������ͬ��ѧ����С����ǰ
	else return A.name < B.name;          //����ֻ�����ֵ����ˣ�˭С˭���ֵ�����ǰ
}
int main()
{
	int N; cin >> N;           //ѧ�����Ķ��������
	int num = 0;//ѧУ��
	map<string, int> mp;                         //mp�������ѧУ���ַ������ṹ�������ӳ��
	for (int i = 0; i < N; i++)
	{
		string id, school; float score;
		cin >> id >> score >> school;
		for (int j = 0; j < school.length(); j++)
		{         //���ֱ�Сд
			school[j] = tolower(school[j]);
		}

		if (id[0] == 'B') score /= 1.5;          //���㵱ǰѧ�����Ը�ѧУ�������ٷ�
		if (id[0] == 'T') score *= 1.5;
		if (mp.count(school) == 0)
		{            //�����ѧУ��һ�γ���
			mp[school] = num++;
			arr[num - 1].name = school;
		}
		arr[mp[school]].score += score;           //�����ѧУ�������ѧ���ķ�
		arr[mp[school]].stu++;          //ѧУ��ѧ�����Ӽ�
	}
	sort(arr, arr + num, cmp);              //�Խṹ�������������

	int i_rank = 1;
	cout << num << endl;
	for (int i = 0; i < num; i++)
	{
		if (i&&int(arr[i].score) != int(arr[i - 1].score))i_rank = i + 1;

		cout << i_rank << ' ' << arr[i].name << ' ' << int(arr[i].score) << ' ' << arr[i].stu << endl;
	}
	return 0;
}