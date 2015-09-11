/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include "header.h"

int minPathSum(vector<vector<int> >& grid) {

}

int main(){
//    int arr[3][3] = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
    vector<vector<int> > grid = {
        {1, 2},
        {1, 1}
    };
//    vector<vector<int> > grid = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
    int res = minPathSum(grid);
    cout<<res<<endl;
    return 0;
}
