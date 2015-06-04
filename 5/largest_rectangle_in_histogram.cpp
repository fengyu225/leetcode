#include "header.h"

//http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
//http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

void find_rec(vector<int>& height, vector<int>& v){

}

int largestRectangleArea(vector<int>& height){
    vector<int> right;
    find_rec(height, right);
    return 0;
}

int main(){
    int height[] = {6, 2, 5, 4, 5, 1, 6};
//    int height[] = {2,4};
    vector<int> h_v(height,height+sizeof(height)/sizeof(height[0]));
    printf("%d\n", largestRectangleArea(h_v));
    return 0;
}
