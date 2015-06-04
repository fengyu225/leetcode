#include "header.h"

//http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
//http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

void find_left(vector<int>& height, vector<int>& v){
    if(height.size() == 0) return;
    stack<int> s;
    height.push_back(0);
    for(int i=0; i<height.size(); i++){
        if(s.empty() || height[s.top()]<height[i]){
            s.push(i);
            continue;
        }
        while(!s.empty() && height[s.top()]>=height[i]){
            int x = s.top();
            s.pop();
            v[x] = s.empty()?height[x]*(x+1):height[x]*(x-s.top());
        }
        s.push(i);
    }
    height.pop_back();
}

int largestRectangleArea(vector<int>& height){
    vector<int> left(height.size(), 0);
    vector<int> right(height.size(), 0);
    find_left(height, left);
    reverse(height.begin(), height.end());
    find_left(height, right);
    reverse(right.begin(), right.end());
    reverse(height.begin(), height.end());
    int res = 0;
    for(int i=0; i<left.size(); i++)
        res = max(res, left[i]+right[i]-height[i]);
    return res;
}

int main(){
//    int height[] = {6, 2, 5, 4, 5, 1, 6};
    int height[] = {2,4};
    vector<int> h_v(height,height+sizeof(height)/sizeof(height[0]));
    printf("%d\n", largestRectangleArea(h_v));
    return 0;
}
