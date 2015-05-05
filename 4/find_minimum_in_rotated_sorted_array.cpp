/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 Find the minimum element.

 You may assume no duplicate exists in the array.
 */

#include "header.h"

int findMin(vector<int> &num) {
    if(num.size() == 1) return num[0];
    int l = 0, r = num.size()-1;
    while(l+1<r){
        int m = (l+r)/2;
        if(num[m]>num[l] && num[m]<num[r] || num[m]<num[l] && num[m]<num[r])
            r=m;
        else
            l=m;
    }
    return num[l]<num[r]?num[l]:num[r];
}

int main(){
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> num(arr, arr+sizeof(arr)/sizeof(int));
    cout<<findMin(num)<<endl;
    return 0;
}
