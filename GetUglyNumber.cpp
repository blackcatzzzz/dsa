#include <vector>

using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index <= 0)
			return 0;

		return getUglyNumber(index);
	}

private:
	int getUglyNumber(int index)
	{
		vector<int> vecUglyNumber(index);
		int curUglyIndex = 0;
		vecUglyNumber[curUglyIndex] = 1;

		int mutiply2Index = 0;
		int mutiply3Index = 0;
		int mutiply5Index = 0;

		while (curUglyIndex < index - 1)
		{
			while (vecUglyNumber[mutiply2Index] * 2 <= vecUglyNumber[curUglyIndex])
				mutiply2Index++;
			while (vecUglyNumber[mutiply3Index] * 3 <= vecUglyNumber[curUglyIndex])
				mutiply3Index++;
			while (vecUglyNumber[mutiply5Index] * 5 <= vecUglyNumber[curUglyIndex])
				mutiply5Index++;

			vecUglyNumber[++curUglyIndex] = min(vecUglyNumber[mutiply2Index] * 2,
				vecUglyNumber[mutiply3Index] * 3,
				vecUglyNumber[mutiply5Index] * 5);
		}

		return vecUglyNumber[curUglyIndex];

	}

	int min(int num1, int num2, int num3)
	{
		int min = num1 <= num2 ? num1 : num2;
		min = min <= num3 ? min : num3;
		return min;
	}

	// 蛮力算法，时间复杂度过高,不能通过，只为练习。
	int getUglyNumber_BF(int index)
	{
		int number = 1;
		int uglyFoundCount = 0;
		while (uglyFoundCount < index)
		{
			if (isUgly(number))
				uglyFoundCount++;
			number++;
		}
		return number;
	}

	bool isUgly(int number)
	{
		while (number % 2 == 0)
			number /= 2;
		while (number % 3 == 0)
			number /= 3;
		while (number % 5 == 0)
			number /= 5;
		return number == 1 ? true : false;
	}

};

int main()
{
	vector<int> v(2);
	v.push_back(1);
	return 0;
}