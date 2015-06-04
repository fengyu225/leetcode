/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

#include "header.h"

int removeDuplicates(vector<int>& nums){
    int sz = nums.size();
    int curr_tail = -1, curr = 0, dup = 0;
    while(curr<sz){
        if(curr_tail==-1 || (nums[curr] == nums[curr_tail] && dup<2) || nums[curr] != nums[curr_tail]){
            nums[++curr_tail] = nums[curr];
            if(nums[curr] == nums[curr_tail-1]) dup++;
            else dup=1;
            curr++;
        }
        else if(nums[curr] == nums[curr_tail]) curr++;
    }
    return curr_tail+1;
}

int main(){
    //int A[] = {1, 1, 1, 2, 2, 3};
    //int A[] = {1, 1, 1, 1, 3, 3};
    int A[] = {0, 0, 0, 1, 2, 2, 4, 4};
    vector<int> nums(A, A+sizeof(A)/sizeof(A[0]));
    int res = removeDuplicates(nums);
    for(int i=0; i<res; i++)
        printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
