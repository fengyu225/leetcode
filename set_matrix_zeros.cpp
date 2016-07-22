/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#include "header.h"

void print(vector<vector<int> > &matrix){
    cout<<"================="<<endl;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<"================="<<endl;
}

void setZeroes(vector<vector<int> > &matrix) {
    int r = matrix.size(), c = matrix[0].size();
    bool first_row_zero = false, first_col_zero = false;
    for(int i=0; i<r; i++) first_row_zero |= (matrix[i][0] == 0);
    for(int i=0; i<c; i++) first_col_zero |= (matrix[0][i] == 0);
    for(int i=1; i<r; i++)
        for(int j=1; j<c; j++)
            if(matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    for(int i=1; i<r; i++){
        if(matrix[i][0] == 0)
            for(int j=0;j<c;j++) matrix[i][j] =0;
    }
    for(int j=1; j<c; j++){
        if(matrix[0][j] == 0)
            for(int i=0; i<r; i++) matrix[i][j] = 0;
    }
    for(int i=1; i<r; i++)
        if(matrix[i][0])
            matrix[i][0] = first_row_zero?0:matrix[i][0];
    for(int i=1; i<c; i++)
        if(matrix[0][i])
            matrix[0][i] = first_col_zero?0:matrix[0][i];
    matrix[0][0] = (first_row_zero||first_col_zero)?0:matrix[0][0];
}

int main(){
    /*
     1, 1, 0, 0
     1, 1, 1, 1
     1, 1, 1, 1
     1, 1, 1, 0
     */
    vector<vector<int> > matrix(4, vector<int>(4, 1));
    matrix[0][3]=0;
    matrix[0][2]=0;
    matrix[3][3]=0;
    setZeroes(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
