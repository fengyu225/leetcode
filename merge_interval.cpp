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
            return a.start<=b.start;
        }
} cmp;

vector<Interval> merge(vector<Interval>& intervals){
    vector<Interval> res;
    if(intervals.size() == 0) return res;
    std::sort(intervals.begin(), intervals.end(),cmp);
    Interval curr = intervals[0];
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i].start<=curr.end)
            curr.end = std::max(curr.end, intervals[i].end);
        else{
            res.push_back(curr);
            curr = intervals[i];
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
