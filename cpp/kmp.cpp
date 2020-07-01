
/*
28. Implement strStr()

Easy

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/


#include "common.h"

class KMP {
public:
    KMP(const string& pat): dp(pat.size(), vector<int>(256, 0)){
        this->pat = pat;
        int M = pat.size();
        //base case
        dp[0][pat[0]] = 1;

        int X = 0;  // 影子状态初始化为0， 跟着j走过相同的路径
        for(int j = 1; j < M; j++){
            for(int c = 0; c < 256; c++){
                if(pat[j] == c)
                    dp[j][c] = j + 1;
                else
                    dp[j][c] = dp[X][c];
            }
            // 更新影子状态
            X = dp[X][pat[j]];
        }
    }

    int search(const string& text){
        int M = this->pat.size();
        int N = text.size();

        int j = 0;
        for(int i = 0; i < N; i++){
            // 当前是状态 j，遇到字符 txt[i]，
            // pat 应该转移到哪个状态？
            j = dp[j][text[i]];

            // 如果达到终止态，返回匹配开头的索引
            if(j == M) return i - M + 1;
        }

        return -1;
    }

private:
    string pat;
    vector<vector<int>> dp;
};

class Solution_F{
public:
    int search(const string& text, const string& pat){
        int M = pat.size();
        int N = text.size();
        for(int i = 0; i <= N - M; i++){
            int j = 0;
            for(; j < M; j++){
                if(text[i+j] != pat[j])
                    break;
            }
            if(j == M) return i;
        }
        return -1;
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        int M = needle.size();
        int N = haystack.size();

        if(M == 0) return 0;

        // 构建dp数组
        vector<vector<int>> dp(M, vector<int>(256, 0));
        buildNext(needle, dp);

        int j = 0;
        for(int i = 0; i < N; i++){
            // 当前是状态 j，遇到字符 txt[i]，
            // pat 应该转移到哪个状态？
            j = dp[j][haystack[i]];

            // 如果达到终止态，返回匹配开头的索引
            if(j == M) return i - M + 1;
        }

        return -1;       
    }

    void buildNext(const string& pat, vector<vector<int>>& dp){
        int M = pat.size();
        //base case
        dp[0][pat[0]] = 1;

        int X = 0;  // 影子状态初始化为0， 跟着j走过相同的路径
        for(int j = 1; j < M; j++){
            for(int c = 0; c < 256; c++){
                if(pat[j] == c)
                    dp[j][c] = j + 1;
                else
                    dp[j][c] = dp[X][c];
            }
            // 更新影子状态
            X = dp[X][pat[j]];
        }
    }

};

void test_SF(){
    cout << "test SF " << endl;
    string pat = "ababc";
    string text = "abaababc";


    Solution_F SF;
    cout << SF.search(text, pat) << endl;
}

int main(){
    string pat = "ababc";
    KMP kmp(pat);

    string text = "abaababc";
    cout << kmp.search(text) << endl;

    test_SF();

    Solution S;
    cout << S.strStr(text, pat) << endl;
}