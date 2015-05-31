/*
N-Queens II

Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.
*/

#include "header.h"

bool is_valid(vector<int>& arr, int k){
    for(int i=0; i<k; i++){
        if((arr[i] == arr[k]) || abs(arr[i]-arr[k])==k-i)
            return false;
    }
    return true;
}

void solve(vector<int>& arr, int curr, int n, int& count){
    if(curr == n){
        count++;
        return;
    }
    for(int i=0;i<n; i++){
        arr[curr] = i;
        if(is_valid(arr,curr)) solve(arr, curr+1, n, count);
    }
}

int totalNQueens(int n){
    if(n == 0) return 0;    
    vector<int> arr(n, -1);
    int count = 0;
    solve(arr, 0, n, count);
    return count; 
}

int main(){
    cout<<totalNQueens(5)<<endl;
    return 0;
}
