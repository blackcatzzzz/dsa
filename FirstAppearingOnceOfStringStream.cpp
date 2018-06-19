#include <string>
#include <sstream>

using namespace std;

/*
* ��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
* ���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
* ���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
*/

class Solution
{
public:
	Solution() :index(0)
	{
		memset(occurrence, -1, 256 * (sizeof(int)));
	}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (occurrence[ch] == -1)
			occurrence[ch] = index;
		else if (occurrence[ch] >= 0)
			occurrence[ch] = -2;

		++index;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		char ch = '#';
		int minIndex = INT_MAX;
		for (int i = 0; i < 256; ++i)
		{
			if (occurrence[i] >= 0 && occurrence[i] < minIndex)
			{
				ch = (char)i;
				minIndex = occurrence[i];
			}
		}

		return ch;
	}
private:
	int index;
	int occurrence[256];
};