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

//first solution
//void rotate(vector<int>& nums, int k) {
//    k = k%nums.size();
//    reverse(nums.begin(),nums.end());
//    reverse(nums.begin(), nums.begin()+k);
//    reverse(nums.begin()+k, nums.end());
//}

/* solution 2
 *
Sample [1,2,3,4,5,6,7,8,9] 3    
The replacing process is as follow:
1) 1->4->7->1
2) 2->5->8->2
3) 3->6->9->3
*/
void rotate(vector<int>& nums, int k) {
    int sz = nums.size();

}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
//    int arr[] = {1,2};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
    rotate(nums, 3);
    for(int i=0; i<nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}