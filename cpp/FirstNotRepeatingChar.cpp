#include <string>

using namespace std;

/*
* ��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
*/

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.size() == 0)
			return -1;
		unsigned int hashTable[256];
		memset(hashTable, 0x00, 256 * sizeof(unsigned int));
		for (unsigned int i = 0; i < str.size(); ++i)
			hashTable[str[i]]++;

		for (unsigned int i = 0; i < str.size(); ++i)
		{
			if (hashTable[str[i]] == 1)
				return i;
		}

		return -1;
	}
};

// 2018.6.18
class Solution1 {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.size() == 0)
			return -1;

		int hashTable[256];
		memset(hashTable, 0, sizeof(hashTable));
		for (int i = 0; i < str.size(); ++i)
			hashTable[str[i]]++;

		for (int i = 0; i < str.size(); ++i)
			if (hashTable[str[i]] == 1)
				return i;

		return -1;
	}
};

int main()
{
	return 0;
}