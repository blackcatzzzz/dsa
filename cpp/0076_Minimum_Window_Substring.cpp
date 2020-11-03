/*
76. Minimum Window Substring
Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"
 

Constraints:

1 <= s.length, t.length <= 105
s and t consist of English letters.
 

Follow up: Could you find an algorithm that runs in O(n) time?
*/

#include "common.h"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window;
        unordered_map<char, int> dst;
        int valid = 0;
        for(auto& c: t){
            window[c] = 0;
            dst[c]++;
        }
            
        
        int ans_l = 0, len = 0;
        for(int i = 0, j = 0; j < s.size();j++){
            char c = s[j];
            if(window.count(c)){
                window[c]++;
                if(window[c] == dst[c])
                    valid++;
            }

            while(valid == dst.size()){
                if(j - i + 1 < len || len == 0){
                    len = j - i + 1;
                    ans_l = i;
                } 
                char c = s[i++];
                if(window.count(c)){
                    window[c]--;
                    if(window[c] < dst[c])
                        valid--;
                }
            }
        }

        return s.substr(ans_l, len);
    }
};

int main(){
    Solution S;
    string s = "a", t = "aa";
    cout << S.minWindow(s, t);
}