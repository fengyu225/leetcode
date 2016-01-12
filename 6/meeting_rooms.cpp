/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
*/

#include "header.h"

class comp{
    public:
        bool operator() (Interval& a, Interval& b){
            return a.start<b.start || a.start == b.start && a.end<b.end;          
        }
};

bool canAttendMeetings(vector<Interval>& intervals){
    int sz = intervals.size();
    if(sz == 1) return true;
    sort(intervals.begin(), intervals.end(), comp());
    for(int l=0; l<sz-1; l++){
        if(intervals[l].end>intervals[l+1].start) return false;
    }
    return true;
}

int main(){
    vector<Interval> intervals;
    intervals.push_back(Interval(20, 30));
    intervals.push_back(Interval(5, 10));
    intervals.push_back(Interval(15, 20));
    cout<<canAttendMeetings(intervals)<<endl;
    return 0;
}