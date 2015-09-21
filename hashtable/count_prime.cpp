/*
Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Hint:

Let's start with a isPrime function. To determine if a number is prime, we need to check if it is not divisible by any number less than n. The runtime complexity of isPrime function would be O(n) and hence counting the total prime numbers up to n would be O(n2). Could we do better?
*/

#include "header.h"

//int countPrimes(int n) {
//    vector<bool> arr(n, true);
//    arr[0] = arr[1] = false;
//    int x = sqrt(n);
//    for(int i=2; i<=x; i++){
//        if(!arr[i]) continue;
//        for(int k=2; i*k<n; k++) arr[i*k] = false;
//    }
//    int res = 0;
//    for(int i=0; i<n; i++) res += arr[i]?1:0;
//    return res;
//}

int countPrimes(int n) {
    // not spend extra loop for count
    // using bool array on heap
    if(n<2) return 0;
    bool* arr = new bool[n];
    fill_n(arr, n, true);
    arr[0] = arr[1] = false;
    int cnt = n-2, x=sqrt(n);
    for(int i=2; i<=x; i++){
        if(!arr[i]) continue;
        for(int k=2; i*k<n; k++){
            if(arr[i*k]) cnt--;
            arr[i*k] = false;
        }
    }
    return cnt;
}


int main(){
//    cout<<countPrimes(100)<<endl;
    cout<<countPrimes(5)<<endl;
//    cout<<countPrimes(12)<<endl;
    return 0;
}