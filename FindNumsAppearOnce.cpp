#include <vector>

using namespace std;

/*
* һ�����������������������֮�⣬���������ֶ����������Ρ�
* ��д�����ҳ�������ֻ����һ�ε����֡�
*/

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		if (data.size() < 2)
			return;
		int resultExclusiveOR = 0;
		for (int i = 0; i < data.size(); ++i)
			resultExclusiveOR ^= data[i];
		int index = findFirstBitIs1(resultExclusiveOR);

		for (int i = 0; i < data.size(); ++i)
		{
			if (isBit1(data[i], index))
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}

		return;
	}

private:
	int findFirstBitIs1(int number)
	{
		int index = 0;
		while ((number & 1) == 0 && index < 8 * sizeof(int))
		{
			number >>= 1;
			++index;
		}

		return index;
	}

	bool isBit1(int number, int index)
	{
		number = number >> index;
		return number & 1;
	}
};

// 2018.6.19
class Solution1 {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		if (data.size() < 2)
			return;

		int resultExclusiveOR = 0;
		for (int i = 0; i < data.size(); ++i)
			resultExclusiveOR ^= data[i];

		int index = findFirstBitIs1(resultExclusiveOR);

		for (int i = 0; i < data.size(); ++i)
		{
			if (isBit1(data[i], index))
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}

		return;
	}

private:
	int findFirstBitIs1(int number)
	{
		int index = 0;
		while ((number & 1) == 0 && index < 8 * sizeof(int))
		{
			number >>= 1;
			index++;
		}

		return index;
	}

	bool isBit1(int number, int index)
	{
		return (number >> index) & 1;
	}
};

int main()
{
	return 0;
}