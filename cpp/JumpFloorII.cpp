#include <iostream>

/*
* 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
* 求该青蛙跳上一个n级的台阶总共有多少种跳法。
*
*/
class Solution {
public:
	int jumpFloorII(int number) {
		return jumpFloorIIIteration(number);
	}

private:
	// f(0) = 1, f(1) = 1, f(2) = f(0) + f(1)
	// A:f(n) = f(n-1) + ……+ f(0)
	// B:f(n-1) = f(n-2)+……+ f(0)
	// A,B 2式相减 f(n) = 2*f(n-1), n >= 2
	int jumpFloorIIRecursion(int number)
	{
		if (number == 1)
			return 1;
		return jumpFloorIIRecursion(number - 1) * 2;
	}

	int jumpFloorIIIteration(int number)
	{
		int count = 1;
		// 迭代number-1次，即2的n-1次方
		while (number-- > 1)
			count *= 2;
		return count;
	}
};

int main()
{
	return 0;
}