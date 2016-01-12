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

class q_comp{
    public:
        bool operator() (Interval& a, Interval& b){
            //interval with small end get higher priority
            return b.end<a.end;
        }
};

// using heap
int minMeetingRooms(vector<Interval>& intervals) {
    int sz = intervals.size();
    if(sz<2) return sz;
    sort(intervals.begin(), intervals.end(), comp());
    priority_queue<Interval,vector<Interval>,q_comp> q; 
    q.push(intervals[0]);
    int res = 1;
    for(int i=1; i<sz; i++){
        Interval temp = q.top();
        if(intervals[i].start<temp.end){
            //intervals[i].start no less than start of all intervals in q
            //intervals[i].end is less than end of all intervals in q
            //so need a new room
            q.push(intervals[i]);
            res++;
        }
        else{
            q.pop();
            temp.end = max(intervals[i].end, temp.end);
            q.push(temp);
        }
    }
    return res;
}

int main(){
    vector<Interval> intervals;
    intervals.push_back(Interval(0, 30));
    intervals.push_back(Interval(5, 10));
    intervals.push_back(Interval(15, 20));
    cout<<minMeetingRooms(intervals)<<endl;
    return 0;
}