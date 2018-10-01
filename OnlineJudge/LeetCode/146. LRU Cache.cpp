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
typedef int OutType;
typedef vector<int> InType;
class LRUCache
{
private:
	map<int, int> mp;
	list<int> ls;
	int Capacity = 0;
public:
	LRUCache(int capacity)
	{
		Capacity = capacity;
	}
	int get(int key)
	{
		if (mp.find(key) == mp.end())return -1;
		ls.remove(key);
		ls.push_back(key);
		return mp[key];
	}
	void put(int key, int value)
	{
		if (mp.find(key) == mp.end())ls.push_back(key);
		else
		{
			ls.remove(key);
			ls.push_back(key);
		}
		mp[key] = value;
		if (ls.size() > Capacity)
		{
			if (mp.size() > Capacity)mp.erase(ls.front());
			ls.pop_front();
		}
	};
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
int main(int argc, char const *argv[])
{
	LRUCache cache(2 /* capacity */);
	cache.put(2, 2);
	cache.put(1, 1);
	cache.put(2, 3);    // evicts key 2
	cache.put(4, 1);    // evicts key 1
	cout << cache.get(1) << endl;       // returns 1
	cout << cache.get(2) << endl;       // returns -1 (not found)
	//cout << cache.get(1) << endl;       // returns -1 (not found)
	//cout << cache.get(3) << endl;       // returns 3
	//cout << cache.get(4) << endl;       // returns 4

	/*InType S = { -1 ,-2 };
	Solution Condition;
	OutType Result = Condition.maxSubArray(S);
	cout << Result << endl;*/
	return 0;
}