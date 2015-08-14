/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/

#include "header.h"

class interval_cmp{
    public:
        bool operator () (const Interval& a, const Interval& b){
            return a.start<b.start;
        }
};

int minMeetingRooms(vector<Interval>& intervals) {
    int sz = intervals.size();
    if(sz<2) return sz;
    vector<vector<Interval> > rooms;
    sort(intervals.begin(), intervals.end(), interval_cmp());
    for(Interval i:intervals){
        int k = -1;
        int diff = INT_MAX;
        for(int j=0;j<rooms.size(); j++){
            int last = rooms[j].size()-1;
            if(rooms[j][last].end>i.start) continue;
            if(i.start-rooms[j][last].end<diff){
                k = j;
                diff = i.start-rooms[j][last].end;
            }
        }
        if(k == -1)
            rooms.push_back(vector<Interval>(1,i));
        else
            rooms[k].push_back(i);
    }
    return rooms.size();
}

int main(){
    vector<Interval> intervals;
    intervals.push_back(Interval(0, 30));
    intervals.push_back(Interval(5, 10));
    intervals.push_back(Interval(15, 20));
    cout<<minMeetingRooms(intervals)<<endl;
    return 0;
}