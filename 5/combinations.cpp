/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include "header.h"

//1, 2, 3, 4

void search(int n, int k, int curr, vector<int>& v, vector<vector<int> >& res){
    if(v.size() == k){res.push_back(v);return;}
    if(curr > n) return;
    v.push_back(curr);
    search(n, k, curr+1, v, res);
    v.pop_back();
    search(n,k,curr+1,v,res);
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > res;
    if(k == 0 || n<k) return res;
    vector<int> v;
    search(n, k, 1, v, res);
    return res;
}

int main(){
    vector<vector<int> > res = combine(4,2);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
