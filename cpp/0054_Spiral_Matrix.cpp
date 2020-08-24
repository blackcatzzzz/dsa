/*
54. Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include "common.h"


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        int startX = 0, startY = 0;
        int endX = m - 1, endY = n - 1;
        while(startX <= endX && startY <= endY){
            for(int j = startY; j <= endY; j++)
                res.push_back(matrix[startX][j]);
            
            if(startX == endX)
                break;
            for(int i = startX + 1; i <= endX; i++)
                res.push_back(matrix[i][endY]);

            if(startY == endY)
                break;
                
            for(int j = endY - 1; j >= startY; j--)
                res.push_back(matrix[endX][j]);

            for(int i = endX - 1; i >= startX + 1; i--)
                res.push_back(matrix[i][startY]);

            startX++, startY++;
            endX--, endY--;
        }
        return res;
    }
};

int main(){
    Solution S;
    vector<vector<int>> matrix{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    printVector(S.spiralOrder(matrix));
}