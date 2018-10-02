#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
typedef ListNode* OutType;
typedef ListNode* InType;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		string result = "";
		int c = 0;
		while (l1 != nullptr&& l2 != nullptr)
		{
			int tmp = l1->val + l2->val + c;
			c = 0;
			if (tmp >= 10) { c = 1, tmp -= 10; }
			result = to_string(tmp) + result;
			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1 != nullptr)
		{
			int tmp = l1->val + c;
			c = 0;
			if (tmp >= 10) { c = 1, tmp -= 10; }
			result = to_string(tmp) + result;

			l1 = l1->next;
		}
		while (l2 != nullptr)
		{
			int tmp = l2->val + c;
			c = 0;
			if (tmp >= 10) { c = 1, tmp -= 10; }
			result = to_string(tmp) + result;
			l2 = l2->next;
		}
		if (c)result = "1" + result;
		ListNode* ret = new ListNode(0), *t3 = ret;
		for (auto iter = result.rbegin(); iter != result.rend(); iter++)
		{
			t3->next = new ListNode(*iter - '0');
			t3 = t3->next;
		}
		ret = ret->next;
		t3 = nullptr;
		delete t3;
		return ret;
	}
};
int main(int argc, char const *argv[])
{
	InType S1 = new ListNode(2), t1 = S1;
	t1->next = new ListNode(4);
	t1 = t1->next;
	t1->next = new ListNode(3);

	InType S2 = new ListNode(5), t2 = S2;
	t2->next = new ListNode(6);
	t2 = t2->next;
	t2->next = new ListNode(4);
	t1 = t2 = nullptr;
	Solution Condition;
	OutType Result = Condition.addTwoNumbers(S1, S2);
	//cout << Result << endl;
	while (Result != nullptr)
	{
		cout << Result->val << endl;
		Result = Result->next;
	}
	delete S1, S2, t1, t2;
	return 0;
}