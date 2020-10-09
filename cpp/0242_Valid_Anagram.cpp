/*
242. Valid Anagram
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

#include "common.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> counter(26, 0);
        for(int i = 0; i < s.size(); i++){
            counter[s[i] - 'a']++;
            counter[t[i] - 'a']--;
        }

        for(auto& c : counter)
            if(c != 0)
                return false;

        return true;
    }
};

int main(){

}