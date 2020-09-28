/*
231. Power of Two
Given an integer n, write a function to determine if it is a power of two.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
Example 4:

Input: n = 4
Output: true
Example 5:

Input: n = 5
Output: false
 

Constraints:

-231 <= n <= 231 - 1
*/

#include "common.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;    

        return (n & -n) == n;
    }
};

class Solution1 {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;    

        return (n & (n - 1)) == 0;
    }
};

// time out
class Solution_BF {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        while(n % 2 == 0)
            n = n / 2;        

        return n == 1;
    }
};

int main(){
    Solution S;
    cout << S.isPowerOfTwo(-2147483648);
}