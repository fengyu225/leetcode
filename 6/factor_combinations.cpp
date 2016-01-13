/*
Numbers can be regarded as product of its factors. For example,
8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

#include "header.h"

void search(int n, int curr, vector<int>& temp, vector<vector<int> >& res){
    if(n == 1){
        if(temp.size()>1) res.push_back(temp);
        return;
    }
    for(int i=curr; i<=n; i++){
        if(n%i != 0) continue;
        temp.push_back(i);
        search(n/i, i, temp, res);
        temp.pop_back();
    }
}

vector<vector<int> > getFactors(int n) {
    vector<int> temp;
    vector<vector<int> > res;
    search(n, 2, temp, res);
    return res;
}

int main(){
    //vector<vector<int> > res = getFactors(23848713);
    vector<vector<int> > res = getFactors(32);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}