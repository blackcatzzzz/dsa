#include <string>

using namespace std;

/*
* ��Ŀ����
* ��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
*
* ��������:
* ����һ���ַ���,����������ĸ����,����Ϊ��
*
* �������:
* ����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
*/

class Solution {
public:
	int StrToInt(string str) {
		if (str.size() == 0)
			return 0;

		int cur = 0;
		bool isNegative = false;

		if (str[cur] == '+')
		{
			if (str.size() < 2)
				return 0;
			cur++;
		}

		else if (str[cur] == '-')
		{
			if (str.size() < 2)
				return 0;
			isNegative = true;
			cur++;
		}

		int number = 0;
		while (cur < str.size())
		{
			if (str[cur] < '0' || str[cur] > '9')
				return 0;

			number = number * 10 + (str[cur] - '0');
			cur++;
		}

		if (isNegative)
			number = -number;

		return number;
	}
};

int main()
{
	return 0;
}