// leetcode62.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

long long factorial(int a) {
	if (a == 1)
		return 1;
	else
		return factorial(a - 1)*a;
 }
long long Axx(int m, int n) {
	long long res = 1;
	long long tempN = n;
	while (tempN) {
		res = res*(m - (n - tempN));
		tempN--;
	}
	return res;
}
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < n)
			swap(m, n);
		if (n == 1 || m == 1)
			return 1;
		return Axx(m+n-2, n-1) / factorial(n-1);
	}
};
int main()
{	
	Solution a;
	a.uniquePaths(2, 100);
    return 0;
}

