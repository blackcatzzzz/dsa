// Source : https://leetcode.com/problems/minimum-window-substring/

/*
76. Minimum Window Substring

Hard

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/


#include "common.h"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;

        int left = 0, right = 0;    // [left, right)
        int valid = 0;
        int start = 0, len = INT_MAX;
        while(right < s.size()){
            // c 是将移入窗口的字符
            char c = s[right];
            // 右移窗口
            right++;
            // 进行窗口内数据的一系列更新
            if(need.count(c)){
                window[c]++;
                if(need[c] == window[c])
                    valid++;
            }

            // 判断左侧窗口是否要收缩
            while(valid == need.size()){
                // 在这里更新最小覆盖子串
                if(right - left < len){
                    len = right - left;
                    start = left;
                }

                // d 是将移出窗口的字符
                char d = s[left];
                // 左移窗口
                left++;
                // 进行窗口内数据的一系列更新
                if(need.count(d)){
                    if(need[d] == window[d])
                        valid--;
                    window[d]--;
                }
            }
        }

        return len == INT_MAX ? "": s.substr(start, len);
    }
};

int main(){
    Solution s;
    string S = "ADOBECODEBANC";
    string T = "ABC";
    cout << s.minWindow(S, T) << endl;
}