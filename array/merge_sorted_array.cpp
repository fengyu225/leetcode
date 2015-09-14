/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

#include "header.h"

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int tail = m+n;
    m-=1;
    n-=1;
    while(m>=0 || n>=0){
        int val;
        if(m < 0 || m >=0 && n>=0 && nums1[m]<nums2[n]){
            val = nums2[n];
            n--;
        }
        else if(n<0 || m>=0 && n>=0 && nums1[m]>=nums2[n]){
            val = nums1[m];
            m--;
        }
        nums1[--tail] = val;
    }
}

int main(){
//    int A[] = {0, 2, 4, 6, 8, -1, -1, -1, -1};
//    int B[] = {1, 3, 5, 7};
//    merge(A,5,B,4);
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 5, 6};
    int sz1 = nums1.size(), sz2 = nums2.size();
    nums1.resize(sz1+sz2);
    merge(nums1, sz1, nums2, sz2);
    print_vector<int>(nums1);
    return 0;
}
