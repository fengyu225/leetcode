#include "header.h"

vector<vector<int> > threeSum(vector<int>& num){
    std::sort(num.begin(), num.end());
    vector<vector<int> > res;
    if(num.size()<3) return res;
    for(int i=0; i<num.size()-2; i++){
        if(i>0 && num[i] == num[i-1]) continue;
        int target = -1*num[i];
        int l = i+1,r=num.size()-1;
        while(l<r){
            if(num[l]+num[r] == target){
                vector<int> v;
                v.push_back(num[i]);
                v.push_back(num[l]);
                v.push_back(num[r]);
                res.push_back(v);
                l++;
                r--;
            while(l<r && num[l] == num[l-1]) l++;
            while(l<r && num[r] == num[r+1]) r--;
            }
            else if(num[l]+num[r]<target) l++;
            else r--;
        }
    }
    return res; 
}

int main(){
//    int arr[] = {-1, 0, 1, 2, -1, -4};
    //int arr[] = {0, 0, 0, 0, 0};
    int arr[] = {-1, -1};
//    int arr[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> num(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > r = threeSum(num);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
