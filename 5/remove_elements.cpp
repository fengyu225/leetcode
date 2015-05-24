#include "header.h"

int removeElement(vector<int>& nums, int val) {
    int sz = nums.size();
    if(sz==0) return 0;
    int curr_tail = -1, curr = 0;
    while(curr<sz){
        if(nums[curr] == val){
            curr++;
            continue;
        }
        nums[++curr_tail] = nums[curr++];
    }
    return curr_tail+1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 3, 6, 7};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    int len = removeElement(v, 3);
    for(int i=0; i<len; i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}