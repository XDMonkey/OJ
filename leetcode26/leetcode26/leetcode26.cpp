// leetcode26.cpp : �������̨Ӧ�ó������ڵ㡣
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
			if (*cur != *(cur+1) && (cur + 1) != nums.end()) {//�����һ����Ϊ�գ�������һ������ͬ��
				cur = nums.erase(cur);
			}
			else if (cur + 1 == nums.end())//�����һ��Ϊ��
				return num;
			else//�����һ����Ϊ�գ����ǲ���ͬ
				cur++;
		}
	}
};

int main()
{
    return 0;
}

