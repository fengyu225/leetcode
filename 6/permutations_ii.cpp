/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

#include "header.h"

bool find(vector<int>& nums, int i, int j){
    for(int x=i; x<j; x++)
        if(nums[x] == nums[j]) return true;
    return false;
}

void search(vector<int>& nums, int curr, vector<vector<int> >& res){
    if(curr == nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=curr; i<nums.size(); i++){
        if(i>curr && find(nums, curr, i)) continue;
        swap(nums[i],nums[curr]);
        search(nums, curr+1, res);
        swap(nums[i],nums[curr]);
    }
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
    vector<vector<int> > res;
    sort(nums.begin(), nums.end());
    search(nums, 0, res);
    return res;
}

int main(){
    //int arr[] = {1, 1, 2};
    //int arr[] = {1, 2, 3};
//    int arr[] = {1, 2, 1, 2};
    vector<int> arr = {0, 1, 0, 0, 9};
    vector<vector<int> > res = permuteUnique(arr);
    for(auto i:res) print_vector<int>(i);
    return 0;
}
