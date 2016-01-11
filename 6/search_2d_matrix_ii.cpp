/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

#include "header.h"

bool searchMatrix(vector<vector<int>>& matrix, int target) {

}

int main(){
//    vector<vector<int> > matrix = {
//        {1, 4, 7, 11, 15},
//        {2, 5, 8, 12, 19},
//        {3, 6, 9, 16, 22},
//        {10, 13, 14, 17, 24},
//        {18, 21, 23, 26, 30}
//    };
//    cout<<searchMatrix(matrix, 5)<<endl;
//    cout<<searchMatrix(matrix, 20)<<endl;

    vector<vector<int> > matrix = {
        {1},
        {3},
        {5}
    };
    cout<<searchMatrix(matrix, 1)<<endl;
    return 0;
}