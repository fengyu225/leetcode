/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

#include "header.h"

int maximalSquare(vector<vector<char> >& matrix) {
    int r = matrix.size();
    if(r == 0) return 0;
    int c = matrix[0].size();
    if(c == 0) return 0;
    vector<vector<int> > arr(r, vector<int>(c, 0));
    int res = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(matrix[i][j] == '0') arr[i][j] = 0;
            else if(i == 0 || j == 0) arr[i][j] = 1;
            else arr[i][j] = min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1]))+1;
            res = max(res, arr[i][j]);
        }
    }
    return res*res;
}

int main(){
    char arr0[] = "1010";    
    char arr1[] = "1011";    
    char arr2[] = "1011";    
    char arr3[] = "1111";    
    vector<char> v_arr0(arr0, arr0+4);
    vector<char> v_arr1(arr1, arr1+4);
    vector<char> v_arr2(arr2, arr2+4);
    vector<char> v_arr3(arr3, arr3+4);
    vector<vector<char> > matrix;
    matrix.push_back(v_arr0);
    matrix.push_back(v_arr1);
    matrix.push_back(v_arr2);
    matrix.push_back(v_arr3);
    cout<<maximalSquare(matrix)<<endl;
    return 0;
}