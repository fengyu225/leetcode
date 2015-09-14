#include "header.h"

int largestRectangleArea(vector<int>& height) {

}

int main(){
//    int height[] = {6, 2, 5, 4, 5, 1, 6};
    int height[] = {2,4};
    vector<int> h_v(height,height+sizeof(height)/sizeof(height[0]));
    printf("%d\n", largestRectangleArea(h_v));
    return 0;
}
