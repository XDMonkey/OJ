// leetcode53.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> maxByIndex(nums.size());
		maxByIndex[0]=nums[0];
		int res = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			maxByIndex[i] = max(nums[i], maxByIndex[i - 1] + nums[i]);
			if (res < maxByIndex[i])
				res = maxByIndex[i];
		}
		return res;
	}
};
int main()
{
	Solution a;
	vector<int> b = { -2,1,-3,4,-1,2,1,-5,4 };
	a.maxSubArray(b);
    return 0;
}

