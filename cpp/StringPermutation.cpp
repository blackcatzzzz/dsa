#include <vector>
#include <algorithm>

using namespace std;

/*
* 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
* 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> vecRes;
		permutation(str, 0, vecRes);
		sort(vecRes.begin(), vecRes.end());
		return vecRes;
	}

private:
	void permutation(string &str, int begin, vector<string> & vecRes)
	{
		if (str.size() == 0)
			return;

		if (begin == str.size())
		{
			if (find(vecRes.begin(), vecRes.end(), str) == vecRes.end())
				vecRes.push_back(str);
		}
		else
		{
			for (int i = begin; i < str.size(); ++i)
			{
				swap(str[begin], str[i]);
				permutation(str, begin + 1, vecRes);
				swap(str[begin], str[i]);
			}
		}

		return;
	}
};

int main()
{
	string str = "abc";
	Solution s;
	auto v = s.Permutation(str);
	getchar();
	return 0;
}