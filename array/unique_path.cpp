/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
m and n will be at most 100.
*/

#include "header.h"

int uniquePaths(int m, int n) {
    static vector<int> curr(101, 0);
    static vector<int> last(101, 0);
    static vector<int> arr[2] = {last, curr};
    int x = 1;
    arr[x%2][0] = 1;
    for(int i=0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(i == 0 && j == 0) continue;
            if(i == 0) arr[x%2][j] = arr[x%2][j-1];
            else if(j == 0) arr[x%2][j] = arr[(x-1)%2][j];
            else arr[x%2][j] = arr[x%2][j-1]+arr[(x-1)%2][j];
        }
        x++;
    }
    return arr[(x-1)%2][n-1];
}

int main(){
    printf("%d\n", uniquePaths(1, 2));
    return 0;
}
