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
    void add(int number) {
        m[number]++;    
    }

    bool find(int value) {
        for(auto x:m){
            if(m.find(value-x.first) != m.end() && (value-x.first != x.first || x.second>1)) return true;
        } 
        return false;
    }
private:
    unordered_map<int,int> m;
};

int main(){
    TwoSum ts;
    ts.add(1);
    ts.add(3);
    ts.add(5);
    cout<<ts.find(4)<<endl;
    cout<<ts.find(7)<<endl;
    return 0;
}