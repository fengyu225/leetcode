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

#include "header.h"

int longestIncreasingPath(vector<vector<int> >& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int> > arr(r, vector<int>(c, -1));
}

int main(){
    vector<vector<int> > matrix = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };
    return 0;    
}