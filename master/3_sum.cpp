#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using std::vector;
using std::sort;

vector<vector<int> > threeSum(vector<int>& num){
    vector<vector<int> > res;
    sort(num.begin(), num.end());
    if(num.size()<3) return res;
    for(int i=0; i<num.size()-2; i++){
        if(i>0 && num[i]==num[i-1]) continue;
        int a = num[i];
        int target = -a;
        int l = i+1, r=num.size()-1;
        while(l<r){
            if(num[l]+num[r] == target){
                vector<int> v_t;
                v_t.push_back(a);
                v_t.push_back(num[l]);
                v_t.push_back(num[r]);
                res.push_back(v_t);
                l++;r--;
                while(l<r && num[l]==num[l-1]) l++;
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
    int arr[] = {-1, -1, -1, 0, 2};
    vector<int> num(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > r = threeSum(num);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
