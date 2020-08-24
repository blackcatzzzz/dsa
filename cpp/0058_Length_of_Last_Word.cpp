/*
58. Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/

#include "common.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int count = 0;
        for(char c : s){
            if(c != ' ')
                count++;
            else{
                res = count > 0 ? count : res;
                count = 0;
            }
        }

        if(count)
            res = count;

        return res;
    }
};

int main(){
    Solution S;
    string s = "b   a    ";
    cout << S.lengthOfLastWord(s);
}