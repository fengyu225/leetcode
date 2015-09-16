/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

#include "header.h"

int maxProduct(vector<int>& nums) {
    int sz = nums.size();
    pair<int,int>* arr = new pair<int,int>[sz];
    arr[0].first = nums[0]<0?nums[0]:nums[0] == 0?0:1;
    arr[0].second = nums[0]>0?nums[0]:nums[0] == 0?0:1;
    int res = nums[0];
    for(int i=1; i<sz; i++){
        if(nums[i] == 0){
            arr[i].first = arr[i].second = 0;
            res = max(res, arr[i].second);
            continue;
        }
        if(nums[i]>=0){
            arr[i].first = arr[i-1].first<0?arr[i-1].first*nums[i]:1;
            arr[i].second = arr[i-1].second>0?arr[i-1].second*nums[i]:nums[i];
        } 
        else{
            arr[i].first = arr[i-1].second>0?arr[i-1].second*nums[i]:nums[i];
            arr[i].second = arr[i-1].first<=0?arr[i-1].first*nums[i]:1;
        }
        res = max(res, arr[i].second);
    }
    return res;
}

int main(){
//    int arr[] = {2, 3, -2, 4};
    int arr[] = {-2, 0, -1};
//    int arr[] = {0,2};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<maxProduct(v)<<endl;
    return 0;
}
