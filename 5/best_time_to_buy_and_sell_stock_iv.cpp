/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include "header.h"

int maxProfit(int k, vector<int>& prices){
    if(k == 0) return 0;
    int sz = prices.size();
    if(sz < 2) return 0;
    int local[k+1][sz];
    int global[k+1][sz];
    memset(local, 0, sizeof(local));
    memset(global, 0, sizeof(global));
    for(int i=1; i<sz; i++){
        int diff = prices[i] - prices[i-1];
        for(int j = 1; j<=k; j++){
            local[j][i] = max(
                    global[j-1][i-1]+max(diff, 0),
                    local[j][i-1]+diff
                    );
            global[j][i] = max(
                    global[j][i-1],
                    local[j][i]
                    );
        }
    }
    return global[k][sz-1];
}

int main(){
    return 0;
}