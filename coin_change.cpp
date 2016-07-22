/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/

#include "header.h"

int coinChange(vector<int>& coins, int amount) {
    int sz = coins.size();
    if(sz == 0) return -1;
    vector<int> arr(amount+1, -1);
    arr[0] = 0;
    for(int i=1; i<amount+1; i++){
        int temp = INT_MAX;
        for(int c:coins){
            if(i-c<0 || arr[i-c] == -1) continue;
            temp = min(temp, arr[i-c]+1);
        }
        if(temp<INT_MAX) arr[i] = temp;
    }
    return arr[amount];
}

int main(){
    //vector<int> coins = {1, 2, 5};
    vector<int> coins = {2};
    cout<<coinChange(coins, 1)<<endl;
    return 0;
}
