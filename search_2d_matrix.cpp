#include "header.h"

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    return false;
}

int main(){
    vector<vector<int> > matrix;
    int arr[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23,30,34,50}
    };
    for(int i=0; i<3; i++){
        vector<int> v(arr[i], arr[i]+sizeof(arr[i])/sizeof(arr[i][0]));
        matrix.push_back(v);
    }
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    bool res = searchMatrix(matrix,3);
    printf("%s\n", res?"true":"false");
    return 0;
}
