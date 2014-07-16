#include "header.h"

void setZeroes(vector<vector<int> > &matrix) {
    
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
