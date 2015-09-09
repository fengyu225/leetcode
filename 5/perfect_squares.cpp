/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

#include "header.h"

int numSquares(int n) {
    vector<int> arr(n+1, 0);
    for(int i=1; i<=n; i++){
        arr[i] = i;
        for(int j = 1; j*j<=i; j++){
            if(j*j == i) {
                arr[i] = 1;
                break;
            }
            arr[i] = min(arr[i], arr[i-j*j]+1); 
        }
    }
    return arr[n];
}

int main(){
    cout<<numSquares(12)<<endl;
    cout<<numSquares(INT_MAX-2)<<endl;
    cout<<numSquares(13)<<endl;
    cout<<numSquares(1)<<endl;
    cout<<numSquares(4)<<endl;
    return 0;
}