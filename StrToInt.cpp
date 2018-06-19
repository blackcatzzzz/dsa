#include <string>

using namespace std;

/*
* 题目描述
* 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
*
* 输入描述:
* 输入一个字符串,包括数字字母符号,可以为空
*
* 输出描述:
* 如果是合法的数值表达则返回该数字，否则返回0
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