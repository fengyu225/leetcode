/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

#include "header.h"

using namespace std;

int minimumTotal(vector<vector<int> >& triangle) {
    int r = triangle.size();
    if(r == 1) return triangle[0][0];
    int sz = triangle.back().size();
    vector<int> curr(sz, 0);
    vector<int> next(sz, 0);
    curr[0] = triangle[0][0];
    vector<int> arr[2] = {curr, next};
    int x = 1;
    int res = INT_MAX;
    for(int i=1; i<r; i++){
        for(int j=0; j<=i; j++){
            int val;
            if(j == 0) val = arr[(x-1)%2][j];
            else if(j == i) val = arr[(x-1)%2][i-1];
            else val = min(arr[(x-1)%2][j-1], arr[(x-1)%2][j]);
            arr[x%2][j] = val+triangle[i][j];
            if(i == r-1) res = min(res, arr[x%2][j]);
        }
        x++;
    }
    return res;
}

int main(){
    vector<vector<int> > triangle = {
        {2},
        {3,4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    cout<<minimumTotal(triangle)<<endl;
    return 0;
}
