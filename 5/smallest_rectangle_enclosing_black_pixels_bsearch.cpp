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

bool check(vector<vector<char> >& image, bool horizontal, int m){
    //return true if all 0
    if(horizontal){
        for(int i=0; i<image.size(); i++)
            if(image[i][m] == '1') return false;
        return true;
    } 
    else{
        for(int i=0; i<image[0].size(); i++)
            if(image[m][i] == '1') return false;
        return true;
    }
}   

int search(vector<vector<char> >& image, bool horizontal, bool neg, int x, int y){
    int b = horizontal?y:x;
    int small=neg?b:0, large=neg?(horizontal?image[0].size():image.size())-1:b;
    int l = small, r = large;
    if(small == large) return 0;
    while(l+1<r){
        int m = (l+r)/2;
        if(check(image, horizontal, m)){
            if(neg) r=m-1;
            else l=m+1;
        }
        else{
            if(neg) l=m;
            else r=m;
        }
    }
    int temp = check(image, horizontal, l)?r:check(image, horizontal, r)?l:neg?r:l;
    return neg?(horizontal?image[0].size():image.size())-temp-1:temp;
}

int minArea(vector<vector<char> >& image, int x, int y){
    if(image.size() == 0 || image[0].size() == 0) return 0;
    int a = search(image, true, false, x, y);
    int b = search(image, true, true, x, y);
    int c = search(image, false, false, x, y);
    int d = search(image, false, true, x, y);
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return (image[0].size()-a-b)*(image.size()-c-d);
}

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