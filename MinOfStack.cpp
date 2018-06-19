#include <stack>

using namespace std;

/*
* 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
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