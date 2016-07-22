/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

Input:          [1,3,2]
Expected:       [2,1,3]

*/

#include "header.h"

void swap(vector<int>& nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void nextPermutation(vector<int>& nums) {
    int sz = nums.size();
    if(sz < 2) return;
    int x=sz-1;
    while(x>0 && nums[x] <= nums[x-1]) x--;
    if(x == 0) sort(nums.begin(), nums.end());
    else{
        int j=sz-1;
        while(j>=x && nums[j]<=nums[x-1]) j--;
        swap(nums, x-1, j);
        sort(nums.begin()+x, nums.end());
    }
}

int main(){
    int arr[] = {1, 3,2};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    nextPermutation(v);
    for(int i=0; i<v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}
