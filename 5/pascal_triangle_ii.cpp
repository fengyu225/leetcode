/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

#include "header.h"

using namespace std;

vector<int> getRow(int rowIndex){
    vector<int> curr(1,1);
    if(rowIndex == 0) return curr;
    curr = vector<int>(2,1);
    vector<int> next;
    vector<int> arr[2] = {curr,next};
    int x = 0;
    for(int i=2; i<=rowIndex; i++){
        arr[(x+1)%2].clear();
        arr[(x+1)%2].push_back(1);
        for(int j=0;j<arr[x%2].size()-1;j++) arr[(x+1)%2].push_back(arr[x%2][j]+arr[x%2][j+1]);
        arr[(x+1)%2].push_back(1);
        x++;
    }
    return arr[x%2];
}

int main(){
    int rowIndex = 10;
    vector<int> r = getRow(rowIndex);
    for(int i=0; i<r.size(); i++)
        printf("%d ", r[i]);
    printf("\n");
    return 0;
}
