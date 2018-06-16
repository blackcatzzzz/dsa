#include <stack>
#include <vector>

using namespace std;


/*
* ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
* ����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1
* �Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
* ��ע�⣺���������еĳ�������ȵģ�
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