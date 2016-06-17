/*
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
*/

#include "header.h"

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        
    }

    int next() {
        
    }

    bool hasNext() {
        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

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
    NestedIterator i(z);
    while(i.hasNext()) cout<<i.next()<<endl;
    return 0;
}
