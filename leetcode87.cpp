// leetcode87.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	bool isScramble(string s1, string s2) {
		int length = s1.size();
		int ***res = new int **[length];
		for (int i = 0; i < length; i++) {
			res[i] = new int*[length];
			for (int j = 0; j < length; j++)
				res[i][j] = new int[length];
		}
		for (int i = 0; i < length; i++)
			for (int j = 0; j < length; j++) {
				if (s1[i] != s2[j])
					res[0][i][j] = false;
				else
					res[0][i][j] = true;
			}
		for (int i = 0; i < length; i++) {
			for (int j = 0; j <= length - 1 - i; j++) {
				for (int m = 0; m <= length - 1 - i; m++)
					for (int k = 0; k < i; k++) {
						if ((res[k][j][m] && res[i - k - 1][j + k + 1][m + k + 1]) || (res[k][j][m + i - k] && res[i - k - 1][j + k + 1][m])) {
							res[i][j][m] = true;
							break;
						}
						res[i][j][m] = false;
					}
			}
		}
		return res[length - 1][0][0];
	}
};
int main()
{
	Solution a;
	if (a.isScramble("rgtae", "great"))
		cout << "yes";
	return 0;
}

