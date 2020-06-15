
// Source: https://leetcode.com/problems/fibonacci-number/

/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

 

Example 1:

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

Note:

0 ≤ N ≤ 30.
*/

#include "common.h"

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

class Solution_Recursion {
public:
    int fib(int N) {
		if(N == 0) return 0;
		if(N == 1) return 1;
        return fib(N - 1) + fib(N - 2);
    }
};

class Solution_DP {
public:
    int fib(int N) {
		vector<int> dp(N + 1, 0);
		//base case
		dp[1] = 1;
		for(int i = 2; i <= N; i++)
			dp[i] = dp[i - 1] + dp[i -2];
		return dp[N];
    }
};

int main()
{
	Solution_DP SDP;
	cout << SDP.fib(5) << endl;
	return 0;
}