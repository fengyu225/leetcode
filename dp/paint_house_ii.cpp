/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

#include "header.h"

int minCostII(vector<vector<int> >& costs) {
    int n = costs.size();
    if(n == 0) return 0;
    int k = costs[0].size();
    if(k<1) return 0;
    int m0 = -1, m1 = -1;
    vector<vector<int> > arr(n, vector<int>(k, 0));
    for(int i=0; i<n; i++){
        for(int j=0;j<k;j++){
            if(i == 0) arr[i][j] = costs[i][j];
            else{
                if(j == m0) arr[i][j] = arr[i-1][m1]+costs[i][j];
                else arr[i][j] = arr[i-1][m0]+costs[i][j];
            }
        }
        m0 = -1; m1 = -1;
        for(int j=0; j<k; j++){
            if(m0 == -1 || arr[i][j]<arr[i][m0]){
                m1 = m0;
                m0 = j;
            }
            else if(m1 == -1 || arr[i][j]<arr[i][m1]) m1 = j;
        }
    }
    return arr[n-1][m0];
}

int main(){
//    vector<vector<int> > costs = {
//        {3,14,12,2,20,16,12,2},
//        {9,6,9,8,2,9,20,18},
//        {20,2,20,4,5,12,11,11},
//        {16,3,7,5,15,2,2,4},
//        {17,3,11,1,9,5,7,11}
//    };
    vector<vector<int> > costs = {
        {15,17,15,20,7,16,6,10,4,20,7,3,4},
        {11,3,9,13,7,12,6,7,5,1,7,18,9}
    };
//    vector<vector<int> > costs = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
    cout<<minCostII(costs)<<endl;
    return 0;
}