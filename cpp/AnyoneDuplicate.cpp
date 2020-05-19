#include <iostream>
#include <unordered_set>

using namespace std;

/*
* 在一个长度为n的数组里的所有数字都在0到n - 1的范围内。 数组中某些数字是重复的，
* 但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
* 例如，如果输入长度为7的数组{ 2, 3, 1, 0, 2, 5, 3 }，那么对应的输出是第一个重复的数字2。
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

	// 由于数组长度为n，每个元素可以尝试将自己放在对应下标位置上，如果有重复元素则会在对应下标位置相等。
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
