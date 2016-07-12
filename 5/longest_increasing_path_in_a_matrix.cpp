/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]

Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]

Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

#include <vector>
#include <iostream>

using namespace std;

int search(vector<vector<int> >& matrix, int x, int y, int r, int c, vector<vector<int> >& arr, vector<vector<int> >& move){
    int res = 1;
    for(int i=0; i<4; i++){
        int new_x = move[i][0]+x;
        int new_y = move[i][1]+y;
        if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && matrix[x][y]<matrix[new_x][new_y]){
            if(arr[new_x][new_y]>0) res = max(res, arr[new_x][new_y]+1);
            else res = max(res, search(matrix, new_x, new_y, r, c, arr, move)+1);
        }
    }
    arr[x][y] = res;
    return res;
}

int longestIncreasingPath(vector<vector<int> >& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int> > arr(r, vector<int>(c, 0));
    int res = 1;
    vector<vector<int> > move = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    for(int i=0; i<r; i++){
        for(int j = 0; j<c; j++){
            int temp = search(matrix, i, j, r, c, arr, move);
            res = max(res, temp);
        }
    }
    return res;
}

int main(){
    vector<vector<int> > matrix = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };
    cout<<longestIncreasingPath(matrix)<<endl;
    return 0;    
}
