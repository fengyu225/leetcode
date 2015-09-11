/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

#include "header.h"

bool search(vector<int>& v, int target, int l, int r){
    while(l<=r){
        int m = (l+r)/2;
        if(v[m] == target) return true;
        else if(target<v[m]) r=m-1;
        else l=m+1;
    }
    return false;
}

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int r = matrix.size(), c = matrix[0].size();
    int l = 0, h = r-1;
    while(l<=h){
        int m = (l+h)/2;
        if(target >= matrix[m][0] && target <= matrix[m][c-1]) return search(matrix[m], target, 0, c-1);
        else if(target<matrix[m][0]) h=m-1;
        else l=m+1;
    }
    return false;
}

int main(){
    vector<vector<int> > matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23,30,34,50}
    };
    print_2d_vector<int>(matrix);
    bool res = searchMatrix(matrix,1);
    printf("%s\n", res?"true":"false");
    return 0;
}
