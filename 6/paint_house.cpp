/*
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
*/

#include "header.h"

int minCost(vector<vector<int> >& costs){
    int sz = costs.size();
    if(sz == 0) return 0;
    int red = costs[0][0], blue = costs[0][1], green = costs[0][2];
    int res = min(min(red, blue), green);
    for(int i=1; i<sz; i++){
        int temp_red = costs[i][0]+min(blue, green);
        int temp_blue = costs[i][1]+min(red, green);
        int temp_green = costs[i][2]+min(red, blue);
        res = min(temp_red, min(temp_blue, temp_green));
        red = temp_red;
        blue = temp_blue;
        green = temp_green;
    }
    return res;
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