/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!

Example:

n = 10, I pick 6.

Return 6.
*/

#include "header.h"

int guess(int n){
    if(n>6) return -1;
    else if(n<6) return 1;
    else return 0;
}

int guessNumber(int n) {
    int l = 1, r = n;
    while(l+1<r){
        int m = l+(r-l)/2;
        int temp = guess(m);
        if(temp == 0) return m;
        else if(temp== -1) r=m-1;
        else l=m+1;
    }
    return guess(l) == 0?l:r;
}

int main(){
    cout<<guessNumber(6)<<endl;
    return 0;
}
