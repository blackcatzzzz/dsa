#include <vector>

using namespace std;

/*
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述 :
对应每个测试案例，输出两个数，小的先输出。
*/

// 方法一,O(n)
// 从头尾开始，第一对和为S的即为乘积最小的
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		if (array.size() == 0)
			return vector<int>();

		vector<int> vecRes;
		int smallIndex = 0;
		int bigIndex = array.size() - 1;
		int curSum = array[smallIndex] + array[bigIndex];
		while (smallIndex <= bigIndex)
		{
			if (curSum == sum)
			{
				vecRes.push_back(array[smallIndex]);
				vecRes.push_back(array[bigIndex]);
				return vecRes;
			}
			else if (curSum < sum)
			{
				curSum = curSum - array[smallIndex] + array[++smallIndex];
			}
			else
			{
				curSum = curSum - array[bigIndex] + array[--bigIndex];
			}
		}

		return vecRes;
	}
};

// 方法二，暴力
class Solution1 {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		if (array.size() <= 1)
			return vector<int>();

		vector<int> vecRes;
		int small = 0, big = 1;
		int product = INT_MAX;
		while (array[small] < (sum + 1) / 2)
		{
			for (big = small + 1; big < array.size(); ++big)
			{
				if (array[small] + array[big] == sum && product > array[small] * array[big])
				{
					product = array[small] * array[big];
					vecRes.clear();
					vecRes.push_back(array[small]);
					vecRes.push_back(array[big]);
				}
			}

			small++;
		}

		return vecRes;
	}
};

int main()
{
	return 0;
}