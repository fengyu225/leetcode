#include "header.h"

//1, 2, 3, 4

void search(int n, int k, int curr, vector<int>& combination, vector<vector<int> >& res){
    if(combination.size() == k){
        res.push_back(combination);
        return;
    }
    if(curr > n) return;
    combination.push_back(curr);
    search(n,k,curr+1,combination,res);
    combination.pop_back();
    search(n,k,curr+1,combination,res);
}

vector<vector<int> > combine(int n, int k) {
    vector<int> combination;
    vector<vector<int> > res;
    if(n==0 || k==0) return res;
    search(n,k,1,combination,res);
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
