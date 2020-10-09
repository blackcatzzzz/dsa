/*
241. Different Ways to Add Parentheses
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

#include "common.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return helper(input, 0, input.size() - 1);
    }

private:
    vector<int> helper(const string& input, int start, int end){
        if(isAllNum(input, start, end))
            return vector<int>{stoi(input.substr(start, end - start + 1))};
        
        if(memo.find(make_pair(start, end)) != memo.end())
            return memo[make_pair(start, end)];
        vector<int> ans;
        for(int i = start; i <= end; i++){
            char c = input[i];
            if(c == '+' || c == '-' || c == '*'){
                vector<int> left = helper(input, start, i - 1);
                vector<int> right = helper(input, i + 1, end);
                for(auto& l : left){
                    for(auto& r: right){
                        if(c == '+')
                            ans.push_back(l + r);
                        else if(c == '-')
                            ans.push_back(l - r);
                        else
                            ans.push_back(l * r);
                    }
                }
            }
        }

        memo[make_pair(start, end)] = ans;
        
        return ans;
    }

    bool isAllNum(const string& str, int start, int end){
        for(int i = start; i <= end; i++)
            if(!isdigit(str[i]))
                return false;
        return true;
    }

private:
    map<pair<int, int>, vector<int>> memo;
};


int main(){
    Solution S;
    string input = "2*3-4*5";
    printVector(S.diffWaysToCompute(input));
}