// leetcode41.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Solution {
public:
	map<int, int> rec;
	Solution() {
		rec[0] = 1;
	}
	void addTheNum(vector<int>::iterator a) {
		if (*a > 0)
			rec[*a] = 1;
	}
	int firstMissingPositive(vector<int>& nums) {
		for (auto a = nums.begin(); a < nums.end(); a++) {
			addTheNum(a);
		}
		auto a = rec.begin();
		a++;
		if (a != rec.end()) {
			for (; a != rec.end(); a++) {
				auto b = a;
				b--;
				if (a->first - b->first != 1)
					return b->first + 1;
			}
			a--;
			return a->first + 1;
		}
		return 1;
	}
};
int main()
{
	vector<int> a{ 1 };
	Solution b;
	cout << b.firstMissingPositive(a);
	return 0;
}

