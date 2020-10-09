/*
240. Search a 2D Matrix II
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

#include "common.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int row = matrix.size() - 1;
        int col = 0;
        while(row >= 0 && col <= matrix[0].size() - 1){
            if(target == matrix[row][col])
                return true;
            else if(target < matrix[row][col])
                row--;
            else
                col++;
        }

        return false;
    }
};


int main(){
    Solution S;
    vector<vector<int>> matrix;
    cout << S.searchMatrix(matrix, 1);
}