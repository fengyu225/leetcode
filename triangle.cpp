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

int minimumTotal(vector<vector<int> >& triangle){
    int sz = triangle.size();
    if(sz == 0) return INT_MAX;
    if(sz == 1) return triangle[0][0];
    vector<int> curr(1,triangle[0][0]);
    vector<int> next;
    vector<int> arr[2] = {curr,next};
    int x = 0;
    int res = INT_MAX;
    for(int i=1; i<sz; i++){
        arr[(x+1)%2].clear();
        for(int j=0;j<=i;j++){
            int l = j==0?INT_MAX:arr[x%2][j-1]+triangle[i][j];
            int r = j==i?INT_MAX:arr[x%2][j]+triangle[i][j];
            arr[(x+1)%2].push_back(min(l,r));
            if(i==sz-1) res=min(res,arr[(x+1)%2][j]);
        }
        x++;
    }
    return res;
}

int main(){
    vector<vector<int> > triangle;
    int arr[4][4] = {{2},{3,4},{6,5,7},{4,1,8,3}};
    for(int i=0; i<4; i++)
        triangle.push_back(vector<int>(arr[i],arr[i]+i+1));
    printf("%d\n", minimumTotal(triangle));
    return 0;
}
