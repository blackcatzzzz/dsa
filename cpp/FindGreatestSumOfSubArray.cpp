#include <vector>

using namespace std;

// ��������������

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.size() == 0)
			return 0;
		return solution1(array);
	}

private:
	// ���������������
	int solution1(vector<int>& array)
	{
		int maxSum = INT_MIN;
		int curSum = 0;
		for (int i = 0; i < array.size(); ++i)
		{
			if (curSum <= 0)
				curSum = array[i];
			else
				curSum += array[i];

			if (curSum > maxSum)
				maxSum = curSum;
		}

		return maxSum;
	}
};

int main()
{
	return 0;
}