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
    if (image.size() == 0 || image[0].size() == 0) {
        return 0;
    }
    int n = image.size();
    int m = image[0].size();
    int lengthX = 0;
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (image[i][j] != '0') {
                lengthX++;
                break;
            };
        }
    }
    int lengthY = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (image[i][j] != '0') {
                lengthY++;
                break;
            }
        }
    }
    return lengthX * lengthY;
}

//void update(int x, int y, int& left, int& right, int& top, int& bottom){
//    left = y<left?y:left;
//    right = y>right?y:right;
//    top = x<top?x:top;
//    bottom = x>bottom?x:bottom;
//}
//
//int minArea(vector<vector<char> >& image, int x, int y){
//    int r = image.size();
//    if(r == 0) return 0;
//    int c = image[0].size();
//    if(c == 0) return 0;
//    int left = c, right=-1, top=r, bottom=-1;
//    for(int i=0; i<r; i++){
//        for(int j=0; j<c; j++){
//            if(image[i][j] == '1')
//            update(i, j, left, right, top, bottom);
//        }
//    }
////    cout<<left<<" "<<right<<" "<<bottom<<" "<<top<<endl;
//    return (right-left+1)*(bottom-top+1);
//}

/*
"000000000000000000000010000000000000000000000000000000000000000000000000000",
"000000000000000000000110000000000000000000000000000000000000000000000000000",
"000000000000000000011100000000000000000000000000000000000000000000000000000",
"000000000000000000111100000000000000000000000000000000000000000000000000000",
"000000000000000100111000000000000010001000000000100000000000000000000000000",
"000000000000011111011000000000000011111100000011110000101000000000000000000",
"000000000000011011111100100000000011111110001111100111111100000000000000000",
"000000000000000001111111110000001111111111011110100111111110000000000000000",
"000000000000000000110011111110000111111100011111110101111100000000000000000",
"000000000000000000000111111111110111111111111111111111111111000000000000000",
"000000000000000000000111111111111111111111111111111111111111000000000000000",
"000000000000000000000111111111111000111000001111111111111011000000000000000",
"000000000000000000011111101111111000111111111110010111111111100000000000000",
"000000000000000000010111111111111111111111100000000111111111011000000000000",
"000000000000000000000111101100100111110000100011100111111111111000000000000",
"000000000000000000000111111111111111110001111111101111111111111100000000000",
"000000000000000000001111111111111111111111101111111111111111111100000000000",
"000000000000000000001000011111111000001000001111111111111111111100000000000"
17
63
*/

int main(){
    vector<vector<char> > image = {
        {'0', '0', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '1', '0', '0'}
    };
    cout<<minArea(image, 0, 2)<<endl;
    return 0;
}