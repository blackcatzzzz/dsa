// Source :https://leetcode.com/problems/russian-doll-envelopes/

/*
354. Russian Doll Envelopes

Hard

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/


#include "common.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // 按w升序排序, w相等则按h降序
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? a[1] > b [1] : a[0] < b[0];
        };
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> hights;
        for(auto envelope : envelopes)
            hights.push_back(envelope[1]);

        return lengthOfLIS(hights);
    }

    int lengthOfLIS(vector<int>& nums){
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < dp.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int res = 0;
        for(int i = 0; i < dp.size(); i++)
            res = max(res, dp[i]);

        return res;
    }
};

int main(){
    Solution S;
    vector<vector<int>> envelopes{{4,5},{4,6},{6,7},{2,3},{1,1}};
    cout << S.maxEnvelopes(envelopes) << endl;
}