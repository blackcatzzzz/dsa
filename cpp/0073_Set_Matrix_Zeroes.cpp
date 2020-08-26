/*
73. Set Matrix Zeroes
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-10^9 <= matrix[i][j] <= 10^9
*/

#include "common.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // columns
        bool isCol = false;

        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0)
                isCol = true;
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        }

        if(matrix[0][0] == 0)
            for(int j = 1; j < n; j++)
                matrix[0][j] = 0;

        if(isCol)
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};

int main(){
    Solution S;
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,0,7,8},
        {0,10,11,12},
        {13,14,15,0}
    };
    S.setZeroes(matrix);
    printVectors(matrix);
}