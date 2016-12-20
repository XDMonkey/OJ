// leetcode35.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int res = 0;
	void findIndex(vector<int> nums, int a, int b, int target) {
		if (a == b) {
			if (nums[a] >= target)
				res=a;
			else res = a + 1;
		}
		int mid = (a + b) / 2;
		if (target <= nums[mid]) 
			findIndex(nums, a, mid, target);
		else
			findIndex(nums, mid + 1, b, target);
	}
	int searchInsert(vector<int>& nums, int target) {
		findIndex(nums, 0, nums.size() - 1, target);
		return res;
	}
};
int main()
{
	vector<int> g;
	g.push_back(1);
	Solution h;
	h.searchInsert(g, 0);
    return 0;
}

