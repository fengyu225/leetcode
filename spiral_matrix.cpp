#include "header.h"

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> res;
    if(matrix.size() == 0) return res;
    int l=0,r=matrix[0].size()-1,t=0,b=matrix.size()-1;
    while(l<=r && t<=b){
        for(int i=l;i<=r;i++)
            res.push_back(matrix[t][i]);
        t++;
        if(t>b) break;
        for(int i=t;i<=b;i++)
            res.push_back(matrix[i][r]);
        r--;
        if(r<l) break;
        for(int i=r;i>=l;i--)
            res.push_back(matrix[b][i]);
        b--;
        if(t>b) break;
        for(int i=b;i>=t;i--)
            res.push_back(matrix[i][l]);
        l++;
        if(r<l) break;
    }
    return res;
}

int main(){
    int arr0[] = {1, 2, 3};
//    int arr0[] = {1, 2, 3};
//    int arr1[] = {4, 5, 6};
//    int arr2[] = {7, 8, 9};
//    int arr3[] = {10, 11, 12};
    vector<int> v0(arr0, arr0+sizeof(arr0)/sizeof(arr0[0]));
//    vector<int> v1(arr1, arr1+sizeof(arr1)/sizeof(arr1[1]));
//    vector<int> v2(arr2, arr2+sizeof(arr2)/sizeof(arr2[2]));
//    vector<int> v3(arr3, arr3+sizeof(arr3)/sizeof(arr3[3]));
    vector<vector<int> > matrix;
    matrix.push_back(v0);
//    matrix.push_back(v1);
//    matrix.push_back(v2);
//    matrix.push_back(v3);
    vector<int> res = spiralOrder(matrix);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
