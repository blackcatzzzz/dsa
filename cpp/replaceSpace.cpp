#include <iostream>

using namespace std;


/***
* ��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
* ���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*
*/

// old
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (!str || length <= 0)
			return;

		int originalLength = 0;
		int numberOfBlank = 0;
		int i = 0; // indexOfOriginalStr
		while (str[i] != '\0')
		{
			originalLength++;
			if (str[i] == ' ')
			{
				numberOfBlank++;
			}
			i++;
		}

		int newLength = originalLength + numberOfBlank * 2;
		if (newLength + 1 > length)
			return;

		int j = newLength;
		while (numberOfBlank > 0)
		{
			if (str[i] != ' ')
			{
				str[j--] = str[i--];
			}
			else
			{
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '%';
				i--;
				numberOfBlank--;
			}
		}
	}
};

// 2018.6.14
class Solution1 {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length <= 0)
			return;
		int numberOfBlank = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == ' ')
				++numberOfBlank;
			++i;
		}

		int newLength = i + numberOfBlank * 2; // ������NULL
		//if (newLength > length)
		//	return;

		int j = newLength;
		while (numberOfBlank > 0)
		{
			if (str[i] != ' ')
			{
				str[j--] = str[i--];
			}
			else
			{
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '%';
				i--;
				numberOfBlank--;
			}
		}
	}
};

int main()
{
	Solution1 s1;
	char s[12] = " helloword";
	cout << sizeof(s) << endl;
	s1.replaceSpace(s ,12);

	getchar();
	return 0;
}
