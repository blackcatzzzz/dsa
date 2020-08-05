
/*
3. Longest Substring Without Repeating Characters
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

// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> window;
        int ans = 0;
        while(right < s.size()){
            char c = s[right];
            // right++;
            window[c]++;

            while(window[c] > 1){
                char d = s[left];
                left++;
                window[d]--;
            }

            ans = max(ans, right - left + 1);

            // 右移窗口
            right++;
        }

        return ans;
    }
};

// 暴力
class Solution_BF {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> cset;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(cset.count(s[j])){
                    cset.clear();
                    break;
                }
                cset.insert(s[j]);
                ans = max(ans, int(cset.size()));
            }
        }

        return ans;
    }
};

int main(){
    string s = "pwwkew";
    Solution S;
    cout << S.lengthOfLongestSubstring(s) << endl;
}