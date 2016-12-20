// leetcode26.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int> &nums) {
		int num=1;
		auto cur = nums.begin();
		if (nums.begin() == nums.end())
			return 0;
		while (1) {
			if (*cur != *(cur+1) && (cur + 1) != nums.end()) {//如果下一个不为空，且与这一个是相同的
				cur = nums.erase(cur);
			}
			else if (cur + 1 == nums.end())//如果下一个为空
				return num;
			else//如果下一个不为空，但是不相同
				cur++;
		}
	}
};

int main()
{
    return 0;
}

