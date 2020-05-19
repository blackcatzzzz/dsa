#include <stack>
#include <iostream>

using namespace std;

template <typename T>
void printStack(T & s)
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

bool parenMatch(const char exp[], int n)
{
	stack<char> s;
	for (size_t i = 0; i < n; i++)
	{
		switch (exp[i])
		{
		case '(':
		case '[':
		case '{':
			s.push(exp[i]);
			break;
		case ')':
			if (s.empty() || '(' != s.top())
			{
				return false;
			}
			s.pop();
			break;
		case ']':
			if (s.empty() || '[' != s.top())
			{
				return false;
			}
			s.pop();
			break;
		case '}':
			if (s.empty() || '{' != s.top())
			{
				return false;
			}
			s.pop();
			break;
		default:
			break;
		}
	}

	return s.empty();
}

int main()
{
	char validExp[] = "{()()[]}";
	char invalidExp[] = "{()()[}";
	//char invalidExp[] = "{()()]}";

	cout << parenMatch(validExp, strlen(validExp)) << endl;
	cout << parenMatch(invalidExp, strlen(invalidExp)) << endl;
	getchar();
	return 0;
}

