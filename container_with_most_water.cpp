#include "header.h"

/*
 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container. 



*/

//int maxArea(vector<int> &height) {
//    int l=0,r=height.size()-1;
//    int max=-1;
//    while(l<r){
//        
//    }
//    return max;
//}

int maxArea(vector<int> &height) {  
  // Start typing your C/C++ solution below  
  // DO NOT write int main() function  
  int start =0;  
  int end = height.size()-1;  
  int maxV = INT_MIN;  
  while(start<end)  
  {  
    int contain = std::min(height[end], height[start]) * (end-start);  
     maxV = max(maxV, contain);  
     if(height[start]<= height[end])  
     {  
       start++;  
     }  
     else  
     {  
       end--;  
     }  
   }  
   return maxV;  
}  

int main(){
    int arr[] = {9, 8, 7, 6, 5, 7, 10, 13, 9};
    vector<int> height(arr,arr+sizeof(arr)/sizeof(arr[0]));
    int res = maxArea(height);
    printf("%d\n", res);
    return 0;
}
