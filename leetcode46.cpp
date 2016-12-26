// leetcode46.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> a;
	void generateAlignment(vector<int>& nums, int order,vector<int> single) {
		if (order == nums.size())
			a.emplace_back(single);
		else {
	//		auto begin = single.begin();
			for (int i = 0; i <= order; i++) {
				single.insert(single.begin()+i, nums[order]);
				generateAlignment(nums, order + 1, single);
				single.erase(single.begin() + i);
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> b;
		generateAlignment(nums, 0, b);
		return a;
	}
};
int main()
{
	vector<int> a{ 1,2,3 };
	Solution c;
	c.permute(a);
    return 0;
}

