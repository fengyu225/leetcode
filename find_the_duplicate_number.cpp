/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate element must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant extra space.
Your runtime complexity should be less than O(n2).
*/

#include "header.h"

//int findDuplicate(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
//    int sz = nums.size();
//    for(int i=1; i<sz; i++){
//        if(nums[i] == nums[i-1]) return nums[i];
//    }
//}

//int search(vector<int>& nums, int l, int r){
//    //changing array
//    if(l == r) return nums[l];
//    int tail = l, curr = l+1;
//    int min_v = nums[l], max_v = nums[l];
//    while(curr<=r){
//        if(nums[curr]<min_v) min_v = nums[curr];
//        if(nums[curr]>max_v) max_v = nums[curr];
//        if(nums[curr] == nums[l] || curr != r && nums[curr] == nums[r]) return nums[curr];
//        if(nums[curr]<nums[l]) swap(nums[++tail], nums[curr]);
//        curr++;
//    }
//    swap(nums[tail], nums[l]);
//    if(tail == l) return search(nums, l+1, r);
//    if(tail == r) return search(nums, l, r-1);
//    if(nums[tail]-min_v<tail-l) return search(nums, l, tail);
//    else return search(nums, tail, r);
//}
//
//int findDuplicate(vector<int>& nums) {
//    int sz = nums.size();
//    int l = 0, r = sz-1;
//    return search(nums, l, r);
//}

// O(nlogn)
//void search(vector<int>& nums, int& lt, int& gt, int& eq, int m){
//    for(int c:nums){
//        if(c == m) eq++;
//        else if(c<m) lt++;
//        else gt++;
//    }
//}
//
//int findDuplicate(vector<int>& nums) {
//    int n = nums.size();    
//    n-=1;
//    int l = 1, r = n;
//    while(l<r){
//        int m = l+(r-l)/2;
//        int lt = 0, gt=0, eq = 0;
//        search(nums, lt, gt, eq, m);
//        if(eq>1) return m;
//        if(lt>m-1) r=m-1;
//        else l=m+1;
//    }
//    return l;
//}

//int findDuplicate(vector<int>& nums) {
//    print_vector<int>(nums);
//    int n = nums.size()-1;
//    int l = 1, r = n;
//    while(l<r){
//        int m = l+(r-l)/2;
//        int count = 0;
//        for(int i=0; i<n+1; i++){
//            if(nums[i]<=m) count++;
//        }
//        cout<<l<<" "<<" "<<m<<" "<<r<<" : "<<count<<endl;
//        if(count<=m) l=m+1;
//        //if(m-l+1>count) l=m;
//        else r=m;
//    }
//    return nums[l];
//}

//http://www.keithschwarz.com/interesting/code/?dir=find-duplicate
int findDuplicate(vector<int>& nums){
    int sz = nums.size();
    int slow = 0, fast = 0;
    while(1){
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(slow == fast) break;
    }
    fast = 0;
    while(1){
        slow = nums[slow];
        fast = nums[fast];
        if(slow == fast) break;
    }
    return slow;
}

int main(){
//    vector<int> nums = {1, 2, 3, 4, 5, 3};
//    vector<int> nums = {2,2,2,2,2};
    vector<int> nums = {1, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 16, 16, 16, 16, 16, 16, 17, 19};
    cout<<findDuplicate(nums)<<endl;
    return 0;
}