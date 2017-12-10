// radixConvert.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <iostream>

using namespace std;

// 将数字转换成对应进制
// 递归版本
void convert_recursion(stack<char>& S, __int64 n, int base)
{
	static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	if (n > 0)
	{
		S.push(digit[n % base]);
		convert_recursion(S, n / base, base);
	}

	return;
}

// 迭代版本
void convert_iteration(stack<char>& S, __int64 n, int base)
{
	static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	while (n > 0)
	{
		int remainder = (int)(n % base);
		S.push(digit[remainder]);
		n = n / base;
	}

	return;
}

template <typename T>
void printStack(T & s)
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

int main()
{
	__int64 n = 0x64;

	stack<char> S;
	convert_iteration(S, n , 16);
	printStack(S);

	convert_recursion(S, n, 10);
	printStack(S);
	getchar();
	return 0;
}

