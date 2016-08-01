/*
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]

Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
*/

#include "header.h"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class comp{
    public:
        bool operator() (Interval a, Interval b){
            return a.start<b.start;
        }
};

class SummaryRanges {
    set<Interval, comp> intervals;
    unordered_map<int,int> parents;
    unordered_map<int,Interval*> p_intervals;
    int f(int curr){
        if(parents[curr] == curr) return curr;
        parents[curr] = f(parents[curr]);
        return parents[curr];
    }
    void u(int a, int b){
        if(parents.find(b) != parents.end()){
            int a_p = f(a);
            int b_p = f(b);
            if(a_p == b_p) return;
            parents[a_p] = b_p;
            intervals.erase(intervals.find(*(p_intervals[a_p])));
            intervals.erase(intervals.find(*(p_intervals[b_p])));
            int start = min(p_intervals[b_p]->start, p_intervals[a_p]->start);
            int end = max(p_intervals[b_p]->end, p_intervals[a_p]->end);
            p_intervals[b_p]->start = start;
            p_intervals[b_p]->end = end;
            intervals.insert(*(p_intervals[b_p]));
        }
    }
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        if(parents.find(val) == parents.end()){
            parents[val] = val;
            p_intervals[val] = new Interval(val, val);
            intervals.insert(*(p_intervals[val]));
        }
        if(val != INT_MAX) u(val, val+1);
        if(val != INT_MIN) u(val, val-1);
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> res;
        for(Interval i : this->intervals) res.push_back(i);
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

int main(){
    SummaryRanges* obj = new SummaryRanges();
    vector<int> nums = {1, 3, 7, 2, 6};
    for(int n : nums){
        cout<<n<<endl;
        obj->addNum(n);
        vector<Interval> res = obj->getIntervals();
        for(Interval i : res) cout<<"("<<i.start<<", "<<i.end<<") ";
        cout<<endl;
    }
    return 0;
}
