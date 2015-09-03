/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include "header.h"

int trap(vector<int>& height) {

}

int main(){
    int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> arr(A,A+sizeof(A)/sizeof(A[0]));
    cout<<trap(arr)<<endl;
    return 0;
}
