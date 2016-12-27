// leetcode47.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	vector<int> singleRes;
	vector<vector<int>> res;
	vector<int> singleInt;
	int sum = 0;
	void getSingleRes(vector<int> &nums, int n, int lastIndex, map<int, int> &numsRec) {
		if (n == sum)
			res.emplace_back(singleRes);
		else {
			int i = 1;
			while (i == 1 || singleInt[(lastIndex + i) % singleInt.size()] != singleInt[(lastIndex + 1) % singleInt.size()]) {
				if (numsRec[singleInt[(lastIndex + i) % singleInt.size()]] > 0) {
					numsRec[singleInt[(lastIndex + i) % singleInt.size()]]--;
					singleRes.emplace_back(singleInt[(lastIndex + i) % singleInt.size()]);
					getSingleRes(nums, n + 1, (lastIndex + i) % singleInt.size(), numsRec);
					singleRes.pop_back();
					numsRec[singleInt[(lastIndex + i) % singleInt.size()]]++;
				}
				i++;
			}
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		map<int, int> numsRec;
		for (int i = 0; i < nums.size(); i++) {
			if (!numsRec[nums[i]])
				singleInt.emplace_back(nums[i]);
			numsRec[nums[i]]++;
			sum++;
		}
		getSingleRes(nums, 0, -1, numsRec);
		return res;
	}
};
int main()
{
	Solution a;
	vector<int> b{ 1,1,2 };
	a.permuteUnique(b);
    return 0;
}

