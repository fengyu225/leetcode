/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
m and n will be at most 100.
*/

#include "header.h"

int uniquePaths(int m, int n) {
    int arr[100][100];
    arr[0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) continue;
            int up = i==0?0:arr[i-1][j];
            int left = j==0?0:arr[i][j-1];
            arr[i][j] = up+left;
        }
    }
    return arr[m-1][n-1];
}

int main(){
    printf("%d\n", uniquePaths(1, 2));
    return 0;
}
