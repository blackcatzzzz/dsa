/*
67. Add Binary
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

#include "common.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();
        int len = len_a > len_b ?  len_a : len_b;
        string res;
        int i = 1;
        int carry = 0;
        while(i <= len_a || i <= len_b){
            char a_c = i <= len_a ? a[len_a - i] : '0';
            char b_c = i <= len_b ? b[len_b - i] : '0';
            int sum = (a_c - '0') + (b_c - '0') + carry;
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
            i++;
        }

        if(carry)
            res.push_back('1');

        reverse(res.begin(), res.end());

        return res;
    }
};

int main(){
    Solution S;
    string a = "1010", b = "1011";
    cout << S.addBinary(a, b);
}