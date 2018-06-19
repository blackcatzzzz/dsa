#include <string>

using namespace std;

/*
* 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
* 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
* 要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (str.size() == 0 || n <= 0)
			return str;
		n = n % str.size();
		return solution_reverse(str, n);
	}

private:
	string solution_strFeature(string &str, int n)
	{
		return str.substr(n, str.size() - n).append(str.substr(0, n));
	}

	string solution_reverse(string &str, int n)
	{
		if (n == 0)
			return str;
		int firstBegin = 0;
		int firstEnd = n - 1;
		int secondBegin = n;
		int secondEnd = str.size() - 1;

		reverse(str, firstBegin, firstEnd);
		reverse(str, secondBegin, secondEnd);
		reverse(str, 0, str.size() - 1);

		return str;
	}

	void reverse(string &str, int begin, int end)
	{
		for (; begin < end; ++begin, --end)
		{
			swap(str[begin], str[end]);
		}
	}
};

class Solution1 {
public:
	string LeftRotateString(string str, int n) {
		if (str.size() == 0 || n <= 0)
			return str;
		n = n % str.size();
		return solution_reverse(str, n);
	}

private:
	string solution_strFeature(string &str, int n)
	{
		return str.substr(n, str.size() - n).append(str.substr(0, n));
	}

	string solution_reverse(string &str, int n)
	{
		if (n == 0)
			return str;
		reverse(str, 0, str.size() - 1);
		reverse(str, 0, str.size() - n - 1);
		reverse(str, str.size() - n, str.size() - 1);

		return str;
	}

	void reverse(string &str, int begin, int end)
	{
		for (int i = begin, j = end; i < j; ++i, --j)
			swap(str[i], str[j]);
	}
};

int main()
{
	string s = "abcdefg";
	Solution1 solution1;
	solution1.LeftRotateString(s, 2);
	return 0;
}