/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include "header.h"

int maxProfit(vector<int>& prices) {
    int sz = prices.size();
    if(sz<2) return 0;
    vector<int> left(sz, 0);
    vector<int> right(sz, 0);
    left[0] = prices[0];
    right[sz-1] = prices[sz-1];
    for(int i=1; i<sz; i++){
        left[i] = min(prices[i], left[i-1]);
        right[sz-1-i] = max(prices[sz-1-i], right[sz-i]);
    }
    int temp = 0, res = 0;
    for(int i=1; i<sz; i++){
        temp = max(temp, prices[i]-left[i]);
        res = max(res, temp+right[i]-prices[i]);
    }
    return res;
}

int main(){
    int prices_arr[] = {3, 2, 6, 5, 0, 3};
    vector<int> prices(prices_arr,prices_arr+sizeof(prices_arr)/sizeof(prices_arr[0]));
    printf("%d\n", maxProfit(prices));
    return 0;
}
