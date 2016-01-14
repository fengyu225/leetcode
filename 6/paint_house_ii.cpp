/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

#include "header.h"

void update(int& small, int& second_small, int idx, vector<int>& arr){
    if(small == -1 || arr[small]>arr[idx]){
        second_small = small;
        small = idx;
    }
    else if(second_small == -1 || arr[second_small]>arr[idx])
        second_small = idx;
}

int minCostII(vector<vector<int> >& costs) {
    if(costs.size()==0 || costs[0].size()==0) return 0;
    int n = costs.size(), k = costs[0].size();
    vector<vector<int> > arr(n, vector<int>(k,0));
    int small = -1, second_small = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(i == 0) arr[i][j] = costs[i][j];
            else arr[i][j] = (j==small?arr[i-1][second_small]:arr[i-1][small])+costs[i][j];
        }
        small = -1, second_small = -1;
        for(int j=0; j<k; j++) update(small, second_small, j, arr[i]);
    }
    return arr[n-1][small];
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
    vector<vector<int> > costs = {
        {1, 5, 3},
        {2, 9, 4}
    };
    cout<<minCostII(costs)<<endl;
    return 0;
}