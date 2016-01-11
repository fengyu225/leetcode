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

//bool search(vector<vector<int> >& matrix, int r_0, int r_1, int c_0, int c_1, int target){
////    cout<<r_0<<" "<<r_1<<endl;
//    if(r_0>r_1 || c_0>c_1) return false;
//    if(r_0 == r_1 && c_0 == c_1) return matrix[r_0][c_0] == target;
//    int r_m = r_0+(r_1-r_0)/2, c_m = c_0+(c_1-c_0)/2;
//    if(matrix[r_m][c_m] == target) return true;
//    if(matrix[r_m][c_m]>target) return 
//        search(matrix, r_0, r_m-1, c_0, c_m-1, target) ||
//        search(matrix, r_0, r_m-1, c_m, c_1, target) ||
//        search(matrix, r_m, r_1, c_0, c_m-1, target);
//    else return 
//        search(matrix, r_0, r_m, c_m+1, c_1, target) ||
//        search(matrix, r_m+1, r_1, c_0, c_m, target) ||
//        search(matrix, r_m+1, r_1, c_m+1, c_1, target);
//}
//
//bool searchMatrix(vector<vector<int> >& matrix, int target) {
//    if(matrix.size() == 0 || matrix[0].size() == 0) return false;
//    int r = matrix.size(), c = matrix[0].size();
//    return search(matrix, 0, r-1, 0, c-1, target);
//}

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if(matrix.size() == 0 || matrix[0].size() == 0) return false;
    int r = matrix.size(), c = matrix[0].size();
    int curr_r = 0, curr_c = c-1;
    while(curr_r>=0 && curr_r<r && curr_c>=0 && curr_c<c){
        if(matrix[curr_r][curr_c] == target) return true;
        else if(matrix[curr_r][curr_c]<target) curr_r++;
        else curr_c--;
    }
    return false;
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

//    vector<vector<int> > matrix = {
//        {1},
//        {3},
//        {5}
//    };
//    cout<<searchMatrix(matrix, 2)<<endl;    
    vector<vector<int> > matrix = {
        {-5}
    };
    cout<<searchMatrix(matrix, -5)<<endl;

    return 0;
}