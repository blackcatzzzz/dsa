/*
258. Add Digits
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

#include "common.h"

class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){
            int next = 0;
            while(num){
                next += num % 10;
                num = num / 10;
            }

            num = next;
        }

        return num;
    }
};


int main(){
    Solution S;
    cout << S.addDigits(38);
}