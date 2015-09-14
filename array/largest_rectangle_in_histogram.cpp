/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

#include "header.h"

void calc_left(vector<int>& height, vector<int>& left){
    height.push_back(0);
    int sz = height.size();
    stack<int> st;
    for(int i=0; i<sz; i++){
        if(st.empty() || height[st.top()]<height[i]) st.push(i);
        else{
            
        }
    }
}

void calc_right(vector<int>& height, vector<int>& right){

}

int largestRectangleArea(vector<int>& height) {
    int sz = height.size();
    vector<int> left(sz, 1);
    vector<int> right(sz, 1);
    calc_left(height, left);
    calc_right(height, right);
    int res = 0;
    for(int i=0; i<sz; i++)
        res = max(res, (left[i]+right[i]-1)*height[i]);
    return res;
}

int main(){
//    int height[] = {6, 2, 5, 4, 5, 1, 6};
//    int height[] = {2,4};
//    vector<int> h_v(height,height+sizeof(height)/sizeof(height[0]));
    vector<int> h_v = {2, 1, 5, 6, 2, 3};
    printf("%d\n", largestRectangleArea(h_v));
    return 0;
}
