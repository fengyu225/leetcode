/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

#include "header.h"

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        
    }
    
    double next(int val) {
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

int main(){
    MovingAverage obj = new MovingAverage(3);
    cout<<obj.next(1)<<endl;
    cout<<obj.next(10)<<endl;
    cout<<obj.next(3)<<endl;
    cout<<obj.next(5)<<endl;
    return 0;
}
