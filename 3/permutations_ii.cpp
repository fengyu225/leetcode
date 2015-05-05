#include "header.h"

void swap(vector<int>& num, int i, int j){
    int x = num[i];
    num[i] = num[j];
    num[j] = x;
}

bool noswap(vector<int>& num, int i, int j){
    for(int x=i; x<j; x++)
        if(num[x] == num[j])
            return true;
    return false;
}

void perm(vector<int> num,int k,int n, vector<vector<int> > &res){
    if(k == n){
        res.push_back(num);
        return;
    }
    for(int i=k; i<=n; i++){
        if(noswap(num,k,i)) continue;
        swap(num,i,k);
        perm(num,k+1,n,res);
        swap(num,i,k);
    }
}

vector<vector<int> > permuteUnique(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > res;
    perm(num,0,num.size()-1,res);
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
