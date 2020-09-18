/*
187. Repeated DNA Sequences
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/

#include "common.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_set<string> counts;
        unordered_set<string> repeatStr;
        for(int i = 0; i < n - 9; i++){
            string str = s.substr(i, 10);
            if(counts.count(str))
                repeatStr.insert(str);
            else
                counts.insert(str);
        }

        return vector<string>(repeatStr.begin(), repeatStr.end());
    }
};

int main(){
    Solution S;
    printVector(S.findRepeatedDnaSequences(""));
}