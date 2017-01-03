// leetcode55.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int index = 0;
		while (1) {
			if (index + nums[index] >= nums.size()-1)
				return true;
			if (!nums[index] && index < nums.size() - 1)
				return false;
			else {
				int temp = nums[index] + index;
				for (int i = index; i < index + nums[index]; i++) {
					if (nums[i] + i > temp + nums[temp])
						temp = i;
				}
				index = temp;
			}
		}
	}
};

int main()
{
    return 0;
}

