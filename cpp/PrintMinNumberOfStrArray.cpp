#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		if (numbers.size() == 0)
			return "";

		vector<string> vecStr(numbers.size());
		for (unsigned int i = 0; i < numbers.size(); ++i)
		{
			stringstream ss;
			string str;
			ss << numbers[i];
			ss >> str;
			vecStr.push_back(str);
		}

		sort(vecStr.begin(), vecStr.end(), compare);

		string s;
		for (auto it = vecStr.begin(); it != vecStr.end(); ++it)
			s.append(*it);

		return s;
	}

private:
	// true ‘Ú≤ªΩªªª
	static bool compare(string s1, string s2)
	{
		return s1.append(s2).compare(s2.append(s1)) <= 0;
	}
};