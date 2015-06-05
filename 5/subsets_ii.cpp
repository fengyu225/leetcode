/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include "header.h"

void search(vector<int>& nums, int curr, vector<int>& temp, vector<vector<int> >& res){
    if(curr == nums.size()){
        res.push_back(temp);
        return;
    }
    int t = curr+1;
    while(t<nums.size() && nums[t] == nums[curr]) t++;
    vector<int> x = temp;
    search(nums, t, temp, res);
    for(int i=0; i<t-curr; i++){
        temp.push_back(nums[curr]);
        search(nums, t, temp, res);
    }
    temp = x;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<int> v;
    vector<vector<int> > res;
    if(nums.size() == 0) return res;
    search(nums, 0, v, res);
    return res;
}

int main(){
    int s_arr[] = {1, 2, 2};
    vector<int> S(s_arr,s_arr+sizeof(s_arr)/sizeof(s_arr[0]));
    vector<vector<int> > res = subsetsWithDup(S);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
