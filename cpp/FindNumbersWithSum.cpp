#include <vector>

using namespace std;

/*
��Ŀ����
����һ����������������һ������S���������в������������ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
������� :
��Ӧÿ�����԰����������������С���������
*/

// ����һ,O(n)
// ��ͷβ��ʼ����һ�Ժ�ΪS�ļ�Ϊ�˻���С��
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

// ������������
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