#include <iostream>
#include <unordered_set>

using namespace std;

/*
* ��һ������Ϊn����������������ֶ���0��n - 1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�
* ����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� 
* ���磬������볤��Ϊ7������{ 2, 3, 1, 0, 2, 5, 3 }����ô��Ӧ������ǵ�һ���ظ�������2��
*/

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == NULL || length <= 0)
			return false;

		return solution_swap(numbers, length, duplication);
	}

private:
	bool solution_hash(int numbers[], int length, int* duplication)
	{
		unordered_set<int> setNum;
		for (int i = 0; i < length; ++i)
		{
			if (setNum.find(numbers[i]) == setNum.end())
			{
				setNum.insert(numbers[i]);
			}
			else
			{
				*duplication = numbers[i];
				return true;
			}
		}

		return false;
	}

	// �������鳤��Ϊn��ÿ��Ԫ�ؿ��Գ��Խ��Լ����ڶ�Ӧ�±�λ���ϣ�������ظ�Ԫ������ڶ�Ӧ�±�λ����ȡ�
	bool solution_swap(int numbers[], int length, int* duplication)
	{
		for (int i = 0; i < length; ++i)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}

				swap(numbers[i], numbers[numbers[i]]);
			}
		}

		return false;
	}
};

int main()
{
	return 0;
}
