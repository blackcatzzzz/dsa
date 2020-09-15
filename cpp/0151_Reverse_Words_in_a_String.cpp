/*
151. Reverse Words in a String
Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.
*/

#include "common.h"

// O(1)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int len = s.size();
        int idx = 0;
        int start = 0, end = 0;
        while(start < len){
            if(s[start] == ' '){
                start++;
                continue;
            }

            // add space to separate
            if(idx != 0) s[idx++] = ' ';

            end = start;
            while(end < len && s[end] != ' ')
                s[idx++] = s[end++];
            
            reverse(s.begin() + idx - (end - start), s.begin() + idx);

            start = end;
        }

        s.erase(s.begin() + idx, s.end());
        return s;
    }

};

// O(N)
class Solution_O_N {
public:
    string reverseWords(string s) {
        int start = 0, end = 0;
        int len = s.size();
        stack<string> stack;
        while(start < len){
            if(s[start] == ' '){
                start++;
                continue;
            }
                
            end = start;
            while((end + 1) < len && s[end + 1] != ' ')
                end++;
            stack.push(s.substr(start, end - start + 1));
            start = end + 1;
        }

        string res;
        while(!stack.empty()){
            res += stack.top() + " ";
            stack.pop();
        }
            
        return res.substr(0, res.size() - 1);
    }
};

int main(){
    Solution S;
    string s = "a good   example";
    cout << S.reverseWords(s);
}