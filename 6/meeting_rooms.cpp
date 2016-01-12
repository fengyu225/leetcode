/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
*/

#include "header.h"

bool canAttendMeetings(vector<Interval>& intervals){
}

int main(){
    vector<Interval> intervals;
    intervals.push_back(Interval(20, 30));
    intervals.push_back(Interval(5, 10));
    intervals.push_back(Interval(15, 20));
    cout<<canAttendMeetings(intervals)<<endl;
    return 0;
}