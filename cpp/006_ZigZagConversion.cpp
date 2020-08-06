/*
6. ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

#include "common.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 0) return "";
        if(numRows == 1) return s;

        vector<string> rows(min(int(s.length()), numRows));
        int curRow = 0;
        bool goingDown = false;
        for(int i = 0; i < s.size(); i++){
            rows[curRow] += s[i];
            if(curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow = goingDown ? curRow + 1 : curRow - 1;
        }

        string res;
        for(auto row : rows) 
            res += row;

        return res;
    }
};

int main(){
    string s = "PAYPALISHIRING";
    int numRows = 4;
    Solution S;
    cout << S.convert(s, numRows) << endl;
}