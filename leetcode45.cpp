// leetcode45.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int step = 0;
	void chooseRoute(vector<int>& nums, int startP) {
		if (startP == nums.size() - 1)
			return;
		int firstP = startP + nums[startP];
		if (firstP >= nums.size() - 1) {
			step++;
			return;
		}
		int secondP = firstP + nums[firstP];
		int max = secondP;
		int newFirstOne = firstP;
		for (int i = startP; i < firstP; i++) {
			if (i + nums[i] > newFirstOne+nums[newFirstOne]) {
				newFirstOne = i;
			}
		}
		step++;
		chooseRoute(nums, newFirstOne);
	}
	int jump(vector<int>& nums) {
		chooseRoute(nums, 0);
		return step;
	}
};
int main()
{
	vector<int> c{ 0 };
	Solution b;
	cout<<b.jump(c);
    return 0;
}

