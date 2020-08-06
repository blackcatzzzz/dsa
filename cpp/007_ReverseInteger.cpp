/*
7. Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include "common.h"

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            int pop = x % 10;
            x = x / 10;
            if(res > INT_MAX / 10 || res < INT_MIN / 10)
                return 0;
            res = res * 10 + pop;
        }

        return res;
    }
};


int main(){
    int x = -101;
    while(x != 0){
        int pop = x % 10;
        x = x / 10;
        cout << pop << endl;
    }
}