#include "header.h"

void setZeroes(vector<vector<int> > &matrix) {
    bool row_sz = false;
    bool col_sz = false;
    for(int i=0; i<matrix.size(); i++)
        if(matrix[i][0] == 0){
            col_sz = true;
            break;
        }
    for(int i=0; i<matrix[0].size(); i++)
        if(matrix[0][i] == 0){
            row_sz = true;
            break;
        }
    for(int row=1; row<matrix.size(); row++){
        for(int col=0; col<matrix[row].size(); col++){
            if(matrix[row][col] == 0){
                matrix[row][0] = 0;
                continue;
            }
        }
    }
    for(int col=1; col<matrix[0].size(); col++){
        for(int row=0; row<matrix.size(); row++){
            if(matrix[row][col] == 0){
                matrix[0][col] = 0;
                continue;
            }
        }
    }
    for(int row=1; row<matrix.size(); row++)
        if(matrix[row][0] == 0){
            for(int col=1; col<matrix[row].size(); col++)
                matrix[row][col]=0;
        }
    for(int col=1; col<matrix[0].size(); col++)
        if(matrix[0][col] == 0){
            for(int row=1;row<matrix.size();row++)
                matrix[row][col]=0;
        }
    if(row_sz){
        for(int i=0; i<matrix[0].size(); i++)
            matrix[0][i] = 0;
    }
    if(col_sz){
        for(int i=0; i<matrix.size(); i++)
            matrix[i][0] = 0;
    }
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
