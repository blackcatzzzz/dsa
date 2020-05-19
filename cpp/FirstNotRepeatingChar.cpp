#include <string>

using namespace std;

/*
* 在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
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