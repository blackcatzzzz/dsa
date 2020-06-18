// Source : https://leetcode.com/problems/multiply-strings/

/*
43. Multiply Strings

Medium

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

#include "common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        // 结果有m+n位
        vector<int> res(m + n, 0);
        // 从个位开始乘
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                // 乘积在 res 对应的索引位置
                int p1 = i + j, p2 = i + j + 1;
                // 叠加到 res 上
                int sum = res[p2] + mul;
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }
        
        // 结果前缀可能存的 0（未使用的位）
        int i = 0;
        while(i < res.size() && res[i] == 0)
            i++;
        
        // 将计算结果转化成字符串
        string str;
        for(;i < res.size(); i++)
            str.push_back('0' + res[i]);

        return str.size() == 0 ? "0" : str;
    }
};

int main(){
    string num1 = "123", num2 = "456";
    Solution S;
    cout << S.multiply(num1, num2) << endl;
}