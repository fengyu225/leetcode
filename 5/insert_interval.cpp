/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include "header.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    int sz = intervals.size();
    int r = 0;
    while(r<sz && intervals[r].end<newInterval.start) r++;
    if(r == sz){
        res = intervals;
        res.push_back(newInterval);
        return res;
    }    
    intervals.insert(intervals.begin()+r, newInterval);
    while(r+1<intervals.size()){
        if(intervals[r+1].start>intervals[r].end) break;
        intervals[r].start = std::min(intervals[r].start,intervals[r+1].start);
        intervals[r].end = std::max(intervals[r].end, intervals[r+1].end);
        intervals.erase(intervals.begin()+r+1);
    }
    return intervals;
}

int main(){
    Interval i0(1, 2);
    Interval i1(3, 5);
    Interval i2(6, 7);
    Interval i3(8, 10);
    Interval i4(12, 16);
    Interval i5(4,9);
    vector<Interval> intervals = {i0, i1, i2, i3, i4};
    vector<Interval> res = insert(intervals, i5);
    for(int i=0; i<res.size(); i++){
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }
    return 0;
}

