/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include "header.h"

/* using search
void search(vector<int>& nums, int curr, vector<int>& v, vector<vector<int> >& res){
    if(curr ==  nums.size()){
        res.push_back(v);
        return;
    }
    v.push_back(nums[curr]);
    search(nums, curr+1, v, res);
    v.pop_back();
    search(nums, curr+1, v, res);
}

vector<vector<int> > subsets(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    vector<int> v;
    search(nums, 0, v, res);
    return res;
}
*/

vector<vector<int> > subsets(vector<int>& nums){
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    int l = pow(2,sz);
    vector<vector<int> > res(l, vector<int>());
    for(int i=0; i<l; i++)
        for(int j=0;j<32;j++)
            if((i>>j)&1) res[i].push_back(nums[j]);
    return res;
}

int main(){
    int arr[] = {1, 2, 3};
    vector<int> S(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = subsets(S);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
