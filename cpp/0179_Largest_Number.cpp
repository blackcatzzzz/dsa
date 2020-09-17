/*
179. Largest Number
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/

#include "common.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> asStrs(nums.size());
        for(int i = 0; i < nums.size(); i++)
            asStrs[i] = to_string(nums[i]);
        
        auto cmp = [](const string& a, const string& b){
            string order1 = a + b;
            string order2 = b + a;
            return order1 > order2;
        };

        sort(asStrs.begin(), asStrs.end(), cmp);
        if(asStrs[0] == "0")
            return "0";

        string ans;
        for(auto& str : asStrs)
            ans += str;

        return ans;
    }
};

int main(){
    Solution S;
    vector<int> nums = {0};
    cout << S.largestNumber(nums);
}