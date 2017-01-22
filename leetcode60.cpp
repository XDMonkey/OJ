// leetcode60.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <list>
#include <string>
using namespace std;
int factorial(int a) {
	if (a != 1)
		return factorial(a - 1)*a;
	return 1;
}

class Solution {
public:
	list<char> counter;
	string getPermutation(int n, int k) {
		string res(n, '1');
		int resBegin = 0;
		for (int i = 1; i <= n; i++)
			counter.emplace_back(i + '0');
		k--;
		int flag = n - 1;
		int index = 0;
		if (!flag)
			return res;
		while (1) {
			int a = k / factorial(flag);
			auto data = counter.begin();
			for (int i = 0; i < a; i++)
				data++;
			res[index++] = *data;
			counter.erase(data);
			if (index == n - 1) {
				res[index] = *counter.begin();
				return res;
			}
			k = k - a*factorial(flag--);
		}
	}
};
int main()
{
	Solution a;
	a.getPermutation(4, 2);
	return 0;
}
