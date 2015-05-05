#include<stdio.h>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices){
    if(prices.size() == 0)
        return 0;
    int left_max[prices.size()];
    int min = prices[0];
    int max_p = 0;
    left_max[0] = 0;
    for(int i=1; i<prices.size(); i++){
        if(prices[i] - min > max_p){
            left_max[i] = prices[i]-min;
            max_p = left_max[i];
        }
        else
            left_max[i] = max_p;
        min = prices[i]<min?prices[i]:min;
    }
    max_p = 0;
    int result = 0;
    int max = prices[prices.size()-1];
    for(int i=prices.size()-1; i>=0; i--){
        if(max-prices[i] > max_p){
            max_p = max-prices[i];
            result = max_p+left_max[i]>result?max_p+left_max[i]:result;
        }
        max = prices[i]>max?prices[i]:max;
    }
    return result;
}

int main(){
    int prices_arr[] = {3, 2, 6, 5, 0, 3};
    vector<int> prices(prices_arr,prices_arr+sizeof(prices_arr)/sizeof(prices_arr[0]));
    printf("%d\n", maxProfit(prices));
    return 0;
}
