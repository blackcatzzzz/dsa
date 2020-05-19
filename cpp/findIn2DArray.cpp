#include <vector>
#include <iostream>

using namespace std;

/******
* 牛客/JzOffer/二维数组中的查找 
*
* 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
* 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*******/
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		size_t n = array.size();
		if (n == 0)
			return false;
		size_t m = array[0].size();
		int i = 0, j = m - 1;
		while (i < n && j >= 0)
		{
			if (array[i][j] < target)
				i++;
			else if (target < array[i][j])
				j--;
			else
				return true;
		}
		return false;
	}
};

int main()
{
	//7, [[1, 2, 8, 9], [2, 4, 9, 12], [4, 7, 10, 13], [6, 8, 11, 15]]

	vector<vector<int>> v{ { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Solution s;
	cout << s.Find(7, v) << endl;
	getchar();
	return 0;
}