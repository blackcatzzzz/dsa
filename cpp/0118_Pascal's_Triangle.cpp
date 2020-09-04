/*
118. Pascal's Triangle
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
          return {};
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++){
            vector<int> line(i + 1, 0);
            for(int j = 0; j < i + 1; j++){
                if(i == 0 || j == 0 || j == i){
                    line[j] = 1;
                }else{
                    line[j] = res[i - 1][j] + res[i - 1][j - 1];
                }
            }
            res.push_back(line);
        }

        return res;
    }
};

int main(){
    Solution S;
    printVectors(S.generate(5));
}