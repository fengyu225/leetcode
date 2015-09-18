/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

#include "header.h"

//[-1,-100,3,99], 3
//[-100,3,99,-1]
//[3,99,-1,-100]

/* method 1 */
//void reverse(vector<int>& nums, int l, int r){
//    while(l<r) swap(nums[l++], nums[r--]);
//}
//
//void rotate(vector<int>& nums, int k) {
//    int sz = nums.size();
//    k = k%sz;
//    if(k == 0) return;
//    reverse(nums, 0, sz-1);
//    reverse(nums, 0, k-1);
//    reverse(nums, k, sz-1);
//}

/* method 2 */
// for 1, 2, 3, 4, 5, 6, 7
// we do this 1->4->7->3->6->2->5
//int rotate_helper(vector<int>& num, int curr, int k){
//    int sz = num.size();
//    int orig = curr, from = curr, to = (curr+k)%sz, res = 0;
//    int temp = num[from];
//    while(to != orig){
//        int x = num[to];
//        num[to] = temp;
//        temp = x;
//        from = to;
//        to = (to+k)%sz;
//        res++;
//    }
//    num[orig] = temp;
//    return res+1;
//}
//
//void rotate(vector<int>& nums, int k) {
//    int sz = nums.size();
//    k = k%sz;
//    if(k == 0) return;
//    int cnt = 0, curr = 0;
//    while(cnt<sz){
//        cnt += rotate_helper(nums, curr, k);
//        curr++;
//    }
//}

/* method 3 (rotate one by one) */
//void rotate_one(vector<int>& nums){
//    int sz = nums.size();
//    int temp = nums[sz-1];
//    for(int i=sz-1; i>0; i--) nums[i] = nums[i-1];
//    nums[0] = temp;
//}
//    
//void rotate(vector<int>& nums, int k) {
//    int sz = nums.size();
//    k = k%sz;
//    for(int i=0; i<k; i++) rotate_one(nums);
//}

/* method 4 */
void rotate(vector<int>& nums, int k) {

}

int main(){
    //int arr[] = {1,2,3,4,5,6,7};
//    int arr[] = {1,2};
    vector<int> nums = {1, 2, 3};
    rotate(nums, 1);
    print_vector<int>(nums);
    return 0;
}