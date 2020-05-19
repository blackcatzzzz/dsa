// stackPermutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <iostream>

using namespace std;

// 设B 为A = { 1, 2, 3, ..., n }任一排列。
// 判断B是否为“禁形”,
bool forbiddenPattern(int b[], int n)
{
	stack<int> s; // 辅助中转栈S
	int i = 1; // 模拟源栈A
	for (size_t k = 0; k < n; k++)
	{
		while (s.empty() || b[k] != s.top() )
		{
			s.push(i++);
			//assert: 只要B[]的确不含禁形，则以上迭代就不可能导致栈A的溢出
			if (i > n + 1)
			{
				return false;
			}
		}
		//assert: 以上迭代退出时，S栈必然非空，且S的栈顶元素就是B[k]
		s.pop();
	}

	return true;
}

int main()
{
	int b[] = { 3, 1, 2 };
	int n = sizeof b / sizeof(int);
	cout << forbiddenPattern(b, n);
	getchar(); 
	return 0;
}

