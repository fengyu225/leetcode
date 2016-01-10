/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

#include "header.h"

void search(int k, int n, int curr, int curr_sum, vector<int>& temp, vector<vector<int> >& res){
    int sz = temp.size();
    if(sz == k && curr_sum == n){
        res.push_back(temp);
        return;
    }
    if(sz>k || curr_sum>n || curr>9) return;
    temp.push_back(curr);
    search(k,n,curr+1,curr_sum+curr,temp,res);
    temp.pop_back();
    search(k,n,curr+1,curr_sum,temp,res);
}

vector<vector<int> > combinationSum3(int k, int n){
    vector<vector<int> > res;
    if(k==0 || n==0) return res;
    int curr_sum = 0, curr = 1;
    vector<int> temp;
    search(k, n, curr, curr_sum, temp, res);
    return res;
}

int main(){
    vector<vector<int> > res = combinationSum3(3,9);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}