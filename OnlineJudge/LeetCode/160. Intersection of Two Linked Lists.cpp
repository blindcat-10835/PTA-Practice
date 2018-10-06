static int x = []()
{
	ios::sync_with_stdio(false);    // cin与stdin禁止同步
	cin.tie(NULL);                  //cin与cout解除绑定
	return 0;
}();
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (headA == nullptr || headB == nullptr)return nullptr;

		ListNode *A = headA, *B = headB;
		while (headA != nullptr && headB != nullptr)
		{
			headA = headA->next; headB = headB->next;
		}
		bool a = true;
		int difLen = 0;
		while (headA != nullptr)
		{
			a = true;
			headA = headA->next;
			difLen++;
		}
		while (headB != nullptr)
		{
			a = false;
			headB = headB->next;
			difLen++;
		}

		while (difLen--)
		{
			if (a)A = A->next;
			else B = B->next;
		}
		while (A != nullptr
			&& B != nullptr
			&& A != B)
		{
			A = A->next; B = B->next;
		}
		if (A == B)return A;
		else return nullptr;
	}
};