/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include "header.h"

class comp{
    public:
        bool operator() (Interval& a, Interval& b){
            return a.start<b.start;      
        }
};

vector<Interval> merge(vector<Interval>& intervals) {
    int sz = intervals.size();
    vector<Interval> res;
    if(sz == 0) return res;
    sort(intervals.begin(), intervals.end(), comp());
    res.push_back(intervals[0]);
    for(int i=1; i<sz; i++){
        Interval last = res.back();
        if(intervals[i].start>last.end) res.push_back(intervals[i]);
        else{
            last.start = min(last.start, intervals[i].start);
            last.end = max(last.end, intervals[i].end);
            res[res.size()-1]=last;
        }
    }
    return res;
}

int main(){
    Interval i0(1,3);
    Interval i1(2,6);
    Interval i2(8,10);
    Interval i3(15,18);
    vector<Interval> intervals;
    intervals.push_back(i0);
    intervals.push_back(i2);
    intervals.push_back(i1);
    intervals.push_back(i3);
    vector<Interval> res = merge(intervals);
    for(int i=0; i<res.size(); i++){
        printf("[%d,%d] ", res[i].start, res[i].end);
    }
    printf("\n");
    return 0;
}
