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
    queue<int> q;
    int curr;
    int cnt;
    int size;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        cnt = 0;
        curr = 0;
        this->size = size;
    }
    
    double next(int val) {
        q.push(val);
        curr+=val;
        if(cnt<size) cnt++;
        else{
            curr-=q.front();
            q.pop();
        }
        return (double)curr/(double)(min(cnt,size)); 
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

int main(){
    MovingAverage obj(3);
    cout<<obj.next(1)<<endl;
    cout<<obj.next(10)<<endl;
    cout<<obj.next(3)<<endl;
    cout<<obj.next(5)<<endl;
    return 0;
}
