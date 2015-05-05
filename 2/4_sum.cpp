#include "header.h"

vector<vector<int> > fourSum(vector<int> &num, int target) {
    std::sort(num.begin(), num.end());
    vector<vector<int> > res;
    if(num.size()<4) return res;
    for(int i=0; i+3<num.size(); i++){
        if(i>0 && num[i] == num[i-1]) continue;
        for(int j=i+1; j+2<num.size(); j++){
            if(j>i+1 && num[j] == num[j-1]) continue;
            int x = target-num[i]-num[j];
            int l = j+1;
            int r=num.size()-1;
            while(l<r){
                if(num[l]+num[r] == x){
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    v.push_back(num[l]);
                    v.push_back(num[r]);
                    res.push_back(v);
                    l++;
                    r--;
                    while(l<r && num[l] == num[l-1]) l++;
                    while(l<r && num[r] == num[r+1]) r--;
                }
                else if(num[l]+num[r]<x)
                    l++;
                else
                    r--;
            }
        }
    }
    return res;
}

int main(){
    int arr[] = {1, 0, -1, 0, -2, 2};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = fourSum(num,0);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size();j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
