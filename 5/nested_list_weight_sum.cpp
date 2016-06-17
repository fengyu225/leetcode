/*
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)
*/

#include "header.h"

int depthSum(vector<NestedInteger>& nestedList) {
    return depthSum(nestedList, 1);
}

int main(){
    NestedInteger a(1);
    NestedInteger b(1);
    NestedInteger c(2);
    NestedInteger d(1);
    NestedInteger e(1);
    NestedInteger x, y;
    x.addNextedInteger(a);
    x.addNextedInteger(b);
    y.addNextedInteger(d);
    y.addNextedInteger(e);
    vector<NestedInteger> z;
    z.push_back(x);
    z.push_back(c);
    z.push_back(y);
    cout<<depthSum(z)<<endl;
    return 0;
}
