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

bool search(vector<int>& arr, int target){
    int l = 0, r=arr.size()-1;
    while(l<r){
        int m = (l+r)/2;
        if(target == arr[m]) return true;
        if(target<arr[m]) r=m-1;
        else l=m+1;
    }
    return l==r && l>=0 && target==arr[l];
}

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if(matrix.size() == 0) return false;
    int r = matrix.size(), c=matrix[0].size();
    int curr = 0;
    while(curr<r){
        if(target>matrix[curr][c-1]) curr++;
        else return search(matrix[curr], target);
    }
    return false;
}

int main(){
    vector<vector<int> > matrix;
    int arr[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23,30,34,50}
    };
    for(int i=0; i<3; i++){
        vector<int> v(arr[i], arr[i]+sizeof(arr[i])/sizeof(arr[i][0]));
        matrix.push_back(v);
    }
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    bool res = searchMatrix(matrix,100);
    printf("%s\n", res?"true":"false");
    return 0;
}
