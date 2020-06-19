// Source : https://leetcode.com/problems/non-overlapping-intervals/

/*
435. Non-overlapping Intervals
Medium

Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Note:

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
*/


#include "common.h"

// https://en.wikipedia.org/wiki/Interval_scheduling
// https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/tan-xin-suan-fa-zhi-qu-jian-tiao-du-wen-ti
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        auto cmp = [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; };
        // 按end升序排序
        sort(intervals.begin(), intervals.end(), cmp);
        // 至少有一个区间不相交
        int count = 1; // 不相交的区间
        int res = 0;   // 需要移除的区间
        int x_end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            int x_start = intervals[i][0];
            if(x_start >= x_end){
                count++;
                x_end = intervals[i][1];
            }else
                res++;
        }

        // cout << res << endl;

        return intervals.size() - count;
    }
};

int main(){
    vector<vector<int>> intervals{{1,2},{2,3},{3,4},{1,3}};
    Solution S;
    cout << S.eraseOverlapIntervals(intervals) << endl;
}