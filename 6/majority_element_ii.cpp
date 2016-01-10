/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/

#include "header.h"

vector<int> majorityElement(vector<int>& nums){
}

int main(){
    //int arr[] = {5, 2, 4, 4, 4, 4, 5, 5, 5};
    //int arr[] = {1,2,3,4,4,4};
    int arr[] = {0, -1, 2, -1};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> res = majorityElement(v_arr);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}