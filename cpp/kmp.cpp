
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

// 二维DP
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

// 暴力
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


// leetcode 二维dp solution
class Solution_DP {
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

// leetcode 一维next solution
// https://www.zhihu.com/question/21923021/answer/1032665486
class Solution {
public:
    int strStr(string haystack, string needle) {
        int M = needle.size();
        if(M == 0) return 0;

        // 构建next, next[i] 表示 模式串p中 p[0...i] 子串的前缀与后缀的最大匹配长度
        vector<int> next(M, 0); 
        buildNext(needle, next);

        return search(haystack, needle, next);       
    }

    int search(const string& s, const string& p, vector<int>& next){
        int N = s.size();
        int M = p.size();
        int i = 0; // i 表示主串s待匹配的位置
        int j = 0; // j 表示模式串p待匹配的位置
        // while(i < N){
        //     if(s[i] == p[j]){
        //         i++;
        //         j++;
        //     }else if(j > 0 && next[j - 1]){     // 失配了，根据next移动模式串（即前缀与后缀的最大匹配长度）
        //         j = next[j - 1];
        //     }else if(j > 0){                   // 失配且next[j-1] == 0， 直接移动模式串到p[0]
        //         j = 0;
        //     }else{
        //         i++;                            // 在p[0]处失配，直接移动主串
        //     }

        //     if(j == M) return i - M;    // 匹配成功
        // }

        // 合并上面注释的逻辑，主要是j > 0 && next[j - 1]这里
        while(i < N){
            if(s[i] == p[j]){
                i++;
                j++;
            }else if(j){                    // 失配了，根据next移动模式串（即前缀与后缀的最大匹配长度）
                j = next[j - 1];
            }else{                          // 在p[0]处失配，直接移动主串
                i++;                            
            }

            if(j == M) return i - M;    // 匹配成功
        }

        return -1;
    }

    // 发现buildNext与search代码很类似，其实 buildNext相当于 模式串自己与自己的前缀进行匹配， 即x相当于i, now相当于j 
    void buildNext(const string& p, vector<int>& next){
        int M = p.size();
        // base case
        next[0] = 0;

        int now = 0, x = 1; // now为当前从1开始算,可以理解now = next[x-1], 扩展时next[x] = next[x-1] + 1
        while(x < M){
            if(p[x] == p[now]){  // 如果p[x] == p[now],向右扩展一回
                now += 1;
                next[x] = now;
                x += 1;
            }else if(now){      // 缩小now, 回退，重启状态
                now = next[now - 1];
            }else{              // now缩小为0, 无法回退
                next[x] = 0;
                x += 1;
            }
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

void test_S(){
    cout << "test S " << endl;
    string pat = "ababc";
    string text = "abaababc";

    Solution S;
    cout << S.strStr(text, pat) << endl;    
}

int main(){
    string pat = "ababc";
    KMP kmp(pat);

    string text = "abaababc";
    cout << kmp.search(text) << endl;

    test_SF();

    // Solution_DP S;
    // cout << S.strStr(text, pat) << endl;

    test_S();
}