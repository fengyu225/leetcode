/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.
*/

#include "header.h"

/*
Why the max product of any n>4 must contain a factor of 3? 
1. It can't contain any factor x that is >= 5, o.w., we can further increase the max product by decomposing x, as the decomposed x when x>=5 is strictly greater than x;
2. Out of 1, 2, 3, 4, we know 1 won't be a factor of n when n>4, if n is an odd number, 3 must be there as a factor (2 and 4 can't add up to an odd number); 
3. Now say n is an even number (n>4) and only has factor of 2 and 4, we can always split a 6 to 3X3, which is better than 2X2X2.
Therefore, the max product of any n (n>4) must contain a factor of 3. The recurrence relation holds.
*/

int integerBreak(int n) {
    if(n == 2) return 1;
    if(n == 3) return 2;
    if(n == 4) return 3;
    vector<int> arr(n+1, 1);
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;
    for(int i=5; i<=n; i++) arr[i] = 3*arr[i-3];
    return arr[n];
}

//int integerBreak(int n) {
//    //O(n^2)
//    vector<int> arr(n+1, 1);
//    for(int i=2; i<=n; i++){
//        int temp = 1;
//        for(int j=1; j<i; j++) temp = max(temp, max(j, arr[j])*(i-j));
//        arr[i] = temp;
//    }
//    return arr[n];
//}

int main(){
//    cout<<integerBreak(2)<<endl;
    //cout<<integerBreak(10)<<endl;
    cout<<integerBreak(6)<<endl;
    return 0;
}
