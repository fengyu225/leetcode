/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

#include "header.h"

int maxProfit(vector<int>& prices) {

}

int main(){
    //int prices_arr[] = {0, 1, 2, 3};
    int prices_arr[] = {1,2,4};
    vector<int> prices(prices_arr,prices_arr+sizeof(prices_arr)/sizeof(prices_arr[0]));
    printf("%d\n", maxProfit(prices));
    return 0;
}
