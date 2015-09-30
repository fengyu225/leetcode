/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include "header.h"

int maxProfit(int k, vector<int>& prices){
    int sz = prices.size();
    if(sz == 0 || k == 0) return 0;

}

int main(){
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout<<maxProfit(2, prices)<<endl;
    return 0;
}