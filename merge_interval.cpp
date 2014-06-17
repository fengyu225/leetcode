#include "header.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool comp(const Interval& i0, const Interval& i1){
    return i0.start<i1.start;
}

vector<Interval> merge(vector<Interval>& intervals){
    vector<Interval> result;
    if(intervals.size() == 0) return result;
    std::sort(intervals.begin(), intervals.end(), comp);
    Interval to_be_added = intervals[0];
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i].start<=to_be_added.end){
            if(intervals[i].end>to_be_added.end)
                to_be_added.end = intervals[i].end;
        }
        else{
            result.push_back(to_be_added);
            to_be_added = intervals[i];
        }
    }
    result.push_back(to_be_added);
    return result;
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
