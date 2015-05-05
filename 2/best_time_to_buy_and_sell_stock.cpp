#include "header.h"

using namespace std;

int maxProfit(vector<int>& prices){
    int arr[prices.size()];
    memset(arr,0,sizeof(arr));
    arr[0] = prices[0];
    int res = INT_MIN;
    for(int i=1; i<prices.size(); i++){
        arr[i] = std::min(arr[i-1], prices[i]);
        res = std::max(res,prices[i]-arr[i]);
    }
    return res;
}

int main(){
    //int prices_arr[] = {0, 1, 2, 3};
    int prices_arr[] = {2,1};
    vector<int> prices(prices_arr,prices_arr+sizeof(prices_arr)/sizeof(prices_arr[0]));
    printf("%d\n", maxProfit(prices));
    return 0;
}
