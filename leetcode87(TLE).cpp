// leetcode87.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	bool isScramble(string s1, string s2) {
		return judge(s1, s2, 0, s1.size() - 1, 0, s2.size() - 1);
	}
	bool judge(string &s1, string &s2, int a1, int b1, int a2, int b2) {
		if (a1 == b1&&a2 == b2) {
			if (s1[a1] == s2[a2])
				return true;
			return false;
		}
		else {
			for (int i = 0; i < b1 - a1; i++) {
				if (judge(s1, s2, a1, a1 + i, a2, a2 + i) && judge(s1, s2, a1 + i + 1, b1, a2 + i + 1, b2))
					return true;
				if (judge(s1, s2, a1, a1 + i, b2 - i, b2) && judge(s1, s2, a1 + i + 1, b1, a2, b2 - i - 1))
					return true;
			}
			return false;
		}
	}
};
int main()
{
	Solution a;
	if (a.isScramble("ab", "aa"))
		cout << "yes";
	return 0;
}

