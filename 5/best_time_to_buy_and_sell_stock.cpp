/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

#include "header.h"

int maxProfit(vector<int>& prices){
    int sz = prices.size();
    if(sz == 1) return 0;
    int arr[sz], res=0;
    arr[0] = INT_MAX;
    for(int i=1; i<sz; i++){
        arr[i] = min(arr[i-1],prices[i-1]);
        cout<<prices[i]<<" "<<arr[i]<<endl;
        res = max(res,prices[i]-arr[i]);
    }
    return res;
}

int main(){
    //int prices_arr[] = {0, 1, 2, 3};
    int prices_arr[] = {1,2,4};
    vector<int> prices(prices_arr,prices_arr+sizeof(prices_arr)/sizeof(prices_arr[0]));
    printf("%d\n", maxProfit(prices));
    return 0;
}
