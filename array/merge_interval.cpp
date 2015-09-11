/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include "header.h"

class cmp{
    public:
        bool operator() (Interval& a, Interval& b){
            return a.start<b.start;
        }
};

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    int sz = intervals.size();
    if(sz == 0) return res;
    sort(intervals.begin(), intervals.end(), cmp());
    Interval working = intervals[0];
    for(int i=1; i<sz; i++){
        if(intervals[i].start<=working.end) working.end = max(intervals[i].end, working.end);
        else{
            res.push_back(working);
            working = intervals[i];
        }
    }
    res.push_back(working);
    return res;
}

int main(){
    vector<Interval> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };
    vector<Interval> res = merge(intervals);
    for(int i=0; i<res.size(); i++){
        printf("[%d,%d] ", res[i].start, res[i].end);
    }
    printf("\n");
    return 0;
}
