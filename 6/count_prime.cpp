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
//    if(n<=2) return 0;
//    vector<bool> arr(n-1, true);
//    for(int i=2; i*i<n; i++){
//        if(!arr[i]) continue;
//        int temp = i;
//        for(int j=temp; temp*j<n; j++) arr[temp*j]=false;
//    }
//    int res = 0;
//    for(int i=2; i<n; i++){
//        if(arr[i]) res++;
//    }
//    return res;
//}
//

int countPrimes(int n) {
    if(n<2) return 0;
//    vector<bool> arr(n, true);
    bool* arr = new bool[n];
    fill_n(arr, n, true);
    int res = n-2;
    for(int i=2; i*i<n; i++){
        if(!arr[i]) continue;
        int temp = i;
        for(int j=temp; temp*j<n; j++){
            if(arr[temp*j]){
                arr[temp*j]=false;
                res--;
            }
        }
    }
    return res;
}

int main(){
    cout<<countPrimes(13)<<endl;
    return 0;
}