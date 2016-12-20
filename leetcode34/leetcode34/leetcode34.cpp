// leetcode34.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> d;
	int start_i = -1;
	int end_i = -1;
	void findIndex(vector<int> nums, int a, int b, int target, int flag) {
		if (a != b) {
			int mid = (a + b) / 2;
			if (nums[mid] == target) {
				if (!flag1) {
					flag1 = 1;
					findIndex(nums, a, mid, target, -1);
					findIndex(nums, mid + 1, b, target, 1);
				}
				else {
					if (flag == -1)
						findIndex(nums, a, mid, target, -1);
					else if (flag == 1)
						findIndex(nums, mid + 1, b, target, 1);

				}
			}
			else if (nums[mid]>target) {
				findIndex(nums, a, mid, target, flag);

			}
			else {
				findIndex(nums, mid + 1, b, target, flag);
			}
		}
		else {
			if (nums[a] == target) {
				if (flag == -1) {
					start_i = a;
				}
				if (flag == 1) {
					end_i = a;
				}
				else {
					start_i = a;
					end_i = a;
				}
			}
			else if (start_i != -1)
				end_i = a - 1;
		}

	}
	int flag1 = 0;
	vector<int> searchRange(vector<int>& nums, int target) {
		findIndex(nums, 0, nums.size() - 1, target, 0);
		if (start_i != -1 && end_i == -1)
			end_i = start_i;
		else if (end_i != -1 && start_i == -1)
			start_i = end_i;
		d.push_back(start_i);
		d.push_back(end_i);
		return d;
	}
};
int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	Solution c;
	c.searchRange(a, 2);
	return 0;
}

