/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:

Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2

The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
*/

#include "header.h"

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int r = matrix.size();
    if(r == 0) return 0;
    int c = matrix[0].size();
    if(c == 0) return 0;
    vector<vector<int> > sums(r, vector<int>(c, 0));
    for(int i=0; i<r; i++){
        sums[i][0] = matrix[i][0];
        for(int j = 1; j<c; j++) sums[i][j] = sums[i][j-1]+matrix[i][j];
    }
    for(int l = 0; l<c; l++){
        for(int r = l+1; r<c; r++){
               
        }
    } 
}

int main(){
    vector<vector<int> > matrix = {
        {1, 0, 1},
        {0, -2, 3}
    };
    cout<<maxSumSubmatrix(matrix, 2)<<endl;
    return 0;
}
