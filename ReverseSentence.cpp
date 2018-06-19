#include <string>

using namespace std;


/*
* ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
* ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
* ���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ�
* ��ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
*/

class Solution {
public:
	string ReverseSentence(string str) {
		if (str.size() == 0)
			return str;
		int begin = 0, end = str.size() - 1;
		reverse(str, 0, end);

		begin = end = 0;
		while (begin < str.size())
		{
			while (str[begin] == ' ')
			{
				begin++;
				end++;
			}

			//if (str[end] == ' ' || str[end] == '\0')
			if (str[end] == ' ' || end == str.size())
			{
				reverse(str, begin, end - 1);
				begin = end;
			}
			else
				++end;
		}

		return str;
	}

private:
	void reverse(string& str, int begin, int end)
	{
		for (; begin < end; ++begin, --end)
		{
			swap(str[begin], str[end]);
		}
	}
};

int main()
{
	return 0;
}