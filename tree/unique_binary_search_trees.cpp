/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include "header.h"

int numTrees(int n) {
    if(n <= 2) return n;
    vector<vector<int> > arr(n+1, vector<int>(n+1, 1));
    for(int len = 2; len<=n; len++){
        for(int start = 1; start+len-1<=n; start++){
            arr[len][start] = 0;
            for(int l_len = 0; l_len<len; l_len++)
                arr[len][start] += arr[l_len][start] * arr[len-l_len-1][start+l_len+1];
            cout<<arr[len][start]<<" ";
        }
        cout<<endl;
    }
    return arr[n][1];
}

int main(){
    cout<<numTrees(3)<<endl;
    return 0;
}