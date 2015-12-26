/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

#include "header.h"

//int maxProfit(vector<int>& prices) {
//    int sz = prices.size();
//    vector<int> global(sz+1, 0);
//    vector<int> local(sz+1, 0);
//    for(int i=2; i<=sz; i++){
//        for(int j=0; j<i-1; j++){
//            local[i] = max(local[i], prices[i-1]-prices[j]+(j-1>=0?global[j-1]:0));
//        }
//        global[i] = max(global[i-1], local[i]);
//    }
//    return global[sz];
//}

//https://leetcode.com/discuss/72030/share-my-dp-solution-by-state-machine-thinking
int maxProfit(vector<int>& prices) {
    int sz = prices.size();
    if(sz<=1) return 0;
    vector<int> s0(sz, 0);
    vector<int> s1(sz, 0);
    vector<int> s2(sz, 0);
    s0[0] = 0;
    s1[0] = -1*prices[0];
    s2[0] = 0;
    for(int i=1; i<sz; i++){
        s0[i] = 
    }
}

int main(){
    //vector<int> prices = {1, 2, 3, 0, 2};
    vector<int> prices = {1, 4, 2};
    cout<<maxProfit(prices)<<endl;
    return 0;
}