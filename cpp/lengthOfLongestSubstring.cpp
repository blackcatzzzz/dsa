// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
3. Longest Substring Without Repeating Characters

Medium

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include "common.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int res = 0;

        while(right < s.size()){
            char c = s[right];
            right++;
            window[c]++;

            while(window[c] > 1){
                char d = s[left];
                left++;
                window[d]--;
            }

            res = max(res, right - left);
        }

        return res;
    }
};

int main(){
    Solution S;
    string s = "abcabcbb";
    cout << S.lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << S.lengthOfLongestSubstring(s) << endl;
    
    s = "pwwkew";
    cout << S.lengthOfLongestSubstring(s) << endl;
}