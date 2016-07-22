/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include "header.h"

/* this may overflow */
int climbStairs(int n) {
    int* arr = new int[n+1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2;i<=n;i++){
        arr[i] = arr[i-1]+arr[i-2];
        //cout<<i<<" "<<arr[i]<<endl;
    }
    int res = arr[n];
    delete[] arr;
    return res;
}

int main(){
    cout<<climbStairs(100)<<endl;
    return 0;
}
