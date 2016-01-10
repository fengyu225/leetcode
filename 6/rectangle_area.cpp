/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

(image url) https://leetcode.com/static/images/problemset/rectangle_area.png

Assume that the total area is never beyond the maximum possible value of int.
*/

#include "header.h"

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
    // rectangle 1: (A,B), (C,D)
    // rectangle 2: (E,F), (G,H)
    long common = 0, area_0 = 0, area_1 = 0;
    int r_x = min(C, G), l_x = max(E, A);
    int t_y = min(D, H), b_y = max(F, B);
    common = (r_x>=l_x?r_x-l_x:0)*(t_y>=b_y?t_y-b_y:0);
    area_0 = (long)((C-A)*(D-B));
    area_1 = (long)((G-E)*(H-F));
    return area_0+area_1-common;
}

int main(){
    cout<<computeArea(-3, 0, 3, 4, 0, -1, 9, 2)<<endl;
    return 0;
}