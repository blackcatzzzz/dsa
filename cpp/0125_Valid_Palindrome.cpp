/*
125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
*/

#include "common.h"

class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        while(lo <= hi){
            while(lo < hi && !isalnum(s[lo]))
                lo++;

            while(lo < hi && !isalnum(s[hi]))
                hi--;

            if(tolower(s[lo]) != tolower(s[hi]))
                return false;

            lo++;
            hi--;
        }

        return true;
    }
};

int main(){
    Solution S;
    string s = "A man, a plan, a canal: Panama";
    cout << S.isPalindrome(s) << endl;
}