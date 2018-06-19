#include <iostream>

using namespace std;
/*
* 求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
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