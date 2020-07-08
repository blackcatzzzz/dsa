// Source: https://leetcode.com/problems/find-all-anagrams-in-a-string/

/*
438. Find All Anagrams in a String

Medium

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

#include "common.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for(char c : p) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        vector<int> res;

        while(right < s.size()){
            char c = s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(need[c] == window[c])
                    valid++;
            }

            while(right - left >= p.size()){
                if(valid == need.size())
                    res.push_back(left);

                char d = s[left];
                left++;
                if(need.count(d)){
                    if(need[d] == window[d])
                        valid--;
                    window[d]--;
                }
            }
        }

        return res;
    }
};

int main(){
    Solution S;
    string s = "cbaebabacd", p ="abc";
    S.findAnagrams(s, p);

    s = "abab", p ="ab";
    S.findAnagrams(s, p);
}