/*
Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:
Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]

Expalanation:
Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
*/

#include "header.h"

vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    if(length == 0) return vector<int>();
    vector<int> res(length, 0);
    for(auto v : updates){
        res[v[0]] += v[2];
        if(v[1]+1<length) res[v[1]+1] -= v[2];
    }
    int curr = res[0];
    for(int i=1; i<length; i++){
        res[i] += curr;
        curr = res[i];
    }
    return res;
}

int main(){
    vector<vector<int> > updates = {
        {1, 3, 2},
        {2, 4, 3},
        {0, 2, -2}
    };
    vector<int> res = getModifiedArray(5, updates);
    print_vector<int>(res);
    return 0;
}
