#include "header.h"

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > res(n,vector<int>(n,-1));
    int curr=1,l=0,r=n-1,t=0,b=n-1;
    while(curr<=n*n){
        for(int i=l;i<=r;i++)
            res[t][i] = curr++;
        if(curr>n*n) break;
        t++;
        for(int i=t;i<=b;i++)
            res[i][r] = curr++;
        if(curr>n*n) break;
        r--;
        for(int i=r;i>=l;i--)
            res[b][i] = curr++;
        if(curr>n*n) break;
        b--;
        for(int i=b;i>=t;i--)
            res[i][l] = curr++;
        if(curr>n*n) break;
        l++;
    }
    return res;
}


int main(){
    vector<vector<int> > res = generateMatrix(5);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
