/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include "header.h"

void swap(vector<int>& num, int i, int j){
    int x = num[i];
    num[i] = num[j];
    num[j] = x;
}
void search(vector<int>& nums, int curr, vector<vector<int> >& res){
    if(curr == nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=curr; i<nums.size(); i++){
        swap(nums,i,curr);
        search(nums,curr+1,res);
        swap(nums,i,curr);
    }
}   

vector<vector<int> > permute(vector<int>& nums){
    vector<vector<int> > res;
    int sz = nums.size();
    if(sz == 0) return res;
    search(nums,0,res);
    return res;
}

int main(){
    int arr[] = {1, 2, 3};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = permute(v);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
