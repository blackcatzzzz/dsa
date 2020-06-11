// Source: https://leetcode.com/problems/permutation-in-string/

/*
567. Permutation in String

Medium

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/


#include "common.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for(char c: s1) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        while(right < s2.size()){
            char c = s2[right];
            right++;

            if(need.count(c)){
                window[c]++;
                if(need[c] == window[c])
                    valid++;
            }

            while(right - left >= s1.size()){
                char d = s2[left];
                left++;
                if(valid == need.size())
                    return true;

                if(need.count(d)){
                    if(need[d] == window[d])
                        valid--;
                    window[d]--;
                }
            }
        }

        return false;
    }
};

int main(){
    Solution s;
    string s1 = "ab", s2 = "eidbaooo";
    cout << s.checkInclusion(s1, s2) << endl;

    s1= "ab", s2 = "eidboaoo";
    cout << s.checkInclusion(s1, s2) << endl;
}