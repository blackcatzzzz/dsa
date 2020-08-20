/*
43. Multiply Strings
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
        int m = num1.size();
        int n = num2.size();
        vector<int> res(m + n, 0);
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int p1 = i + j, p2 = i + j + 1;
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = res[p2] + mul;
                res[p2] = sum % 10;
                res[p1] += sum / 10; 
            }
        }

        int i = 0;
        while(i < res.size() && res[i] == 0)
            i++;
        
        string ans;
        for(; i < res.size(); i++)
            ans.push_back(res[i] + '0');

        return ans.size() == 0 ? "0" : ans;
    }
};

int main(){
    Solution S;
    string num1 = "123", num2 = "456";
    cout << S.multiply(num1, num2);
}
