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

void setZeroes(vector<vector<int> > &matrix) {
    int r = matrix.size(), c = matrix[0].size();
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
