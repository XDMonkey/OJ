// leetcode33.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void findIndex(vector<int> &nums, int a, int b,int target) {
		int mid = (a + b) / 2;
		if (nums[mid] == target) {
			res = mid;
			return;
		}
		if (target < nums[mid]&&target>=nums[a]) {
			findIndex(nums, a, mid, target);
	 }
		if (target > nums[mid]&&target<=nums[b]) {
			findIndex(nums, mid + 1, b, target);
		}
	}
	int m = 0;
	int n = 0;
	int res=-1;
	int search(vector<int>& nums, int target) {
		int i = 0;
		while(i+1<nums.size()) {
			if (nums[i + 1] < nums[i])
				break;
			i++;
		}
		if (i != nums.size() - 1) {
			m = i + 1;
			n = nums.size() - m;
			auto nums_i = nums.begin();
			advance(nums_i, m);
			reverse(nums.begin(), nums_i);
			reverse(nums_i, nums.end());
			reverse(nums.begin(), nums.end());
		}
		int length = nums.size();
		findIndex(nums, 0, length - 1, target);
		if (res != -1&&i!=nums.size()-1) {
			if (res < n)
				return m + res;
			else
				return res - n;
		}
		return res;
	}
};

int main()
{
	vector<int> a;

	a.push_back(1);
	Solution b;
	b.search(a, 1);
    return 0;
}

