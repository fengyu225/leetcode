/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
*/

#include "header.h"

int maxKilledEnemies(vector<vector<char>>& grid) {
    int r = grid.size();
    if(r == 0) return 0;
    int c = grid[0].size();
    vector<vector<pair<int,int> > > arr(r, vector<pair<int,int> >(c, {0,0}));
    vector<vector<pair<int,int> > > arr1(r, vector<pair<int,int> >(c, {0,0}));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(grid[i][j] == 'W') arr[i][j] = make_pair(0,0); 
            else{
                int temp = (grid[i][j] == '0')?0:1;
                arr[i][j].first = (j==0?0:arr[i][j-1].first)+temp;
                arr[i][j].second = (i==0?0:arr[i-1][j].second)+temp;
            }
        }
    }
    for(int i=r-1; i>=0; i--){
        for(int j=c-1; j>=0; j--){
            if(grid[i][j] == 'W') arr1[i][j] = make_pair(0,0); 
            else{
                int temp = (grid[i][j] == '0')?0:1;
                arr1[i][j].first = (j==c-1?0:arr1[i][j+1].first)+temp;
                arr1[i][j].second = (i==r-1?0:arr1[i+1][j].second)+temp;
            }
        }
    }
    int res = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            if(grid[i][j] == '0') res=max(res, arr[i][j].first+arr[i][j].second+arr1[i][j].first+arr1[i][j].second);
    }
    return res;
}

int main(){
    vector<vector<char> > grid = {
        {'0', 'E', '0', '0'},
        {'E', '0', 'W', 'E'},
        {'0', 'E', '0', '0'}
    };
    cout<<maxKilledEnemies(grid)<<endl;
    return 0;
}
