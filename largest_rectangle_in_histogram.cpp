#include "header.h"

//http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
//http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

int largestRectangleArea(vector<int> &height) {
    if(height.size() == 0) return 0;
    int max = 0;
    stack<int> s;
    for(int i=0; i<height.size(); i++){
        if(s.empty() || s.top()<=height[i]) s.push(height[i]);
        else{
            int x = 1;
            while(!s.empty() && s.top()>height[i]){
                s.pop();
                x++;
            }
            max = max<height[i]*x?height[i]*x:max;
            s.push(height[i]);
        }
    }
    return max;
}

int main(){
    int height[] = {2, 1, 5, 6, 2, 3};
    vector<int> h_v(height,height+sizeof(height)/sizeof(height[0]));
    printf("%d\n", largestRectangleArea(h_v));
    return 0;
}
