/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
*/

#include "header.h"

class comp{
    public:
        bool operator() (int a, int b){
            return b<a;
        }
};

class MedianFinder {
    bool even;
    priority_queue<int,vector<int> > small;
    priority_queue<int,vector<int>,comp> large;
public:
    MedianFinder(){
        even = true;
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        if(even){
            if(!large.empty() && large.top()<num){
                small.push(large.top());
                large.pop();
                large.push(num);
            }
            else small.push(num);
        }
        else{
            if(small.top()>num){
                large.push(small.top());
                small.pop();
                small.push(num); 
            }
            else large.push(num);
        }
        even = !even;
    }

    // Returns the median of current data stream
    double findMedian() {
        if(even) return ((double)small.top()+(double)large.top())*0.5;
        return (double)small.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main(){
    MedianFinder mf;
    mf.addNum(0);
    mf.addNum(0);
    cout<<mf.findMedian()<<endl;
//    mf.addNum(-1);
//    cout<<mf.findMedian()<<endl;
//    mf.addNum(-2);
//    cout<<mf.findMedian()<<endl;
//    mf.addNum(-3);
//    cout<<mf.findMedian()<<endl;
//    mf.addNum(-4);
//    cout<<mf.findMedian()<<endl;
//    mf.addNum(-5);
//    cout<<mf.findMedian()<<endl;
    return 0;
}