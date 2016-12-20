// leetcode29.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<limits.h>
#include<math.h>
#include<iostream>
using namespace std;
long long int divideLong(long long dividend, long long divisor) {
	if (divisor==0)
		return INT_MAX;//如果除数为0
	if (dividend==0)
		return 0;//如果被除数为0
	int place = 0;
	int res = 0;
	int flag = 0;
	int sign = 1;
	if ((dividend<0)^(divisor<0))
		sign = -1;
	dividend = abs(dividend);
	divisor = abs(divisor);
	while (dividend >= divisor) {
		place = 1;
		flag = 0;
		while (divisor << place < dividend) {
			divisor <<= 1;
			place++;
			flag = 1;
		}
		if (divisor == dividend) {
			res += pow(2, place-1);
			break;
		}
	if (flag) {
			dividend -= divisor;
			divisor >>= place-1;
			res += pow(2, place-1);
		}
	else {
		divisor >>= place-1;
		if (dividend > divisor)
			res += 1;
		dividend -= divisor;
	}
 }
	return res*sign;
}
class Solution {
public:
	    int divide(int dividend, int divisor) {
		long long int ret = divideLong(dividend, divisor);
		if (ret<INT_MIN || ret>INT_MAX)
			return INT_MAX;
		else return ret;
	}
};
int main()
{
	Solution a;
	cout << a.divide(-2147483648,-1) << endl;
	return 0;
}

