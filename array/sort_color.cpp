/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

#include "header.h"

void sortColors(vector<int>& nums) {
    int sz = nums.size();
    int l = -1, r = sz, curr = 0;
    while(curr<r){
        if(nums[curr] == 0) swap(nums[curr++], nums[++l]);
        else if(nums[curr] == 1) curr++;
        else swap(nums[curr], nums[--r]);
    }
}

int main(){
    int A[] = {2, 0, 1, 1, 0, 2, 1};
    //int A[] = {1, 2, 0};
    vector<int> arr(A, A+sizeof(A)/sizeof(A[0]));
    sortColors(arr);
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
