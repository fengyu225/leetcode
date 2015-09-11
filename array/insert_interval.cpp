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

class cmp{
    public:
        bool operator() (Interval& l, Interval& r){
            return l.start<r.start;
        }
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    int sz = intervals.size();
    int i = 0;
    for(; i<sz; i++){
        if(intervals[i].end<newInterval.start) res.push_back(intervals[i]);
        else{
            //intervals[i].end >= newInterval.start
            if(intervals[i].start>newInterval.end){
                res.push_back(newInterval);
                newInterval = intervals[i];
            }
            else{
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
    }
    res.push_back(newInterval);
    return res;
}

int main(){
//    vector<Interval> intervals = {
//        {1,2},
//        {3,5},
//        {6,7},
//        {8, 10},
//        {12, 16}
//    };    
    vector<Interval> intervals = {
        {1,3},
        {6, 9}
    };
    //Interval newInterval(4, 9);
    Interval newInterval(2, 5);
    vector<Interval> res = insert(intervals, newInterval);
    for(int i=0; i<res.size(); i++){
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }
    return 0;
}

