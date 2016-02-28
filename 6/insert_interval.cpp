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

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    int sz = intervals.size();
    vector<Interval> res;
    int i = 0;
    for(; i<sz; i++){
        if(intervals[i].end<newInterval.start) res.push_back(intervals[i]);
        else if(intervals[i].start>newInterval.end) break;
        else{
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
    }
    res.push_back(newInterval);
    for(;i<sz;i++) res.push_back(intervals[i]);
    return res;
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

