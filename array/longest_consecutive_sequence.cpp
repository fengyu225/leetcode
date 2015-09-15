/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include "header.h"

int longestConsecutive(vector<int>& nums) {
    int sz = nums.size();
    unordered_map<int,int> m;
     
}

int main(){
    int arr[] = {100, 4, 200, 1, 3, 2};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    printf("%d\n", longestConsecutive(num));
    return 0;
}
