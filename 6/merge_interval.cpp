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
            return a.start<b.start || a.start == b.start && a.end<b.end;
        }
};

vector<Interval> merge(vector<Interval>& intervals) {
    int sz = intervals.size();
    vector<Interval> res;
    if(sz == 0) return res;
    if(sz == 1) return vector<Interval>(1, intervals[0]);
    sort(intervals.begin(), intervals.end(), comp());
    int curr = 0, next = 1;
    while(next<sz){
        if(intervals[next].start<=intervals[curr].end){
            intervals[curr].end = max(intervals[next].end, intervals[curr].end);
            next++;
        }
        else{
            res.push_back(intervals[curr]);
            curr = next++;
        }
    }
    res.push_back(intervals[curr]);
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
