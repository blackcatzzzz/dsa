/*
56. Merge Intervals
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

intervals[i][0] <= intervals[i][1]
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty())
            return res;
        auto cmp = [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];};
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            int l = intervals[i][0], r = intervals[i][1];
            if(res.back()[1] < l)
                res.push_back(intervals[i]);
            else
                res.back()[1] = max(res.back()[1], r);
        }

        return res;
    }
};

int main(){
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    Solution S;
    vector<vector<int>> res = S.merge(intervals);
    getchar();
}