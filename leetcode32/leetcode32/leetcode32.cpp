// leetcode32.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> paranStack;
		int maxLength = 0;
		int lastValidIndx = 0;
		for (int indx = 0; indx<s.length(); indx++) {
			if (s[indx] == '(')
				paranStack.push(indx);
			else {
				if (paranStack.empty())
					lastValidIndx = indx + 1;
				else {
					paranStack.pop();
					if (paranStack.empty())
						maxLength = max(maxLength, indx - lastValidIndx + 1);
					else
						maxLength = max(maxLength, indx - paranStack.top());
				}
			}
		}
		return maxLength;
	}
};
int main()
{
	string a(")(");
	Solution c;
	cout << c.longestValidParentheses(a);
	return 0;
}

