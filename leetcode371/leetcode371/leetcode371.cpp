// leetcode371.cpp : �������̨Ӧ�ó������ڵ㡣
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

