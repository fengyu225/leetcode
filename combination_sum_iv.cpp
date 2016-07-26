/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:
nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/

#include "header.h"

int combinationSum4(vector<int>& nums, int target) {
    int sz = nums.size();
    if(sz == 0 || target == 0 || target<(*min(nums.begin(), nums.end()))) return 0;
    vector<vector<int> > arr(2, vector<int>(target+1, 0));
    int res = 0;
    for(int n : nums){ 
        if(n<=target) arr[1][n] = 1;
        if(n == target) res++;
    }
    for(int i=2; i<=target; i++){ //length is i
        for(int j=1; j<=target; j++){ //curr sum is j
            arr[i%2][j] = 0;
            for(int k : nums){ //last element is k
                if(j<k) continue;
                arr[i%2][j] += arr[(i-1)%2][j-k];
            } 
            if(j == target) res += arr[i%2][target]; 
        }
    }
    return res;
}

int main(){
//    vector<int> nums = {1, 2, 3};
//    cout<<combinationSum4(nums, 4)<<endl;
//    vector<int> nums = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
//    cout<<combinationSum4(nums, 10)<<endl;
    vector<int> nums = {3, 33, 333};
    cout<<combinationSum4(nums, 10000)<<endl;
    return 0;
}
