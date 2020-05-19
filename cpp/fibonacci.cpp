class Solution {
public:
	// f(0) = 0, f(1) = 1, f(2) = 1, ...
	int Fibonacci(int n) {
		int f = 1, g = 0; // f(-1) = 1, f(0) = 0

		while (n-- > 0)
		{
			g = f + g;
			f = g - f;
		}

		return g;
	}
};

int main()
{
	return 0;
}