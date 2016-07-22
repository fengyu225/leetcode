/*
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
*/

#include "header.h"

//int getHeight(NestedInteger& i){
//    int res = 1;
//    if(i.isInteger()) return res;
//    for(NestedInteger c : i.getList())
//        res = max(res, 1+getHeight(c));
//    return res;
//}
//
//int depthSumInverse(NestedInteger& i, int level){
//    if(i.isInteger()) return i.getInteger()*level;
//    int res = 0;
//    for(NestedInteger c : i.getList()){
//        if(c.isInteger()) res += (level-1)*c.getInteger();
//        else res += depthSumInverse(c, level-1);
//    }
//    return res;
//}
//
//int depthSumInverse(vector<NestedInteger>& nestedList) {
//    int h = 1, res = 0;
//    for(NestedInteger i : nestedList)
//        h = max(h, getHeight(i)+1);
//    for(NestedInteger i : nestedList){
//        res += depthSumInverse(i, h-1);
//    }
//    return res;
//}

// Instead of multiplying by depth, add integers multiple times (by going level by level and adding the unweighted sum to the weighted sum after each level
int depthSumInverse(vector<NestedInteger>& nestedList) {
    int unweight = 0, weight = 0;
    queue<NestedInteger> qs[2];
    int curr = 0;
    for(NestedInteger i : nestedList) qs[curr].push(i);
    while(!qs[curr%2].empty()){
        NestedInteger temp = qs[curr%2].front();
        qs[curr%2].pop();
        if(temp.isInteger()) weight += temp.getInteger();
        else{
            for(NestedInteger n : temp.getList()) qs[(curr+1)%2].push(n);
        }
        if(qs[curr%2].empty()){
            unweight += weight;
            curr++;
        }
    }
    return unweight;
}

int main(){
    NestedInteger i0(1);
    NestedInteger i1(1);
    NestedInteger i2(1);
    NestedInteger i3(1);
    NestedInteger i4(2);
    NestedInteger i5;
    NestedInteger i6;
    i5.addNextedInteger(i0);
    i5.addNextedInteger(i1);
    i6.addNextedInteger(i2);
    i6.addNextedInteger(i3);
    vector<NestedInteger> arr = {i5, i4, i6};
    cout<<depthSumInverse(arr)<<endl;
    return 0;
}
