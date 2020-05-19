#include <stack>
#include <vector>

using namespace std;


/*
* 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
* 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1
* 是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
* （注意：这两个序列的长度是相等的）
*/

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0 || popV.size() == 0)
			return false;
		int pushLen = pushV.size();
		int popLen = popV.size();
		int i = 0, j = 0;

		stack<int> sta;

		while (i < pushLen)
		{
			while (i < pushLen && (sta.empty() || sta.top() != popV[j]))
				sta.push(pushV[i++]);

			while (sta.top() == popV[j] && j < popLen)
			{
				sta.pop();
				j++;
			}
		}

		if (sta.empty() && j == popLen)
			return true;
		else
			return false;

	}
};

// 2018.6.16
class Solution1 {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size())
			return false;

		int i = 0, j = 0;
		stack<int> sta;
		while (i < pushV.size() && j < popV.size())
		{
			while (i < pushV.size() && (sta.empty() || sta.top() != popV[j]))
				sta.push(pushV[i++]);

			while (j < popV.size() && sta.top() == popV[j])
			{
				sta.pop();
				++j;
			}
		}

		return sta.empty() ? true : false;
	}
};

int main()
{
	getchar();
	return 0;
}