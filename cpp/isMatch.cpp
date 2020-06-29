// Source : https://leetcode.com/problems/regular-expression-matching/

/*
10. Regular Expression Matching

Hard

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/


#include "common.h"

// DP 
class Solution {
public:
    bool isMatch(string s, string p) {
        /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        
        f[0][0] = true;
        for (int i = 1; i <= m; i++)
            f[i][0] = false;
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
        
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
        
        return f[m][n];
    }
};

// 备忘录
class Solution_MEMO {
public:
    bool isMatch(string s, string p) {
        return dp(s, p, 0, 0);
    }

private:
    bool dp(const string& s, const string& p, int i, int j){
        if(memo.count(pair<int, int>(i, j))) return memo[pair<int, int>(i, j)];

        if(j == p.size()) return i == s.size();

        bool first = i < s.size() && (p[j] == '.' || p[j] == s[i]);
        if(j <= p.size() - 2 && p[j + 1] == '*'){
            return dp(s, p, i, j + 2) || first && dp(s, p, i + 1, j);
        }else{
            return first && dp(s, p, i + 1, j + 1);
        }
    }

private:
    // unordered_map<pair<int, int>, bool> memo; // need hash
    map<pair<int, int>, bool> memo;
};

// 暴力
class Solution_F {
public:
    bool isMatch(string s, string p) {
        return isMatch_Re(s, p);
    }

private:
    bool isMatch_Re(const string&s, const string& p){
        if(p.empty()) return s.empty();

        bool first = !s.empty() && (p[0] == '.' || p[0] == s[0]);
        if(p.size() >= 2 && p[1] == '*'){
            return isMatch_Re(s, p.substr(2)) || first && isMatch_Re(s.substr(1), p);
        }else{
            return first && isMatch_Re(s.substr(1), p.substr(1));
        }
    }
};

void test_SF(){
    cout << "**********test SF********" << endl;
    string s = "mississippi";
    string p = "mis*is*p*.";
    Solution_F SF;
    cout << SF.isMatch(s,p) << endl;

    s = "aab";
    p = "c*a*b";
    cout << SF.isMatch(s,p) << endl;

    s = "aa";
    p = "a*";
    cout << SF.isMatch(s,p) << endl;
}

void test_MEMO(){
    cout << "**********test MEMO********" << endl;
    Solution_MEMO S;
    string s = "mississippi";
    string p = "mis*is*p*.";
    // cout << S.isMatch(s,p) << endl;

    s = "ab";
    p = ".*";
    cout << S.isMatch(s,p) << endl;
    
    

    s = "aab";
    p = "c*a*b";
    cout << S.isMatch(s,p) << endl;

    s = "aa";
    p = "a*";
    cout << S.isMatch(s,p) << endl;
}


int main(){
    test_MEMO();
}