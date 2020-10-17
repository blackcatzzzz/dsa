/*
20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include "common.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                left.push(c);
            }else{
                if(!left.empty() && leftOf(c) == left.top())
                    left.pop();
                else
                    return false;
            }
        }

        return left.empty();
    }
private:
    char leftOf(char c){
        if(c == ')') return '(';
        if(c == ']') return '[';
        // if(c == '}') return '{';
        return '{';
    }
};

int main(){
    string s = "()[]{}";
    Solution S;
    cout << S.isValid(s) << endl;
}