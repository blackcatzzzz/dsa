#include <stack>

using namespace std;

/*
* ����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
*/

class Solution {
public:
	void push(int value) {
		if (staMin.empty() || staMin.top() >= value)
			staMin.push(value);
		else
			staMin.push(staMin.top());

		staData.push(value);
	}
	void pop() {
		staMin.pop();
		staData.pop();
	}
	int top() {
		return staData.top();
	}
	int min() {
		return staMin.top();
	}
private:
	stack<int> staData;
	stack<int> staMin;
};

int main()
{
	getchar();
	return 0;
}