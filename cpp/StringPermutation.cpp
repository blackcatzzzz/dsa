#include <vector>
#include <algorithm>

using namespace std;

/*
* ����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
* ���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
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