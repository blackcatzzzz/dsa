
/*
85. Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0
 

Constraints:

rows == matrix.length
cols == matrix.length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

#include "common.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        vector<int> dp(n);
        int maxArea = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(dp));
        }

        return maxArea;
    }

private:
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