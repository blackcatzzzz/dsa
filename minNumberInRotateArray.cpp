#include <vector>

using namespace std;

/**
* ţ��/JZOFFER/��ת�������С����
*
* ��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
* ����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
* ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
* NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
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