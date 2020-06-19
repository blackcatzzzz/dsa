// Source : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

/*
452. Minimum Number of Arrows to Burst Balloons

Medium

There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
*/

#include "common.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        auto cmp = [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; };
        // 按end升序排序
        sort(points.begin(), points.end(), cmp);
        // 至少有一个区间不相交
        int count = 1; // 最大不相交的区间
        int x_end = points[0][1];
        for(int i = 1; i < points.size(); i++){
            int x_start = points[i][0];
            if(x_start > x_end){
                count++;
                x_end = points[i][1];
            }
        }

        return count;
    }
};

int main(){
    vector<vector<int>> points{};
}