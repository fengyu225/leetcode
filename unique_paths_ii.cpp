#include "header.h"

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int r = obstacleGrid.size();
    int c = obstacleGrid[0].size();
    if(obstacleGrid[0][0] == 1 || obstacleGrid[r-1][c-1]==1) return 0;
    int arr[r][c];
    memset(arr,0,sizeof(arr));
    arr[0][0] = 1;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(i == 0 && j==0){arr[i][j] = 1;continue;}
            int up = i==0?0:obstacleGrid[i-1][j]==1?0:arr[i-1][j];
            int left = j==0?0:obstacleGrid[i][j-1]==1?0:arr[i][j-1];
            arr[i][j] = up+left;
            cout<<"arr["<<i<<"]["<<j<<"] = "<<arr[i][j]<<endl;
        }
    }
    return arr[r-1][c-1];
}

int main(){
    vector<vector<int> > obstacleGrid(3,vector<int>(3,0));
    obstacleGrid[1][1] = 1;
    int res = uniquePathsWithObstacles(obstacleGrid);
    printf("%d\n", res);
    return 0;
}
