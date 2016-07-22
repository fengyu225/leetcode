/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include "header.h"

int maxProfit(vector<int>& prices){
    int sz = prices.size();
    if(sz == 0) return 0;
    vector<int> left(sz,0);
    vector<int> right(sz,0);
    int x=prices[0];
    left[0] = 0;
    //buy before and sell at i
    for(int i=1; i<sz; i++){
        x=min(x,prices[i]);
        left[i] = max(left[i-1],prices[i]-x);
    }
    x=prices[sz-1];
    right[sz-1]=0;
    //buy at i and sell after
    for(int i=sz-2;i>=0;i--){
        x=max(x,prices[i]);
        right[i] = max(right[i+1],x-prices[i]);
    }
    int res = 0;
    for(int i=0; i<sz; i++) res=max(res, left[i]+(i==sz-1?0:right[i+1]));
    return res;
}

int main(){
    int prices_arr[] = {3, 2, 6, 5, 0, 3};
    vector<int> prices(prices_arr,prices_arr+sizeof(prices_arr)/sizeof(prices_arr[0]));
    printf("%d\n", maxProfit(prices));
    return 0;
}
