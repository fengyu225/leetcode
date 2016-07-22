/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12

Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

#include "header.h"

class NumMatrix {
    vector<vector<int> > sums;
public:
    NumMatrix(vector<vector<int> > &matrix) {
        if(!(matrix.size() == 0 || matrix[0].size() == 0)){
            int row = matrix.size(), col = matrix[0].size();
            sums = vector<vector<int> >(row, vector<int>(col, 0));
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    if(i == 0 && j == 0) sums[i][j] = matrix[i][j];
                    else if(i == 0) sums[i][j] = sums[i][j-1]+matrix[i][j];
                    else if(j == 0) sums[i][j] = sums[i-1][j]+matrix[i][j];
                    else sums[i][j] = sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0) return sums[row2][col2];
        else if(row1 == 0) return sums[row2][col2]-sums[row2][col1-1];
        else if(col1 == 0) return sums[row2][col2]-sums[row1-1][col2];
        else return sums[row2][col2]-sums[row1-1][col2]-sums[row2][col1-1]+sums[row1-1][col1-1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main(){
    vector<vector<int> > matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix numMatrix(matrix);;
    cout<<numMatrix.sumRegion(2, 1, 4, 3)<<endl;
    cout<<numMatrix.sumRegion(0, 1, 2, 3)<<endl;
    return 0;
}