#include "header.h"

bool search(vector<int> v, int target){
    int l=0,r=v.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        if(v[m] == target) return true;
        if(v[m]<target)
            l=m+1;
        else
            r=m-1;
    }
    return false;
}

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if(matrix.size() == 0) return false;
    if(target<matrix[0][0] || target>matrix[matrix.size()-1][matrix[0].size()-1]) return false;
    int l=0,r=matrix.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        if(target<matrix[m][0])
            r=m-1;
        else if(target>matrix[m][matrix[0].size()-1])
            l=m+1;
        else
            return search(matrix[m], target);
    }
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
