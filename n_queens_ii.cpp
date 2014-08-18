#include "header.h"

bool is_valid(vector<int>& arr, int k){
    for(int i=0; i<k; i++){
        if((arr[i] == arr[k]) || abs(arr[i]-arr[k])==k-i)
            return false;
    }
    return true;
}


void count(vector<int>& arr, int k, int n, int& res){
    if(k==n){
        res++;
        return;
    }
    for(int i=0; i<n; i++){
        arr[k] = i;
        if(is_valid(arr,k))
            count(arr,k+1,n,res);
    }
}

int totalNQueens(int n) {
    vector<int> arr(n,-1);
    int res = 0;
    count(arr,0, n, res);
    return res;
}

int main(){
    cout<<totalNQueens(5)<<endl;
    return 0;
}
