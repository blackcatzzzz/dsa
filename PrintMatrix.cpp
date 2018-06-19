#include <iostream>
#include <vector>

using namespace std;

/*
* 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
*/
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result;
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return result;

		int rows = matrix.size();
		int columns = matrix[0].size();

		int startX = 0, startY = 0;
		int endX = columns - 1, endY = rows - 1;

		while (startX <= endX && startY <= endY)
		{
			for (int i = startX; i <= endX; ++i)
				result.push_back(matrix[startY][i]);

			if (startY + 1 > endY)
				break;
			for (int i = startY + 1; i <= endY; ++i)
				result.push_back(matrix[i][endX]);

			if (endX - 1 < startX)
				break;
			for (int i = endX - 1; i >= startX; --i)
				result.push_back(matrix[endY][i]);

			if (endY - 1 <= startY)
				break;
			for (int i = endY - 1; i > startY; --i)
				result.push_back(matrix[i][startX]);

			++startX;
			++startY;
			--endX;
			--endY;
		}

		return result;
	}
};

int main()
{
	//vector<vector<int>> v = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	//vector<vector<int>> v = { { 1, 2 }, { 4, 5 }, { 7, 8} };
	vector<vector<int>> v = { { 1 }, { 4 }, { 7 } };
	Solution s;
	auto res = s.printMatrix(v);
	getchar();
	return 0;
}