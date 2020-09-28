/*
223. Rectangle Area
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:

Assume that the total area is never beyond the maximum possible value of int.
*/

#include "common.h"

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        // if(area1 == 0 || area2 == 0)
        //     return area1 + area2;
        long long overlap_h = (long long)min(D, H) - (long long)max(B, F);
        long long overlap_w = (long long)min(G, C) - (long long)max(A, E);
        int overlap_area = overlap_h > 0 && overlap_w > 0 ? overlap_w * overlap_h : 0;
        return area1 - overlap_area + area2 ; // 先减防止溢出
    }
};

int main(){
    Solution S;
    cout << S.computeArea(0, 0, 50000, 40000, 0, 0, 50000, 40000)<< endl;
    // cout << S.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    // cout << S.computeArea(0, 0, 0, 0, -1, -1, 1, 1)<< endl;
    // cout << S.computeArea(-2, -2, 2, 2, -1, -1, 1, 1)<< endl;
}