/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

#include "header.h"

vector<int> spiralOrder(vector<vector<int> >& matrix){
    int m = matrix.size();
    vector<int> res;
    if(m == 0) return res;
    int n = matrix[0].size();
    int offset = 0;
    int sz = 0;
    while(sz<n*m){
        for(int i=offset; i<n-offset; i++){
            res.push_back(matrix[offset][i]);
            sz++;
        }
        for(int i=1+offset; i<m-offset; i++){
            res.push_back(matrix[i][n-offset-1]);
            sz++;
        }
        if(m-1-offset>offset){
            for(int i=n-2-offset; i>=offset; i--){
                res.push_back(matrix[m-1-offset][i]);
                sz++;
            }
        }
        if(offset<n-offset-1){
            for(int i=m-2-offset; i>offset; i--){
                res.push_back(matrix[i][offset]);
                sz++;
            }
        }
        offset++;
    }
    return res;
}

int main(){
    int arr0[] = {1, 2, 3};
//    int arr0[] = {1, 2, 3};
//    int arr1[] = {4, 5, 6};
//    int arr2[] = {7, 8, 9};
//    int arr3[] = {10, 11, 12};
    vector<int> v0(arr0, arr0+sizeof(arr0)/sizeof(arr0[0]));
//    vector<int> v1(arr1, arr1+sizeof(arr1)/sizeof(arr1[1]));
//    vector<int> v2(arr2, arr2+sizeof(arr2)/sizeof(arr2[2]));
//    vector<int> v3(arr3, arr3+sizeof(arr3)/sizeof(arr3[3]));
    vector<vector<int> > matrix;
    matrix.push_back(v0);
//    matrix.push_back(v1);
//    matrix.push_back(v2);
//    matrix.push_back(v3);
    vector<int> res = spiralOrder(matrix);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
