/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include "header.h"

int minPathSum(vector<vector<int> >& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> last(n, 0);
    vector<int> curr(n, 0);
    vector<int> arr[2] = {last, curr};
    int x = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i == 0 && j == 0) arr[x%2][0] = grid[i][j];
            else if(i == 0) arr[x%2][j] = arr[x%2][j-1]+grid[i][j];
            else if(j == 0) arr[x%2][j] = arr[(x-1)%2][j]+grid[i][j];
            else arr[x%2][j] = min(arr[x%2][j-1]+grid[i][j], arr[(x-1)%2][j]+grid[i][j]);
        }
        x++;
    }
    return arr[(x-1)%2][n-1];
}

int main(){
//    int arr[3][3] = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
    vector<vector<int> > grid = {
        {1, 2},
        {1, 1}
    };
//    vector<vector<int> > grid = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
    int res = minPathSum(grid);
    cout<<res<<endl;
    return 0;
}
