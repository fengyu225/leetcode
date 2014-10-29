#include "header.h"

/*
 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container. 



*/


int maxArea(vector<int> &height){  
    int sz = height.size();
    if(sz == 0) return 0;
    int l = 0, r = sz-1;
    int res = 0;
    while(l<r){
        res = std::max(res,(r-l)*std::min(height[r], height[l]));
        if(height[l]<=height[r])
            l++;
        else
            r--;
    }
    return res;
}  

int main(){
    int arr[] = {9, 8, 7, 6, 5, 7, 10, 13, 9};
    vector<int> height(arr,arr+sizeof(arr)/sizeof(arr[0]));
    int res = maxArea(height);
    printf("%d\n", res);
    return 0;
}
