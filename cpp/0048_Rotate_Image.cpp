/*
48. Rotate Image
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

#include "common.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int pos1 = 0, pos2 = matrix.size() - 1;
        // 左上角1， 右上角2，右下角3，左下角4
        while(pos1 < pos2){
            int offset = 0;
            while(pos1 + offset < pos2){
                // tmp = 1
                int tmp = matrix[pos1][pos1 + offset];
                // 1 = 4
                matrix[pos1][pos1 + offset] = matrix[pos2 - offset][pos1];
                // 4 = 3
                matrix[pos2 - offset][pos1] = matrix[pos2][pos2 - offset];
                // 3 = 2
                matrix[pos2][pos2 - offset] = matrix[pos1 + offset][pos2];
                // 2 = 1
                matrix[pos1 + offset][pos2] =  tmp;
                offset++;
            }
            pos1++;
            pos2--;
        }

    }
};

int main(){
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    Solution S;
    S.rotate(matrix);
    getchar();
}