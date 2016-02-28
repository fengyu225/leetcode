/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

#include "header.h"

void search(int curr, int sz, vector<int>& nums, vector<vector<int> >& res){
    if(curr == sz){
        res.push_back(nums);
        return;
    }
    unordered_set<int> st;
    for(int i=curr; i<sz; i++){
        if(i>curr && st.find(nums[i]) != st.end()) continue;
        st.insert(nums[i]);
        swap(nums[i], nums[curr]);
        search(curr+1, sz, nums, res);
        swap(nums[i], nums[curr]);
    } 
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
    vector<vector<int> > res;
    int sz = nums.size();
    if(sz == 0) return res;
    sort(nums.begin(), nums.end());
    search(0, sz, nums, res);
    return res;
}

int main(){
    vector<int> arr = {1, 1, 2};
    //int arr[] = {1, 2, 3};
//    int arr[] = {1, 2, 1, 2};
//    vector<int> arr = {0, 1, 0, 0, 9};
    vector<vector<int> > res = permuteUnique(arr);
    for(auto i:res) print_vector<int>(i);
    return 0;
}
