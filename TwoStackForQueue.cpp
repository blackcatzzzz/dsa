#include <stack>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution
{
public:
	void push(int node)
	{
		stack1.push(node);
	}

	int pop()
	{
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}

		/*if (stack2.empty())
			return -1;*/

		assert(!stack2.empty());

		int node = stack2.top();
		stack2.pop();

		return node;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Solution s;

	s.push(1);
	s.push(2);

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	s.push(3);
	s.push(4);
	cout << s.pop() << endl;

	s.push(5);
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	getchar();
	return 0;
}