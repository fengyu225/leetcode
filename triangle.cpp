#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

int minimumTotal(vector<vector<int> >& triangle){

    return 0; 
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
    vector<vector<it> > triangle;
    triangle.push_back(arr0);
    triangle.push_back(arr1);
    triangle.push_back(arr2);
    triangle.push_back(arr3);
    printf("%d\n", minimumTotal(triangle));
    return 0;
}
