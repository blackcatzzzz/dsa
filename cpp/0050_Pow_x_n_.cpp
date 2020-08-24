/*
50. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e. xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104
*/

#include "common.h"


class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return x;
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }

private:
    double quickMul(double x, long long N){
        if(N == 0)
            return 1.0;
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
};

int main(){
    double x = 0.00001;
    int n = 2147483647;
    Solution S;
    cout << S.myPow(x, n) << endl;
}