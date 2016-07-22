/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:

Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2

The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
*/

#include "header.h"

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int r = matrix.size();
    if(r == 0) return 0;
    int c = matrix[0].size();
    if(c == 0) return 0;
    vector<vector<int> > sums(r, vector<int>(c, 0));
    for(int i=0; i<r; i++){
        sums[i][0] = matrix[i][0];
        for(int j = 1; j<c; j++) sums[i][j] = sums[i][j-1]+matrix[i][j];
    }
    int res = INT_MIN;
    for(int _l = 0; _l<c; _l++){
        for(int _r = _l; _r<c; _r++){
            set<int> s;
            int last = 0;
            for(int i=0; i<r; i++){
                int curr = last+(sums[i][_r] - (_l>=1?sums[i][_l-1]:0));
                if(curr<=k) res = max(res, curr);
                auto iter = s.lower_bound(curr-k);
                if(iter != s.end()) res = max(res, curr-*iter);
                s.insert(curr);
                last = curr;
            }
        }
    } 
    return res;
}

int main(){
    vector<vector<int> > matrix = {
        {5, -4, -3, 4},
        {-3, -4, 4, 5},
        {5, 1, 5, -4}
    };
    cout<<maxSumSubmatrix(matrix, 9)<<endl;
    return 0;
}
