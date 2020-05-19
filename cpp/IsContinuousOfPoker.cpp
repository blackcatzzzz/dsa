#include <algorithm>
#include <vector>

using namespace std;

/*
* LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
* ��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���
* ������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,������\С ��
* ���Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),
* ��So Lucky!����LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Ρ�
* Ϊ�˷������,�������Ϊ��С����0��
*/

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() == 0)
			return false;
		sort(numbers.begin(), numbers.end());

		int countOfZero = 0;
		int countOfGap = 0;

		for (int i = 0; i < numbers.size() && numbers[i] == 0; ++i)
			++countOfZero;

		for (int i = countOfZero; i < numbers.size() - 1; ++i)
		{
			if (numbers[i] == numbers[i + 1])
				return false;
			countOfGap += numbers[i + 1] - numbers[i] - 1;
		}

		return countOfZero >= countOfGap;
	}
};

int main()
{
	return 0;
}