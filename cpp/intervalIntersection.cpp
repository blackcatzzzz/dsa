// Source : https://leetcode.com/problems/interval-list-intersections/

/*
986. Interval List Intersections

Medium

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < A.size() && j < B.size()){
            int a1 = A[i][0], a2 = A[i][1]; // [a1, a2]
            int b1 = B[j][0], b2 = B[j][1]; // [b1, b2]
            // 两个区间存在交集
            if(b2 >= a1 && a2 >= b1)
                res.push_back(vector<int>{max(a1, b1), min(a2, b2)});

            if(b2 > a2)
                i++;
            else
                j++;
        }

        return res;
    }
};