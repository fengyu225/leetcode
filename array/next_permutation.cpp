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

void nextPermutation(vector<int>& nums) {
    int sz = nums.size();

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