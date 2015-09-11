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

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if(obstacleGrid[0][0] == 1) return 0;
    static vector<int> last(101, 0);
    static vector<int> curr(101, 0);
    static vector<int> arrs[2] = {last, curr};
    int x = 1;
    arrs[x%2][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i == 0 && j == 0) continue;
            if(obstacleGrid[i][j] == 1){
                arrs[x%2][j] = 0;
                continue;
            }
            if(i == 0) arrs[x%2][j] = obstacleGrid[i][j-1] == 1?0:(arrs[x%2][j-1]);
            else if(j == 0) arrs[x%2][j] = obstacleGrid[i-1][j]==1?0:(arrs[(x-1)%2][j]);
            else arrs[x%2][j] = (obstacleGrid[i][j-1] == 1?0:arrs[x%2][j-1]) + (obstacleGrid[i-1][j]==1?0:arrs[(x-1)%2][j]);
        }
        x++;
    }
    return arrs[(x-1)%2][n-1];
}

int main(){
    vector<vector<int> > obstacleGrid(3,vector<int>(3,0));
    obstacleGrid[1][1] = 1;
    int res = uniquePathsWithObstacles(obstacleGrid);
    printf("%d\n", res);
    return 0;
}
