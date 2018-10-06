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
	bool hasCycle(ListNode *head)
	{
		map<ListNode*, int> mp;
		ListNode* tmp = head;
		while (tmp != nullptr)
		{
			if (mp[tmp] != 0)return true;
			else mp[tmp]++;
			tmp = tmp->next;
		}
		return false;
	}
};