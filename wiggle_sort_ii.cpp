/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

#include "header.h"

//void wiggleSort(vector<int>& nums) {
//    //https://leetcode.com/discuss/76965/3-lines-python-with-explanation-proof
//    int sz = nums.size();
//    if(sz<2) return;
//    sort(nums.begin(), nums.end());
//    vector<int> temp;
//    int m = sz%2 == 0?sz/2-1:sz/2;
//    for(int i=m, j=sz-1; i>=0 || j>m; ){
//        if(i>=0) temp.push_back(nums[i--]);  
//        if(j>m) temp.push_back(nums[j--]);  
//    }
//    nums = temp;
//}

//void wiggleSort(vector<int>& nums) {
//    int n = nums.size();
//
//    // Find a median.
//    auto midptr = nums.begin() + n / 2;
//    nth_element(nums.begin(), midptr, nums.end());
//    int mid = *midptr;
//    print_vector<int>(nums);
//
//    // Index-rewiring.
//    #define A(i) nums[(1+2*(i)) % (n|1)]
//
//    for(int i=0; i<n; i++) cout<<A(i)<<" "<<(1+2*(i)) % (n|1)<<", ";
//    cout<<endl;
//
//    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
//    int i = 0, j = 0, k = n - 1;
//    while (j <= k) {
//        if (A(j) > mid)
//            swap(A(i++), A(j++));
//        else if (A(j) < mid)
//            swap(A(j), A(k--));
//        else
//            j++;
//    }
//}

void wiggleSort(vector<int>& nums) {

}

int main(){
    vector<int> nums = {1,3,2,2,2,1,1,3,1,1,2};
    wiggleSort(nums);
    print_vector<int>(nums);
    //vector<int> nums_1 = {1, 5, 1, 1, 6, 4};
    vector<int> nums_1 = {4, 5, 5, 6};
    wiggleSort(nums_1);
    print_vector<int>(nums_1);
    return 0;
}