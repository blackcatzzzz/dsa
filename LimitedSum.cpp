#include <iostream>

using namespace std;
/*
* ��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����
*/

class Solution {
public:
	int Sum_Solution(int n) {
		Sum::reset();
		Sum * s = new Sum[n];
		delete[] s;
		s = NULL;

		return Sum::getSum();
	}

private:

	class Sum
	{
	public:
		Sum(){ ++n; sum += n; }
		static void reset(){ n = 0; sum = 0; }
		static int getSum(){ return sum; }
	private:
		static int sum;
		static int n;
	};
};

int Solution::Sum::sum = 0;
int Solution::Sum::n = 0;

int main()
{
	return 0;
}