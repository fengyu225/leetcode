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

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > res;
    if(numRows == 0) return res;
    res.push_back(vector<int>(1, 1));
    if(numRows == 1) return res;
    for(int i=2; i<=numRows; i++){
        vector<int> temp;
        temp.push_back(1);
        vector<int> last = res.back();
        for(int j=0; j+1<last.size(); j++) temp.push_back(last[j]+last[j+1]);
        temp.push_back(1);
        res.push_back(temp);
    }
    return res;
}

int main(){
    int numRows = 5;
    vector<vector<int> > r = generate(numRows);
    print_2d_vector<int>(r);
    return 0;
}
