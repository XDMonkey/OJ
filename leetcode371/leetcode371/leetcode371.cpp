// leetcode371.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
using namespace std;
int main()
{
	int a;
	cin >> a;
	int b;
	cin >> b;
	int carry;
	while (b) {
		carry = a&b;
		a = a^b;
		b = carry<< 1;
	}
	cout << a;
    return 0;
}

