/// Source : https://leetcode.com/problems/flood-fill/

/*
733. Flood Fill

Easy

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int origColor = image[sr][sc];
        fill(image, sr, sc, origColor, newColor);
        return image;
    }

    void fill(vector<vector<int>>& image, int x, int y, int origColor, int newColor){
        // 出界：超出数组边界
        if(!inArea(image, x, y)) return;
        // 碰壁：遇到其他颜色，超出 origColor 区域
        if(image[x][y] != origColor) return;
        // 已探索过的 origColor 区域
        if(image[x][y] == -1) return;

        // choose：打标记，以免重复
        image[x][y] = -1;
        fill(image, x - 1, y, origColor, newColor);
        fill(image, x + 1, y, origColor, newColor);
        fill(image, x, y - 1, origColor, newColor);
        fill(image, x, y + 1, origColor, newColor);
        // unchoose：将标记替换为 newColor
        image[x][y] = newColor;
    }

    bool inArea(vector<vector<int>>& image, int x, int y){
        return x >= 0 && x < image.size() &&
                y >= 0 && y < image[0].size();
    }
};