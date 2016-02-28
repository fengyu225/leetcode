/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

#include "header.h"

void update(int& m, int& second_m, vector<vector<int> >& arr, int i, int j){
    if(m == -1) m = j;
    else{
        if(arr[i][m]>arr[i][j]){
            second_m = m;
            m = j;
        }
        else if(second_m == -1 || arr[i][second_m]>arr[i][j])
            second_m = j;
    }
}

int minCostII(vector<vector<int> >& costs) {
    if(costs.size() == 0 || costs[0].size() == 0) return 0;
    int n = costs.size(), k = costs[0].size();
    vector<vector<int> > arr(n, vector<int>(k, 0));
    int m = -1, second_m = -1, last_m = -1, last_second_m = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(i == 0) arr[i][j] = costs[i][j];
            else{
                if(last_m != j) arr[i][j] = costs[i][j]+arr[i-1][last_m];
                else arr[i][j] = costs[i][j]+arr[i-1][last_second_m];
            }
            update(m, second_m, arr, i, j);
        }
        last_m = m;
        last_second_m = second_m;
        m = -1;
        second_m = -1;
    }
    return arr[n-1][last_m];
}

int main(){
//    vector<vector<int> > costs = {
//        {3,14,12,2,20,16,12,2},
//        {9,6,9,8,2,9,20,18},
//        {20,2,20,4,5,12,11,11},
//        {16,3,7,5,15,2,2,4},
//        {17,3,11,1,9,5,7,11}
//    };
//    vector<vector<int> > costs = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
//    vector<vector<int> > costs = {
//        {1, 5, 3},
//        {2, 9, 4}
//    };
    vector<vector<int> > costs = {
        {20,19,11,13,12,16,16,17,15,9,5,18},
        {3,8,15,17,19,8,18,3,11,6,7,12},
        {15,4,11,1,18,2,10,9,3,6,4,15}
    };
    cout<<minCostII(costs)<<endl;
    return 0;
}