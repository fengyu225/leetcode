/*
Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
Follow up:
What if the number of hits per second could be very large? Does your design scale?
*/

#include "header.h"

class HitCounter {
    deque<int> q;
    unordered_map<int,int> qm;
    int count;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        this->count = 0; 
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        count++;
        if(qm.find(timestamp) == qm.end())
            q.push_back(timestamp);
        qm[timestamp]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!q.empty() && timestamp-q.front()>=300){
            this->count -= qm[q.front()];
            qm.erase(qm.find(q.front()));
            q.pop_front();
        } 
        return this->count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

int main(){
    HitCounter* counter = new HitCounter();
    counter->hit(1);
    counter->hit(2);
    counter->hit(3);
    cout<<counter->getHits(4)<<endl;
    counter->hit(300);
    cout<<counter->getHits(300)<<endl;
    cout<<counter->getHits(301)<<endl; 
    return 0;
}
