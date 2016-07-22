/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

#include "header.h"

int uniquePathsWithObstacles(vector<vector<int> > &obstaclegrid) {
    int arr[100][100];
    memset(arr, 0, sizeof(arr));
    int m = obstaclegrid.size();
    int n = obstaclegrid[0].size();
    if(obstaclegrid[0][0] == 1) return 0;
    arr[0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0;j<n; j++){
            if(i == 0 && j == 0) continue;
            if(obstaclegrid[i][j] == 1) continue;
            int top = i==0||obstaclegrid[i-1][j]==1?0:arr[i-1][j];
            int left = j==0||obstaclegrid[i][j-1]==1?0:arr[i][j-1];
            arr[i][j] = top+left;
        }
    }
    return arr[m-1][n-1];
}

int main(){
    vector<vector<int> > obstacleGrid(3,vector<int>(3,0));
    obstacleGrid[1][1] = 1;
    int res = uniquePathsWithObstacles(obstacleGrid);
    printf("%d\n", res);
    return 0;
}
