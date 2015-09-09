/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

#include "header.h"

int numSquares(int n) {
    int arr[n+1];
    arr[0] = 0;
    for(int i=1; i<=n; i++){
        int temp = INT_MAX;
        for(int j = 1; j*j<=i; j++){
            temp = min(temp, arr[i-j*j]+1); 
        }
        arr[i] = temp;
    }
    return arr[n];
}

int numSquares(int n) {
    //this code is much faster than above code, because it use static?
    static vector<int> dp {0};
    while (dp.size() <= n) {
        int m = dp.size(), squares = INT_MAX;
        for (int i=1; i*i<=m; ++i)
            squares = min(squares, dp[m-i*i] + 1);
        dp.push_back(squares);
    }
    return dp[n];
}

int main(){
    cout<<numSquares(100000)<<endl;
//    cout<<numSquares(12)<<endl;
//    cout<<numSquares(100000)<<endl;
//    cout<<numSquares(13)<<endl;
//    cout<<numSquares(1)<<endl;
//    cout<<numSquares(4)<<endl;
    return 0;
}