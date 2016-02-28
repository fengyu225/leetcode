/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

#include "header.h"

//void swap(vector<int>& nums, int i, int j){
//    int temp = nums[i];
//    nums[i] = nums[j];
//    nums[j] = temp;
//}
//
//bool find(vector<int>& nums, int i, int j){
//    for(int x=i; x<j; x++)
//        if(nums[x] == nums[j]) return true;
//    return false;
//}
//
//void search(vector<int>& nums, int curr, vector<vector<int> >& res){
//    if(curr == nums.size()){
//        res.push_back(nums);
//        return;
//    }
//    for(int i=curr; i<nums.size(); i++){
//        if(i!=curr && find(nums, curr, i)) continue;
//        swap(nums, i, curr);
//        search(nums, curr+1, res);
//        swap(nums, i, curr);
//    }
//}
//
//vector<vector<int> > permuteUnique(vector<int>& nums){
//    vector<vector<int> > res;
//    if(nums.size() == 0) return res;
//    sort(nums.begin(), nums.end());
//    search(nums, 0, res);
//    return res;
//}

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
    //int arr[] = {1, 1, 2};
    //int arr[] = {1, 2, 3};
//    int arr[] = {1, 2, 1, 2};
    int arr[] = {-1,2,0,-1,1,0,1};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = permuteUnique(num);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
