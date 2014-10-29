#include "header.h"

//http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
//http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

void find_left(vector<int>& h, vector<int>& left){
    stack<int> stack;
    h.push_back(0);
    for(int i=0; i<h.size(); i++){
        if(stack.empty() || h[stack.top()]<h[i]){
            stack.push(i);
            continue;
        }
        while(!stack.empty() && h[stack.top()]>=h[i]){
            int x = stack.top();
            stack.pop();
            left[x] = stack.empty()?h[x]*(x+1):h[x]*(x-stack.top());
        }
        stack.push(i);
    }
//    for(int i=0; i<left.size(); i++)
//        cout<<left[i]<<" ";
//    cout<<endl;
    h.pop_back();
}

int largestRectangleArea(vector<int> &h) {   
    vector<int> left(h.size(),0);
    vector<int> right(h.size(),0);
    find_left(h,left);
    std::reverse(h.begin(), h.end());
    find_left(h,right);
    std::reverse(right.begin(), right.end());
    std::reverse(h.begin(), h.end());
    int res = 0;
    for(int i=0; i<h.size(); i++)
        res = std::max(res,(left[i]+right[i]-h[i]));
    return res;
}

int main(){
    //int height[] = {6, 2, 5, 4, 5, 1, 6};
    int height[] = {2,4};
    vector<int> h_v(height,height+sizeof(height)/sizeof(height[0]));
    printf("%d\n", largestRectangleArea(h_v));
    return 0;
}
