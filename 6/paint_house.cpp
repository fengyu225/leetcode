/*
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
*/

#include "header.h"

int minCost(vector<vector<int> >& costs){
    if(costs.size() == 0 || costs[0].size() == 0) return 0;
    int h_cnt = costs.size();
    vector<vector<int> > arr(h_cnt, vector<int>(3, 0));
    for(int i=0; i<h_cnt; i++){
        arr[i][0] = costs[i][0]+min(i==0?0:arr[i-1][1], i==0?0:arr[i-1][2]);
        arr[i][1] = costs[i][1]+min(i==0?0:arr[i-1][0], i==0?0:arr[i-1][2]);
        arr[i][2] = costs[i][2]+min(i==0?0:arr[i-1][0], i==0?0:arr[i-1][1]);
    }
    return min(arr[h_cnt-1][0], min(arr[h_cnt-1][1], arr[h_cnt-1][2]));
}

int main(){
    vector<int> costs0 = {1, 2, 3};
    vector<int> costs1 = {4, 5, 6};
    vector<int> costs2 = {7, 8, 9};
    vector<vector<int> > costs;
    costs.push_back(costs0);
    costs.push_back(costs1);
    costs.push_back(costs2);
    cout<<minCost(costs)<<endl;
    return 0;
}