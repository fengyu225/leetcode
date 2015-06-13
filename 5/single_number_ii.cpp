/*Given an array of integers, every element appears three times 
 * except for one. Find that single one. 
 */

#include "header.h"

int singleNumber(vector<int>& nums){
    int res = 0;
    for(int i=0; i<32; i++){
        int x=0, temp=1<<i;
        for(int j=0;j<nums.size(); j++) if(nums[j]&temp) x++;
        res |= (((x%3 == 0)?0:1)<<i);
    }
    return res;
}

int main(){
    int A[10] = {2, 2, 2, 3, 3, 3, 4, 4, 4, -5};
    vector<int> arr(A,A+sizeof(A)/sizeof(A[0]));
    int r = singleNumber(arr);
    printf("%d\n", r);
    return 0;
}
