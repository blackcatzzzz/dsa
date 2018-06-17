#include <vector>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0)
			return 0;

		int maj = majEleCandidate(numbers);

		return majEleCheck(numbers, maj) ? maj : 0;

	}

private:

	// 方法一：剪枝法
	int majEleCandidate(vector<int>& numbers)
	{
		int maj;
		for (int c = 0, i = 0; i < numbers.size(); ++i)
		{
			if (c == 0)
			{
				maj = numbers[i];
				c = 1;
			}
			else
			{
				maj == numbers[i] ? c++ : c--;
			}
		}

		return maj;
	}

	bool majEleCheck(vector<int>& numbers, int maj)
	{
		int c = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (maj == numbers[i])
				c++;
		}

		return c > numbers.size() / 2;
	}
};

int main()
{
	return 0;
}