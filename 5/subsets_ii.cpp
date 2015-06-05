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

vector<vector<int>> subsetsWithDup(vector<int>& nums){
    
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
