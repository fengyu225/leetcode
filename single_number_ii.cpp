/*Given an array of integers, every element appears three times 
 * except for one. Find that single one. 
 */

#include<stdlib.h>
#include<stdio.h>

int singleNumber(int A[], int n){
    int result = 0;
    for(int i=0; i<32; i++){
        int bit = 0;
        for(int j=0; j<n; j++){
            bit += (1 & (A[j]>>(32-i-1)));
        }
        result += ((bit%3) & 1)<<(32-i-1);
    }
    return result;
}

int main(){
    int A[10] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5};
    int r = singleNumber(A, sizeof(A)/sizeof(A[0]));
    printf("%d\n", r);
    return 0;
}
