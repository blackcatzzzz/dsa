/*
5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/


#include "common.h"

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0; i < s.size(); i++){
            string s1 = helper(s, i, i);
            string s2 = helper(s, i, i + 1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }

        return res;
    }

private:
    string helper(const string& s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--; r++;
        }

        return s.substr(l + 1, r - l - 1);
    }
};

int main(){
    string s = "a";
    try
    {
         cout << s.substr(0,2) << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Solution S;
    cout << S.longestPalindrome(s) << endl;
}