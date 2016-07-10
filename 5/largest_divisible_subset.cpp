/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:
nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)

Example 2:
nums: [1,2,4,8]

Result: [1,2,4,8]
*/

#include "header.h"

vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> res;
    int sz = nums.size();
    if(sz == 0) return res;
    if(sz == 1) return vector<int>(1, nums[0]);
    vector<int> last(sz, -1);
    vector<int> arr(sz, 1);
    sort(nums.begin(), nums.end());
    int largest_end_index = 0;
    for(int i=1; i<sz; i++){
        for(int j=0; j<i; j++){
            if(nums[i]%nums[j] != 0) continue;
            if(arr[j]+1>arr[i]){
                arr[i] = arr[j]+1;
                last[i] = j;
            }
        }
        if(arr[i]>arr[largest_end_index]) largest_end_index = i;
    }
    for(int i=largest_end_index; i != -1; i=last[i])
        res.push_back(nums[i]);
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    //vector<int> nums = {2, 4, 6, 8};
    vector<int> nums = {1, 2, 4, 8};
    vector<int> res = largestDivisibleSubset(nums);
    print_vector<int>(res);
    return 0;
}
