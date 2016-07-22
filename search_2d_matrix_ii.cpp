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

// quad search
//bool search(vector<vector<int> >& matrix, int target, int r_start, int r_end, int c_start, int c_end){
//    if(r_start>r_end || c_start>c_end) return false;
//    int r_m = (r_start+r_end)/2;
//    int c_m = (c_start+c_end)/2;
//    if(matrix[r_m][c_m] == target) return true;
//    else if(matrix[r_m][c_m]<target)
//        return 
//            search(matrix, target, r_m+1, r_end, c_m+1, c_end) ||
//            search(matrix, target, r_start, r_m, c_m+1, c_end) ||
//            search(matrix, target, r_m+1, r_end, c_start, c_m);
//    else
//        return
//            search(matrix, target, r_start, r_m-1, c_start, c_m-1) ||
//            search(matrix, target, r_start, r_m-1, c_m, c_end) ||
//            search(matrix, target, r_m, r_end, c_start, c_m-1);
//}
//
//bool searchMatrix(vector<vector<int> >& matrix, int target) {
//    int r = matrix.size();
//    if(r == 0) return false;
//    int c = matrix[0].size();
//    if(c == 0) return false;
//    return search(matrix, target, 0, r-1, 0, c-1);
//}

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int r = matrix.size();
    if(r == 0) return false;
    int c = matrix[0].size();
    if(c == 0) return false;
    int curr_r = 0, curr_c = c-1;
    while(curr_r<r && curr_r>=0 && curr_c<c && curr_c >= 0){
        if(matrix[curr_r][curr_c] == target) return true;
        else if(matrix[curr_r][curr_c]<target) curr_r++;
        else curr_c--;
    }
    return false;
}

int main(){
//    int arr0[] = {1, 4, 7, 11, 15};
//    int arr1[] = {2, 5, 8, 12, 19};
//    int arr2[] = {3, 6, 9, 16, 22};
//    int arr3[] = {10, 13, 14, 17, 24};
//    int arr4[] = {18, 21, 23, 26, 30};
//    vector<vector<int> > matrix;
//    matrix.push_back(vector<int>(arr0, arr0+sizeof(arr0)/sizeof(arr0[0])));
//    matrix.push_back(vector<int>(arr1, arr1+sizeof(arr1)/sizeof(arr1[1])));
//    matrix.push_back(vector<int>(arr2, arr2+sizeof(arr2)/sizeof(arr2[2])));
//    matrix.push_back(vector<int>(arr3, arr3+sizeof(arr3)/sizeof(arr3[3])));
//    matrix.push_back(vector<int>(arr4, arr4+sizeof(arr4)/sizeof(arr4[4])));
//    cout<<searchMatrix(matrix, 5)<<endl;
//    cout<<searchMatrix(matrix, 20)<<endl;

    int arr0[] = {1};
    int arr1[] = {3};
    int arr2[] = {5};
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(arr0, arr0+sizeof(arr0)/sizeof(arr0[0])));
    matrix.push_back(vector<int>(arr1, arr1+sizeof(arr1)/sizeof(arr1[1])));
    matrix.push_back(vector<int>(arr2, arr2+sizeof(arr2)/sizeof(arr2[2])));
    cout<<searchMatrix(matrix, 1)<<endl;

    return 0;
}