/*
168. Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
*/

#include "common.h"

class Solution {
public:
    string convertToTitle(int n) {
        stack<string> stk;
        while(n){
            n--;
            stk.push(string(1, n % 26 + 'A'));
            n = n / 26;
        }
        string ans;
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

int main(){
    Solution S;
    cout << S.convertToTitle(28);
}