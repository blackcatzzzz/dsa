package com.zhangchi.dsa;

/**
 * 最长公共子序列
 * @date 2018.6.24
 * @author chi zhang
 * https://blog.csdn.net/yysdsyl/article/details/4226630/
 * https://blog.csdn.net/ljyljyok/article/details/77905681
 */
public class LongestCommonSubsequence {

    private final int upleft = 0;
    private final int up = 1;
    private final int left = -1;

    public int longestCommonSubsequence(String s1, String s2){
        int m = s1.length();
        int n = s2.length();
        if(m == 0 || n == 0)
            return 0;

        int[][] chess = new int[m + 1][n + 1];

        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(s1.charAt(i - 1) == s2.charAt(j - 1)){
                    chess[i][j] = chess[i - 1][j - 1] + 1;
                }
                else if(chess[i - 1][j] >= chess[i][j - 1])
                    chess[i][j] = chess[i - 1][j];
                else
                    chess[i][j] = chess[i][j - 1];
            }
        }

        return chess[m][n];
    }

    public int lcs1(String s1, String s2, int[][] c, int[][] b){
        int m = s1.length();
        int n = s2.length();
        if(m == 0 || n == 0)
            return 0;

        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(s1.charAt(i - 1) == s2.charAt(j - 1)){
                    c[i][j] = c[i - 1][j - 1] + 1;
                    b[i][j] = upleft;
                }
                else if(c[i - 1][j] >= c[i][j - 1]){
                    c[i][j] = c[i - 1][j];
                    b[i][j] = up;
                }
                else{
                    c[i][j] = c[i][j - 1];
                    b[i][j] = left;
                }

            }
        }

        return c[m][n];
    }

    public void printLCS(String s1, int[][] b , int i, int j){
        if(i == 0 || j == 0)
            return;

        if(b[i][j] == upleft){
            printLCS(s1, b, i - 1, j - 1);
            System.out.print(s1.charAt(i - 1));
        }else if(b[i][j] == up){
            printLCS(s1, b, i - 1, j);
        }else{
            printLCS(s1, b, i, j - 1);
        }

    }

    public static void main(String[] args) {
        String s1 = "ABCBDAB";
        String s2 = "BDCABA";

        LongestCommonSubsequence lcs = new LongestCommonSubsequence();
        System.out.println(lcs.longestCommonSubsequence(s1, s2));

        int m = s1.length();
        int n = s2.length();
        int[][] c = new int[m + 1][n + 1];
        int[][] b = new int[m + 1][n + 1];
        lcs.lcs1(s1, s2, c, b);
        lcs.printLCS(s1, b, m, n);
    }
}
