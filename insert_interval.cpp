#include "header.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    int r=0;
    while(r<intervals.size() && newInterval.start>intervals[r].end) r++;
    if(r==intervals.size()){
        intervals.push_back(newInterval);
        return intervals;
    }
    intervals.insert(intervals.begin()+r, newInterval);
    while(r+1<intervals.size()){
        if(intervals[r+1].start>intervals[r].end) break;
        intervals[r].start = std::min(intervals[r].start,intervals[r+1].start);
        intervals[r].end = std::max(intervals[r].end,intervals[r+1].end);
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

