/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include "header.h"

int maxProfit(vector<int>& prices){
}

int main(){
    int prices[] = {5, 1, 2, 3, 4};
    vector<int> prices_v(prices,prices+sizeof(prices)/sizeof(prices[0]));
    printf("%d\n", maxProfit(prices_v));
    return 0;
}
