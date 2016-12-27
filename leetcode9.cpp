// leetcode9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> a;
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (!x)
			return true;
		transferToVec(x);
		for (int i = 0; i <= (a.size() - 1) / 2; i++) {
			if (a[i] != a[a.size() - 1 - i])
				return false;
		}
		return true;
	}
	void transferToVec(int x) {
		while (x) {

			a.emplace_back(x%10);
			x = (x - x % 10) / 10;
		}
	}
};
int main()
{
	Solution a;
	a.isPalindrome(11);
	return 0;
}

