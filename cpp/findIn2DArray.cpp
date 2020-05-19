#include <vector>
#include <iostream>

using namespace std;

/******
* ţ��/JzOffer/��ά�����еĲ��� 
*
* ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
* �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
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