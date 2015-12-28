/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

#include "header.h"

vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
    vector<vector<int> > res;
    return res;
}

int main(){
    vector<vector<int> > A = {
        {1, 0, 0},
        {-1, 0, 3}
    };
    vector<vector<int> > B = {
        {7, 0, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    vector<vector<int> > res = multiply(A, B);
    for(auto v : res) print_vector<int>(v);
    return 0;
}