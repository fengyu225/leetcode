/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
*/

#include "header.h"

int nthSuperUglyNumber(int n, vector<int>& primes) {
    //see ugly number ii
    int sz = primes.size();
    if(n == 1) return 1;
    vector<int> index(sz, 0);
    vector<int> arr(n, 1);
    for(int i=1; i<n; i++){
        int temp = INT_MAX;
        for(int j=0; j<sz; j++) temp = min(temp, arr[index[j]]*primes[j]);
        arr[i] = temp;
        for(int j=0; j<sz; j++)
            if(arr[i]%primes[j] == 0) index[j]++;
    }
    return arr[n-1];
}

int main(){
    vector<int> primes = {2, 7, 13, 19};
    cout<<nthSuperUglyNumber(8, primes)<<endl;
    return 0;
}