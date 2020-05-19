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
	// ˼·��
	// 1.���ҵ���һ��ż��λ��i
	// 2.Ȼ���i+1��ʼ������������ҵ�����(λ��j)������������λ��i,ͬʱ��[i,j-1]��������Ųһ��λ�ü�a[j] = a[j-1](j����[i+1,j]);
	//		                  ���û�ҵ�����˵��ż����û�����������������	
	//        
	void solution_insertion1(vector<int> &array)
	{
		// �ҵ���һ��ż��λ��
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