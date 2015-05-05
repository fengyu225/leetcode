#include "header.h"

bool isValid(vector<int> A, int r){
    for (int i=0;i<r;i++){
        if ( (A[i]==A[r])||(abs(A[i]-A[r])==(r-i))){
            return false;
        }
    }
    return true;
}

void solve(vector<int>& A, int curr, int n, vector<vector<string> >& res){
    if(curr == n){
        vector<string> v;
        for(int i=0; i<n; i++){
            string s(n, '.');
            s[A[i]] = 'Q';
            v.push_back(s);
        }
        res.push_back(v);
        return;
    }
    for(int i=0; i<n; i++){
        A[curr] = i;
        if(isValid(A,curr))
            solve(A,curr+1,n,res);
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    vector<int> A(n, -1);
    solve(A, 0, n, res);
    return res;
}

int main(){
    vector<vector<string> > res = solveNQueens(8);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%s \n", res[i][j].c_str());
        printf("\n");
    }
    return 0;
}
