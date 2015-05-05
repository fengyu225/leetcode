#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices){
    if(prices.size() == 0)
        return 0;
    int max = -1;
    int min = prices[0];
    for(int i=0; i<prices.size(); i++){
        min = prices[i]<min?prices[i]:min;
        max = prices[i]-min>max?prices[i]-min:min;
    }
    return max;
}

int main(){
    //int prices_arr[] = {0, 1, 2, 3};
    int prices_arr[] = {2,1};
    vector<int> prices(prices_arr,prices_arr+sizeof(prices_arr)/sizeof(prices_arr[0]));
    printf("%d\n", maxProfit(prices));
    return 0;
}
