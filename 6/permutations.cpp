/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include "header.h"

void search(int curr, int sz, vector<int>& nums, vector<vector<int> >& res){
    if(curr == sz){
        res.push_back(nums);
        return;
    }
    for(int i=curr; i<sz; i++){
        swap(nums[i], nums[curr]);
        search(curr+1, sz, nums, res);
        swap(nums[i], nums[curr]);
    }
}

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > res;
    int sz = nums.size();
    if(sz == 0) return res;
    search(0, sz, nums, res);
    return res;
}

int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int> > res = permute(arr);
    for(auto i:res) print_vector<int>(i);
    return 0;
}
