/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include "header.h"

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > res(n, vector<int>(n, 0));
    int curr = 1, left = 0, right = n-1, low = 0, high = n-1;
    while(left<=right && low<=high){
        for(int i=left; i<=right; i++) res[low][i] = curr++;
        low++;
        if(low>high) break;
        for(int i=low; i<=high; i++) res[i][right] = curr++;
        right--;
        if(right<left) break;
        for(int i=right; i>=left; i--) res[high][i] = curr++;
        high--;
        if(high<low) break;
        for(int i=high; i>=low; i--) res[i][left] = curr++;
        left++;
    }
    return res;
}

int main(){
    vector<vector<int> > res = generateMatrix(3);
    print_2d_vector<int>(res);
    return 0;
}
