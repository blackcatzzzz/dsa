
/*
84. Largest Rectangle in Histogram
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/

#include "common.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> mono_stack;
        for(int i = 0; i < n; i++){
            while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
                mono_stack.pop();

            left[i] = mono_stack.empty() ? - 1 : mono_stack.top();
            mono_stack.push(i);
        }

        // 可优化，只遍历一次，如有相同高度的柱子，右边界可在相等高度的最右柱子确定
        mono_stack = stack<int>();
        for(int i = n - 1; i >= 0; i--){
            while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
                mono_stack.pop();
            right[i] = mono_stack.empty() ? n : mono_stack.top();
            mono_stack.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));

        return ans;
    }
};

int main(){

}