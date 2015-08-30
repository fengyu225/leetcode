/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

#include "header.h"

int find_k(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2, int k){
    int sz1 = r1-l1+1, sz2 = r2-l2+1;
    if(sz1>sz2) return find_k(nums2, l2, r2, num1, l1, r1, k);
    if(sz1 == 0) return nums2[l2+k-1];
    if(k == 1) return min(nums1[l1], nums2[l2]);
    int x = min(k/2, sz1);
    int y = k-x;
    if(nums1[l1+x-1] == nums2[l2+y-1]) return nums1[l1+x-1];
    else if(nums1[l1+x-1]<nums2[l2+y-1]) return find_k(nums1, l1+x, r1, nums2, l2, r2, k-x);
    else return find_k(nums1, l1, r1, nums2, l2+y, r2, k-y);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int sz1 = nums1.size(), sz2 = nums2.size();
    int len = sz1+sz2;
    if(len%2 == 0){
        double a = (double)find_k(nums1, 0, sz1, nums2, 0, sz2, len/2);
        double b = (double)find_k(nums1, 0, sz1, nums2, 0, sz2, len/2+1);
        return (a+b)/2.0;
    }
    return (double)find_k(nums1, 0, sz1, nums2, 0, sz2, len/2+1);
}

int main(){
    vector<int> nums1 = {0, 2, 4, 6, 8};
    vector<int> nums2 = {1, 3, 5};
    cout<<findMedianSortedArrays(nums1, nums2)<<endl;
    return 0;
}