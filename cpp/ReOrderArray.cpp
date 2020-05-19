#include <vector>
#include <list>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.size() == 0)
			return;

		solution_list(array);

		return;
	}
private:

	void solution_copy(vector<int> &array)
	{
		vector<int> oddVec;
		vector<int> evenVec;
		for (int i = 0; i < array.size(); ++i)
		{
			if (isOdd(array[i]))
				oddVec.push_back(array[i]);
			else
				evenVec.push_back(array[i]);
		}

		int i = 0;
		for (; i < oddVec.size(); ++i)
			array[i] = oddVec[i];

		for (int j = 0; j < evenVec.size(); ++j)
			array[i + j] = evenVec[j];
	}

	void solution_insertion(vector<int> &array)
	{
		for (unsigned int i = 0, j = 0; i <= j && j < array.size(); ++j)
		{
			if (isOdd(array[j]))
			{
				int temp = array[j];
				for (unsigned int k = j; k > i; --k)
					array[k] = array[k - 1];
				array[i] = temp;
				++i;
			}
		}
	}

	// 2018.6.15
	// 思路：
	// 1.先找到第一个偶数位置i
	// 2.然后从i+1开始找奇数，如果找到奇数(位置j)，则将奇数插入位置i,同时将[i,j-1]的数往后挪一个位置即a[j] = a[j-1](j属于[i+1,j]);
	//		                  如果没找到，则说明偶数后没有奇数，即完成排序。	
	//        
	void solution_insertion1(vector<int> &array)
	{
		// 找到第一个偶数位置
		int evenIndex = 0;
		for (; evenIndex < array.size(); ++evenIndex)
			if (!isOdd(array[evenIndex]))
				break;
		int i = evenIndex + 1;
		for (; i < array.size(); ++i)
		{
			if (isOdd(array[i]))
			{
				int tmp = array[i];
				for (int j = i; j > evenIndex; --j)
				{
					array[j] = array[j - 1];
				}
				array[evenIndex] = tmp;
				++evenIndex;
			}
		}
	}

	void solution_list(vector<int> &array)
	{
		list<int> l(array.begin(), array.end());

		for (list<int>::iterator itInsertPosi = l.begin(), it = l.begin(); it != l.end();)
		{
			if (isOdd(*it))
			{
				if (it != itInsertPosi)
				{
					l.insert(itInsertPosi, *it);
					it = l.erase(it);
				}
				else
				{
					++itInsertPosi;
					++it;
				}
			}
			else
				++it;
		}

		int i = 0;
		for (list<int>::iterator it = l.begin(); it != l.end(); ++it, ++i)
			array[i] = *it;
	}

	bool isOdd(int num)
	{
		return num % 2;
	}
};

int main()
{

}