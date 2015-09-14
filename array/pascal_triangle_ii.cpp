/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

#include "header.h"

using namespace std;

vector<int> getRow(int rowIndex) {
    if(rowIndex == 0) return vector<int>(1,1);
    vector<int> curr(2,1);
    for(int i=1; i<rowIndex; i++){
        vector<int> next(1,1);
        for(int j=1; j<i+1; j++) next.push_back(curr[j]+curr[j-1]);
        next.push_back(1);
        curr = next;
    }
    return curr; 
}

int main(){
//    int rowIndex = 4;
//    vector<int> r = getRow(rowIndex);
//    print_vector<int>(r);
    for(int i=0; i<6; i++) print_vector<int>(getRow(i));
    return 0;
}
