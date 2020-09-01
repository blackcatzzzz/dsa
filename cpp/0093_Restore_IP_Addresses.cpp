/*
93. Restore IP Addresses
Given a string s containing only digits. Return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single points and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "1111"
Output: ["1.1.1.1"]
Example 4:

Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]
Example 5:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

Constraints:

0 <= s.length <= 3000
s consists of digits only.
*/

#include "common.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0);
        return res;
    }

private:
    void dfs(const string& s, int start){
        if(path.size() == 4){
            string ip;
            for(auto s : path)
                ip += s + ".";
            res.push_back(ip.substr(0, ip.size() - 1));
        }

        for(int i = 1; i <= 3; i++){
            if(s.size() - start - i > (3 - path.size()) * 3 || s.size() - start - i < (3 - path.size()))
                continue;

            string str = s.substr(start, i);
            if(!isValid(str))
                continue;
            path.push_back(str);
            dfs(s, start + i);
            path.pop_back();
        }

    }

private:
    bool isValid(const string& s){
        if(s.size() > 1 && s[0] == '0')
            return false;

        int num = 0;
        for(int i = 0; i < s.size(); i++)
            num = num * 10 + (s[i] - '0');
        
        if(num < 0 || num > 255)
            return false;

        return true;
    }

private:
    vector<string> res;
    vector<string> path;
};


int main(){
    Solution S;
    string s = "25525511135";
    printVector(S.restoreIpAddresses(s));
}