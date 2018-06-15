#include <iostream>

/*
* һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
* �����������һ��n����̨���ܹ��ж�����������
*
*/
class Solution {
public:
	int jumpFloorII(int number) {
		return jumpFloorIIIteration(number);
	}

private:
	// f(0) = 1, f(1) = 1, f(2) = f(0) + f(1)
	// A:f(n) = f(n-1) + ����+ f(0)
	// B:f(n-1) = f(n-2)+����+ f(0)
	// A,B 2ʽ��� f(n) = 2*f(n-1), n >= 2
	int jumpFloorIIRecursion(int number)
	{
		if (number == 1)
			return 1;
		return jumpFloorIIRecursion(number - 1) * 2;
	}

	int jumpFloorIIIteration(int number)
	{
		int count = 1;
		// ����number-1�Σ���2��n-1�η�
		while (number-- > 1)
			count *= 2;
		return count;
	}
};

int main()
{
	return 0;
}