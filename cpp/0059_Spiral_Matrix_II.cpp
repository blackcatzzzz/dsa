/*
59. Spiral Matrix II
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int startX = 0, startY = 0;
        int endX = n - 1, endY = n - 1;
        int k = 1;
        while(startX <= endX && startY <= endY){
            for(int j = startY; j <= endY; j++)
                matrix[startX][j] = k++;
            
            if(startX == endX)
                break;
            for(int i = startX + 1; i <= endX; i++)
                matrix[i][endY] = k++;

            if(startY == endY)
                break;
                
            for(int j = endY - 1; j >= startY; j--)
                matrix[endX][j] = k++;

            for(int i = endX - 1; i >= startX + 1; i--)
                matrix[i][startY] = k++;

            startX++, startY++;
            endX--, endY--;
        }
        return matrix;       
    }
};

int main(){
    Solution S;
    S.generateMatrix(3);
}