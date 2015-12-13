/*
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]

and x = 0, y = 2,
Return 6.
*/

#include "header.h"

int minArea(vector<vector<char> >& image, int x, int y){
    return 1;
}

int main(){
    vector<vector<char> > image = {
        {'0', '0', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '1', '0', '0'}
    };
    cout<<minArea(image, 0, 2)<<endl;
    return 0;
}