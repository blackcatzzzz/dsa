#include <iostream>

/*
* 题目描述 : 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
* 求该青蛙跳上一个n级的台阶总共有多少种跳法。
*
*/

class Solution {
public:
	// 倒推分析，到n级台阶，f(n) = f(n-1) + f(n-2)
	// 台阶1：求fib(2) 台阶2：求fib(3)
	int jumpFloor(int number) {
		int f = 1, g = 0;
		while (number-- >= 0)
		{
			g = f + g;
			f = g - f;
		}

		return g;
	}
};

int main()
{
	return 0;
}