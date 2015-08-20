/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

#include "header.h"

int minCostII(vector<vector<int> >& costs){
    int n = costs.size();
    if(n == 0) return 0;
    int k = costs[0].size();
    vector<vector<int> > arr(n, vector<int>(k, INT_MAX));
    pair<int,int> min_arr = make_pair(-1, -1); 
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(i == 0) arr[i][j] = costs[i][j]; 
            else
                arr[i][j] = costs[i][j]+(j==min_arr.first?arr[i-1][min_arr.second]:arr[i-1][min_arr.first]);
        } 
        min_arr.first = min_arr.second = -1;
        for(int j=0; j<k; j++){
            if(min_arr.first==-1) min_arr.first = j;
            else if(min_arr.second == -1){
                if(arr[i][j]<arr[i][min_arr.first]){
                    min_arr.second = min_arr.first;
                    min_arr.first = j;
                }
                else min_arr.second = j;
            }
            else{
                if(arr[i][j]<arr[i][min_arr.first]){
                    min_arr.second = min_arr.first;
                    min_arr.first = j;
                }
                else if(arr[i][j]<arr[i][min_arr.second]) min_arr.second = j;
            }
        }
    }
    return arr[n-1][min_arr.first]; 
}

//int minCostII(vector<vector<int> >& costs){
//    //O(n*k*lg(k))
//    int n = costs.size();
//    if(n == 0) return 0;
//    int k = costs[0].size();
//    vector<vector<int> > arr(n, vector<int>(k, INT_MAX));
//    for(int i=0; i<n; i++){
//        multiset<int> q;
//        if(i != 0){
//            for(int j=0; j<k; j++) q.insert(arr[i-1][j]);
//        }
//        for(int j=0; j<k; j++){
//            if(i == 0) arr[i][j] = costs[i][j];
//            else{
//                q.erase(q.find(arr[i-1][j]));
//                arr[i][j] = *q.begin()+costs[i][j];
//                q.insert(arr[i-1][j]);
//            }
//        }
//    }
//    int res = INT_MAX;
//    for(int i=0; i<k; i++)
//        res = min(res, arr[n-1][i]);
//    return res;
//}

int main(){

    vector<vector<int> > costs = {
        {3,14,12,2,20,16,12,2},
        {9,6,9,8,2,9,20,18},
        {20,2,20,4,5,12,11,11},
        {16,3,7,5,15,2,2,4},
        {17,3,11,1,9,5,7,11}
    };
//    vector<vector<int> > costs = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
    cout<<minCostII(costs)<<endl;
    return 0;
}