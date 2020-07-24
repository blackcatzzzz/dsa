
/*
204. Count Primes
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

#include "common.h"

// brute force
class Solution_BF {
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i = 2; i < n; i++){
            if(isPrime(i))
                count++;
        }
        cout << endl;
        return count;
    }

private:
    bool isPrime(int n){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0)
                return false;
        }
        cout << n << " ";
        return true;
    }
};

//  Sieve of Eratosthenes。
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        for(int i = 2; i < n; i++){
            if(isPrime[i])
                for(int j = i * 2; j < n; j += i)
                    isPrime[j] = false;
        }

        int count = 0;
        for(int i = 2; i < n; i++)
            if(isPrime[i])
                count++;

        return count;
    }
};

int main(){
    Solution S;
    cout << S.countPrimes(10) << endl;
}

