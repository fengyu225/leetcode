/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/

#include "header.h"

class comp{
    public:
        bool operator() (Interval& a, Interval& b){
            return a.start<b.start || a.start == b.start && a.end<b.end;          
        }
};

int minMeetingRooms(vector<Interval>& intervals) {
    int sz = intervals.size();
    sort(intervals.begin(), intervals.end(), comp());
}

int main(){
    vector<Interval> intervals;
    intervals.push_back(Interval(0, 30));
    intervals.push_back(Interval(5, 10));
    intervals.push_back(Interval(15, 20));
    cout<<minMeetingRooms(intervals)<<endl;
    return 0;
}