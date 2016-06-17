/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
*/

#include "header.h"

/*
0 | 1 || 1 2 ||| 1 2 2 3 |||| ...
*/

vector<int> countBits(int num) {
    vector<int> res;
    res.push_back(0);
    int last = 0;
    for(long i=1; i<=num; i++){
        res.push_back(res[last++]+1);
        if((i&(i+1)) == 0) last = 0;
    }
    return res;
}


/* naive way
vector<int> countBits(int num){
    vector<int> res;
    for(int i=0; i<=num; i++){
        int temp = i, c = 0;
        for(;temp;c+=(temp&1), temp>>=1);
        res.push_back(c);
    }
    return res;
}
*/

int main(){
    vector<int> res = countBits(7);
    print_vector<int>(res);
    return 0;
}
