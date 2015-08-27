/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

#include "header.h"

void calc_right(vector<int>& height, vector<int>& right){
    height.push_back(0);
    int sz = height.size();
    stack<int> st;
    st.push(0);
    int curr = 1;
    while(curr<sz){
        if(height[curr]>=height[st.top()]) st.push(curr);
        else{
            while(!st.empty() && height[st.top()]>height[curr]){
                right[st.top()] = height[st.top()]*(curr-st.top());
                st.pop();
            } 
            st.push(curr); 
        }
        curr++;
    }
}
    
int largestRectangleArea(vector<int>& height) {
    int sz = height.size(); 
    vector<int> right(sz, 0);
    vector<int> left(sz, 0);
    calc_right(height, right);
    reverse(height.begin(), height.end());
    calc_right(height, left);
    reverse(left.begin(), left.end());
    reverse(height.begin(), height.end());
    for(int i=0; i<sz; i++) cout<<left[i]<<" ";
    cout<<endl;
    return 0;
}

int main(){
    vector<int> height = {2, 1, 5, 6, 2, 3};
    cout<<largestRectangleArea(height)<<endl;
    return 0;
}