// leetcode22.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<vector>
using namespace std;
vector<string> ans;
void choose(string ser, int leftNum, int rightNum, int cur, int n) {
	int flag = 0;
	if (cur >= 2 * n)
		ans.push_back(ser);
	else {
		
		if (leftNum + 1 <= n)
			choose(ser + "(", leftNum + 1, rightNum, cur + 1, n);
		if (rightNum + 1 <= leftNum&&rightNum + 1 <= n)
			choose(ser + ")", leftNum, rightNum + 1, cur + 1, n);
	}
}
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		string ser;
		choose(ser, 0, 0, 0, n);
		return ans;
	}
};

int main()
{	
	Solution a;
	a.generateParenthesis(4);
	

	return 0;
}

