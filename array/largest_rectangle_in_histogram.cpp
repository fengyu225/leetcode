/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

#include "header.h"

/* using stack 
void calc_left(vector<int>& height, vector<int>& left){
    height.push_back(0);
    int sz = height.size();
    stack<int> st;
    for(int i=0; i<sz; i++){
        if(st.empty() || height[st.top()]<height[i]) st.push(i);
        else{
            while(!st.empty() && height[st.top()]>=height[i]){
                int temp = st.top(); 
                st.pop();
                left[temp] = temp-(st.empty()?-1:st.top());
            }
            st.push(i);
        }
    }
    height.pop_back();
}

void calc_right(vector<int>& height, vector<int>& right){
    height.insert(height.begin(), 0);
    int sz = height.size();
    stack<int> st;
    for(int i=sz-1; i>=0; i--){
        if(st.empty() || height[st.top()]<height[i]) st.push(i);
        else{
            while(!st.empty() && height[st.top()]>=height[i]){
                int temp = st.top();
                st.pop();
                right[temp] = (st.empty()?sz:st.top())-temp;
            }
            st.push(i);
        }
    }
    height.erase(height.begin());
    right.erase(right.begin());
}

int largestRectangleArea(vector<int>& height) {
    int sz = height.size();
    vector<int> left(sz, 1);
    vector<int> right(sz+1, 1);
    calc_left(height, left);
    calc_right(height, right);
    int res = 0;
    for(int i=0; i<sz; i++)
        res = max(res, (left[i]+right[i]-1)*height[i]);
    return res;
}
*/

/* using dp */
int largestRectangleArea(vector<int>& height) {
    int sz = height.size();
    vector<int> left(sz, -1); //left[i]: index of first element on the left which is smaller than height[i]
    vector<int> right(sz, sz); //right[i]: index of the first element on the right which is smaller than height[i]
    for(int i=1; i<sz; i++){
        if(height[i-1]<height[i]) left[i] = i-1;
        else{
            int curr = left[i-1];
            while(curr>=0 && height[curr]>=height[i]) curr = left[curr];
            left[i] = curr;
        }
    }
    for(int i=sz-2; i>=0; i--){
        if(height[i+1]<height[i]) right[i] = i+1;
        else{
            int curr = right[i+1];
            while(curr<sz && height[curr]>=height[i]) curr = right[curr];
            right[i] = curr; 
        }
    }
    int res = 0;
    for(int i=0; i<sz; i++)
        res = max(res, (right[i]-left[i]-1)*height[i]);
    return res;
}

int main(){
//    int height[] = {6, 2, 5, 4, 5, 1, 6};
//    int height[] = {2,4};
//    vector<int> h_v(height,height+sizeof(height)/sizeof(height[0]));
//    vector<int> h_v = {2, 1, 5, 6, 2, 3};
    vector<int> h_v = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d\n", largestRectangleArea(h_v));
    return 0;
}
