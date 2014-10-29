/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 Find the minimum element.

 */

#include "header.h"

int findMin(vector<int> &num) {
    if(num.size() == 1) return num[0];
    int l = 0, r = num.size()-1;
    while(l+1<r){
        int m = (l+r)/2;
        if(num[l] == num[r])
            l++;
        else if(num[l]<num[r])
            return num[l];
        else{
            if(num[m]>=num[l])
                l = m;
            else
                r = m;
        }
    }
    return num[l]<num[r]?num[l]:num[r];
}

int main(){
    //int arr[] = {4, 4, 5, 6, 7, 0, 1, 2, 4};
    int arr[] = {10, 1, 10, 10, 10};
//    int arr[] = {3, 3, 1, 3};
//    int arr[] = {1, 1, 2, 2, 2, 3, 3, 3};
    vector<int> num(arr, arr+sizeof(arr)/sizeof(int));
    cout<<findMin(num)<<endl;
    return 0;
}
