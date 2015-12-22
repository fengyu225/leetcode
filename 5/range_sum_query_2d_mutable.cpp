/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Example:

Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10

Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

#include "header.h"

class NumMatrix {
    vector<vector<int> > m;
    vector<vector<int> > sums;
    int r, c;
    void _update(int row, int col, int val){
        row++;col++;
        while(row<=r){
            for(int col_temp=col; col_temp<=c; col_temp += (col_temp & -col_temp)){
                sums[row][col_temp]+=val; 
            }
            row += (row & -row);
        }
    }
    int _sumRegion(int row, int col){
        row++;col++;
        int res = 0;
        while(row>0){
            for(int col_temp=col; col_temp>0; col_temp -= (col_temp & -col_temp))
                res += sums[row][col_temp];
            row += (row & -row);
        }
        return res;
    }
public:
    NumMatrix(vector<vector<int> > &matrix) {
        m = matrix;
        r = matrix.size();
        c = matrix[0].size();
        sums = vector<vector<int> >(r+1, vector<int>(c+1, 0));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++)
                _update(i, j, m[i][j]);
        }
    }

    void update(int row, int col, int val) {
        _update(row, col, val-m[row][col]);
        m[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1==row2 && col1 == col2)
            return m[row1][col1];
        return 
            _sumRegion(row2, col2)-
            (row1==0?0:_sumRegion(row1-1, col2))- 
            (col1==0?0:_sumRegion(row2, col1-1))+
            ((row1==0||col1==0)?0:_sumRegion(row1-1, col1-1));
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);

int main(){
    vector<vector<int> > matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix numMatrix(matrix);
    cout<<numMatrix.sumRegion(2, 1, 4, 3)<<endl;
//    numMatrix.update(3, 2, 2);
//    cout<<numMatrix.sumRegion(2, 1, 4, 3)<<endl;
    return 0;
}