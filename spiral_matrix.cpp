#include "header.h"

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    for(
}

int main(){
    int arr0[] = {1, 2, 3};
    int arr1[] = {4, 5, 6};
    int arr2[] = {7, 8, 9};
    vector<int> v0(arr0, arr0+sizeof(arr0)/sizeof(arr0[0]));
    vector<int> v1(arr1, arr1+sizeof(arr1)/sizeof(arr1[1]));
    vector<int> v2(arr2, arr2+sizeof(arr2)/sizeof(arr2[2]));
    vector<vector<int> > matrix;
    matrix.push_back(v0);
    matrix.push_back(v1);
    matrix.push_back(v2);
    vector<int> res = spiralOrder(matrix);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    return 0;
}
