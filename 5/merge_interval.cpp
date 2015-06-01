/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include "header.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct comp{
    public:
        bool operator () (const Interval& a, const Interval& b){
            return a.start<b.start;
        }
} cmp;

vector<Interval> merge(vector<Interval>& intervals){
    vector<Interval> res;
    int sz = intervals.size();
    if(sz < 2) return intervals;
    sort(intervals.begin(), intervals.end(), cmp);
    Interval curr = intervals[0];
    for(int i=1; i<sz; i++){
        if(curr.end<intervals[i].start){
            res.push_back(curr);
            curr = intervals[i];
        } 
        else{
            curr.end = max(curr.end, intervals[i].end);
        }
    }
    res.push_back(curr);
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
