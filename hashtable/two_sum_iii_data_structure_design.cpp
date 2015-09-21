/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/

#include "header.h"

class TwoSum {
public:

    // Add the number to an internal data structure.
    void add(int number) {
        
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        
    }
};

// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);

int main(){
    TwoSum ts;
    ts.add(1);
    ts.add(3);
    ts.add(5);
    cout<<ts.find(4)<<endl;
    cout<<ts.find(7)<<endl;
    return 0;
}