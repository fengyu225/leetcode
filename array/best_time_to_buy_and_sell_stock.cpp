/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

#include "header.h"

int maxProfit(vector<int>& prices) {
    int sz = prices.size();
    if(sz < 2) return 0;
    int small = prices[0], res = 0;
    for(int i=1; i<sz; i++){
        small = min(small, prices[i-1]);
        res = max(res, prices[i]-small);
    }
    return res;
}

int main(){
    vector<int> prices = {1,2,4};
//    vector<int> prices = {0, 1, 2, 3};
    printf("%d\n", maxProfit(prices));
    return 0;
}
