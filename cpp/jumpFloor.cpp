#include <iostream>

/*
* ��Ŀ���� : һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
* �����������һ��n����̨���ܹ��ж�����������
*
*/

class Solution {
public:
	// ���Ʒ�������n��̨�ף�f(n) = f(n-1) + f(n-2)
	// ̨��1����fib(2) ̨��2����fib(3)
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