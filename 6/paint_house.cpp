/*
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
*/

#include "header.h"

int minCost(vector<vector<int> >& costs){
    int t_house = costs.size();
    if(t_house == 0) return 0;
    vector<vector<int> > arr(t_house, vector<int>(3, INT_MAX));
    for(int i=0; i<t_house; i++){
        for(int j=0; j<3; j++){
            if(i == 0) arr[i][j] = costs[i][j];
            else{
                arr[i][j] = min(arr[i-1][(j+1)%3], arr[i-1][(j+2)%3])+costs[i][j]; 
            }
        }
    }
    return min(min(arr[t_house-1][0], arr[t_house-1][1]), arr[t_house-1][2]);
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