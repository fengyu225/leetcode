#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

int minimumTotal(vector<vector<int> >& triangle){
    int m[triangle[triangle.size()-1].size()];
    for(int i=0; i<triangle[triangle.size()-1].size(); i++)
        m[i] = triangle[triangle.size()-1][i];
    for(int i=triangle.size()-2;i>=0;i--){
        for(int j=0; j<triangle[i].size();j++){
            m[j] = m[j]<m[j+1]?m[j]:m[j+1];
            m[j] += triangle[i][j];
        }
    }
    return m[0]; 
}

int main(){
    int arr0[] = {2};
    vector<int> s0(arr0,arr0+sizeof(arr0)/sizeof(int));
    int arr1[] = {3, 4};
    vector<int> s1(arr1,arr1+sizeof(arr1)/sizeof(int));
    int arr2[] = {6, 5, 7};
    vector<int> s2(arr2,arr2+sizeof(arr2)/sizeof(int));
    int arr3[] = {4, 1, 8, 3};
    vector<int> s3(arr3,arr3+sizeof(arr3)/sizeof(int));
    vector<vector<int> > triangle;
    triangle.push_back(s0);
    triangle.push_back(s1);
    triangle.push_back(s2);
    triangle.push_back(s3);
    printf("%d\n", minimumTotal(triangle));
    return 0;
}
