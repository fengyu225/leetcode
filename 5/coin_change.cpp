#include<vector>
#include<iostream>

using namespace std;

int make_change(vector<int>& coins, int amount){
    int sz = coins.size();
    if(sz == 0) return 0;
    vector<vector<int> > arr(sz, vector<int>(amount+1, 1));
    for(int i=0; i<sz; i++){
        for(int j=1; j<=amount; j++){
            arr[i][j] = 
                (i<1?0:arr[i-1][j])
                +
                (j<coins[i]?0:arr[i][j-coins[i]]);
        }
    }
    return arr[sz-1][amount];
}

int main(){
    vector<int> coins = {1, 5, 10, 25, 50};
    cout<<make_change(coins, 0)<<endl;
    return 0;
}
