#include <vector>

using namespace std;

/**
* 牛客/JZOFFER/旋转数组的最小数字
*
* 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
* 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
* 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
* NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*
*/

// old
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;

		int index = 0;
		for (; index < rotateArray.size() - 1; ++index)
		{
			if (rotateArray[index] > rotateArray[index + 1])
				break;
		}

		if (index < rotateArray.size() - 1)
			return rotateArray[index + 1];
		else
			return rotateArray[index];
	}
};

// 2016.6.15
class Solution1 {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;

		for (size_t i = 0; i < rotateArray.size() - 1; ++i)
		{
			if (rotateArray[i] <= rotateArray[i + 1])
				continue;
			else
				return rotateArray[i + 1];
		}

		return rotateArray[0];
	}
};

int main()
{
	return 0;
}