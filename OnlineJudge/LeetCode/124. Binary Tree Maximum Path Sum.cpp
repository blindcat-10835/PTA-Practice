#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
static int x = []()
{
	ios::sync_with_stdio(false);    // cin与stdin禁止同步
	cin.tie(NULL);                  //cin与cout解除绑定
	return 0;
}();
typedef string OutType;
typedef vector<string> InType;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
	int maxPathSum(TreeNode* root)
	{
		queue<TreeNode*> Q;
		Q.push(root);
		int maxSum = root->val;
		while (!Q.empty())
		{
			TreeNode* t = Q.front();
			if (t->left != nullptr)
			{
				Q.push(t->left);
			}
			if (t->right != nullptr)
			{
				Q.push(t->right);
			}
			maxSum = max(maxSum, PathSumVia(t));
			Q.pop();
		}
		return maxSum;
	}
	int PathSumVia(TreeNode* root)
	{
		if (root == nullptr)return 0;
		return root->val + maxSingle(root->left) + maxSingle(root->right);
	}
	int maxSingle(TreeNode* root)
	{
		if (root == nullptr)return 0;
		return  max(0, root->val + max(maxSingle(root->left), maxSingle(root->right)));
	}
};
void trimLeftTrailingSpaces(string &input)
{
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
	{
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input)
{
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
	{
		return !isspace(ch);
	}).base(), input.end());
}

TreeNode* stringToTreeNode(string input)
{
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size())
	{
		return nullptr;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true)
	{
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ','))
		{
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null")
		{
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!getline(ss, item, ','))
		{
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null")
		{
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		TreeNode* root = stringToTreeNode(line);

		int ret = Solution().maxPathSum(root);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}