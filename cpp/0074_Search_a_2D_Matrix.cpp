/*
74. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

#include "common.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        
        int n = matrix[0].size();
        if(n == 0) return false;

        int l = 0, r = m * n - 1;
        while(l <= r){
          int pivotIndex = l + (r - l) / 2;
          int pivotElement = matrix[pivotIndex / n][pivotIndex % n];
          if(target == pivotElement)
            return true;
          else if(target < pivotElement)
            r = pivotIndex - 1;
          else
            l = pivotIndex + 1;
        }

        return false;
    }
};

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;

        int n = matrix[0].size();
        if(n == 0) return false;

        int l = 0, r = m - 1;
        int row = -1;
        while(l <= r){
          row = l + (r - l) / 2;
          if(target == matrix[row][0])
            return true;
          else if(target < matrix[row][0])
            r = row - 1;
          else if(target > matrix[row][n - 1])
            l = row + 1;
          else 
            break;
        }

        if(l == m || r == -1)
          return false;

        l = 0, r = n - 1;
        while(l <= r){
          int mid = l + (r - l) / 2;
          if(target == matrix[row][mid])
            return true;
          else if(target < matrix[row][mid])
            r = mid - 1;
          else
            l = mid + 1;
        }

        return false;
    }
};

int main(){
  Solution S;
  vector<vector<int>> matrix = {
    {1,  1},
    // {10, 11, 16, 20},
    // {23, 30, 34, 50}
  };
  cout << S.searchMatrix(matrix, 2);
}