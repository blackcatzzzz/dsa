
/*
8. String to Integer (atoi)
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/

#include "common.h"

// 有限状态自动机
class Solution {

class Automaton {

public:
    // bool isComplete(){
    //     return state == "end";
    // }

    bool get(char c){
        state = table[state][getCol(c)];
        if(state == "in_number"){
            ans = ans * 10 + sign * (c - '0');
            if(ans > INT_MAX){
                ans = INT_MAX;
                return true;
            }

            if(ans < INT_MIN){
                // ans = - long long(INT_MIN);
                ans = INT_MIN;
                return true;
            }

        }else if(state == "signed"){
            sign = c == '-' ? -1 : 1;
        }

        return state != "end";
    }

    int getResult(){
        // return sign * ans;
        return ans;
    }

private:
    int getCol(char c){
        if(c == ' ') return 0;
        if(c == '+' || c == '-') return 1;
        if(c >= '0' && c <= '9') return 2;
        return 3;
    }

private:
    string state = "start";
    int sign = 1;
    long long ans = 0;
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}},
    };
};

public:
    int myAtoi(string str) {
        Automaton automaton;
        for(auto c : str)
            if(!automaton.get(c))
                break;
        return automaton.getResult();
    }
};

int main(){
    string s = "2147483648";
    Solution S;
    cout << S.myAtoi(s) << endl;

    s = "4193 with words";
    cout << S.myAtoi(s) << endl;

    s = "words and 987";
    cout << S.myAtoi(s) << endl;

    s = "-91283472332";
    cout << S.myAtoi(s) << endl;

    s = "-2147483648";
    cout << S.myAtoi(s) << endl;
}