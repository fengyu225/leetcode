#include "header.h"

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    if(obstacleGrid[0][0] == 1) return 0;
    int r = obstacleGrid.size();
    int c = obstacleGrid[0].size();
    if(obstacleGrid[r-1][c-1] == 1) return 0;
    vector<vector<int> > v(r,vector<int>(c,0));
    for(int i=0; i<r; i++)
        if(obstacleGrid[i][0] == 1)
            break;
        else
            v[i][0] = 1;
    for(int i=0; i<c; i++)
        if(obstacleGrid[0][i] == 1)
            break;
        else
            v[0][i] = 1;
    for(int i=1; i<r; i++)
        for(int j=1; j<c; j++){
            v[i][j] = 0;
            if(obstacleGrid[i-1][j] != 1)
                v[i][j]+=v[i-1][j];
            if(obstacleGrid[i][j-1] != 1)
                v[i][j]+=v[i][j-1];
        }
    return v[r-1][c-1];
}

int main(){
    vector<vector<int> > obstacleGrid(3,vector<int>(3,0));
    obstacleGrid[1][1] = 1;
    int res = uniquePathsWithObstacles(obstacleGrid);
    printf("%d\n", res);
    return 0;
}
