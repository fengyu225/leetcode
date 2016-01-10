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

int maximalSquare(vector<vector<char> >& matrix){
    if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int> > arr(r, vector<int>(c, 0));
    int res = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(matrix[i][j] == '0') arr[i][j] = 0;
            else if(i == 0 || j == 0) arr[i][j] = 1;
            else arr[i][j] = min(min(arr[i-1][j], arr[i][j-1]), arr[i-1][j-1])+1;
            res = max(res, arr[i][j]);
        }
    }
    return res*res;
}

int main(){
    vector<vector<char> > matrix = {
        {'1','0','1','0'},
        {'1','0','1','1'},
        {'1','0','1','1'},
        {'1','1','1','1'}        
    };
    cout<<maximalSquare(matrix)<<endl;
    return 0;
}