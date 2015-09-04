/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

#include "header.h"

void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    if(n == 0) return;
    for(int i=0; i<(n-1)<<1; i++){
        for(int j=i; j<n-1-i; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = temp;
        }
    }
}

int main(){
    vector<vector<int> > matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
//    int arr0[] = {1, 2, 3};
//    int arr1[] = {4, 5, 6};
//    int arr2[] = {7, 8, 9};
//    vector<vector<int> > matrix;
//    matrix.push_back(vector<int>(arr0, arr0+sizeof(arr0)/sizeof(arr0[0])));
//    matrix.push_back(vector<int>(arr1, arr1+sizeof(arr1)/sizeof(arr1[0])));
//    matrix.push_back(vector<int>(arr2, arr2+sizeof(arr2)/sizeof(arr2[0])));
    rotate(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
