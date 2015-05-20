/*
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

#include "header.h"

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > res;
    int sz = num.size();
    if(sz<4) return res;
    sort(num.begin(), num.end());
    for(int i=0; i+3<sz; i++){
        if(i!=0 && num[i] == num[i-1]) continue;
        for(int j=i+1; j+2<sz; j++){
            if(j!=i+1 && num[j] == num[j-1]) continue;
            int x = target-num[i]-num[j];
            int l=j+1, r=sz-1;
            while(l<r){
                if(num[l]+num[r] == x){
                    vector<int> t;
                    t.push_back(num[i]);
                    t.push_back(num[j]);
                    t.push_back(num[l]);
                    t.push_back(num[r]);
                    res.push_back(t);
                    l++;
                    while(l<r && num[l] == num[l-1]) l++;
                    r--;
                    while(l<r && num[r] == num[r+1]) r--;
                }
                else if(num[l]+num[r]<x) l++;
                else r--;
            }
        }
    }
    return res;
}

int main(){
    //int arr[] = {1, 0, -1, 0, -2, 2};
    int arr[] = {0, 0, 0, 0};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = fourSum(num,0);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size();j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
