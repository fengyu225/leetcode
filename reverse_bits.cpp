/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
*/

#include "header.h"

uint32_t reverseBits(uint32_t n){
    uint32_t res = 0;
    int l = 31, r = 0;
    while(r<l){
        res |= ((n>>l)&1)<<(31-l);
        res |= ((n>>r)&1)<<(31-r);
        l--;
        r++;
    }
    return res;

//    uint32_t x = n;
//    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
//    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
//    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
//    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
//    return((x >> 16) | (x << 16));
}

int main(){
    cout<<reverseBits(43261596)<<endl;
    //cout<<reverseBits(1)<<endl;
    return 0;
}