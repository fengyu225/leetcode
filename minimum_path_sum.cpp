/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include "header.h"

int minPathSum(vector<vector<int> > &grid) {
    int res = INT_MAX;
    int r = grid.size(), c = grid[0].size();
    int arr[r][c];
    memset(arr, 0, sizeof(arr));
    arr[0][0] = grid[0][0];
    for(int i=0; i<r; i++){
        for(int j=0;j<c;j++){
            if(i == 0 && j==0) continue;
            int up = i==0?INT_MAX:arr[i-1][j];
            int left = j==0?INT_MAX:arr[i][j-1];
            arr[i][j] = grid[i][j]+min(up, left);
            res = min(arr[i][j], res);
        }
    }
    return arr[r-1][c-1];
}

int main(){
//    int arr[3][3] = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
    int arr[2][2] = {
        {1, 2},
        {1, 1}
    };
    vector<vector<int> > grid;
    for(int i=0; i<2; i++){
        vector<int> v;
        for(int j=0;j<2;j++)
            v.push_back(arr[i][j]);
        grid.push_back(v);
    }
    int res = minPathSum(grid);
    printf("%d\n", res);
    return 0;
}
