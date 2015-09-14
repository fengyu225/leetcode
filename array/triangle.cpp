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

int minimumTotal(vector<vector<int>>& triangle) {

}

int main(){
    vector<vector<int> > triangle;
    int arr[4][4] = {{2},{3,4},{6,5,7},{4,1,8,3}};
    for(int i=0; i<4; i++)
        triangle.push_back(vector<int>(arr[i],arr[i]+i+1));
    printf("%d\n", minimumTotal(triangle));
    return 0;
}
