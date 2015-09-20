/*Given an array of integers, every element appears three times 
 * except for one. Find that single one. 
 */

#include "header.h"

int singleNumber(vector<int>& nums){
    int sz = nums.size();
    int res = 0;
    for(int i=0; i<32; i++){
        int count = 0;
        for(int j = 0; j<sz; j++)
            if((nums[j]>>i) & 1) count++;
        if(count%3 == 1) res |= (1<<i);
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
