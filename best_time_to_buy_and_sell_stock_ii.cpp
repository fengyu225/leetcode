#include<vector>
#include<stdio.h>

using namespace std;

int maxProfit(vector<int>& prices){
    int max = 0;
    for(int i=1; i<prices.size(); i++){
        if(prices[i]>prices[i-1])
            max += prices[i]-prices[i-1];
    }
    return max;
}

int main(){
    int prices[] = {5, 1, 2, 3, 4};
    vector<int> prices_v(prices,prices+sizeof(prices)/sizeof(prices[0]));
    printf("%d\n", maxProfit(prices_v));
    return 0;
}
