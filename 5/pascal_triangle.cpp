/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include "header.h"

vector<vector<int> > generate(int numRows){
    vector<vector<int> > res;
    if(numRows<1) return res;
    res.push_back(vector<int>(1,1));
    if(numRows == 1) return res;
    res.push_back(vector<int>(2,1));
    vector<int> temp;
    for(int i=3;i<=numRows;i++){
        temp.clear();
        temp.push_back(1);
        for(int j=0;j<res.back().size()-1;j++) temp.push_back(res.back()[j]+res.back()[j+1]);
        temp.push_back(1);
        res.push_back(temp);
    }
    return res;
}

int main(){
    int numRows = 5;
    vector<vector<int> > r = generate(numRows);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
