/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

#include "header.h"

class comp{
    public:
        bool operator() (pair<int,int>& a, pair<int,int>& b){
            return a.first<b.first || (a.first == b.first && a.second>b.second);
        }
};

int maxEnvelopes(vector<pair<int, int> >& envelopes) {
    int sz = envelopes.size();
    if(sz<2) return sz;
    sort(envelopes.begin(), envelopes.end(), comp());
    vector<int> v;
    for(int i=0; i<sz; i++){
        pair<int,int> curr_p = envelopes[i];
        auto iter = lower_bound(v.begin(), v.end(), curr_p.second);
        if(iter == v.end()) v.push_back(curr_p.second);
        else *iter = curr_p.second;
    }
    return v.size();
}

int main(){
    vector<pair<int,int> > envelopes = {
        {4, 5},
        {4, 6},
        {6, 7},
        {2, 3},
        {1, 1}
    };
    cout<<maxEnvelopes(envelopes)<<endl;
    return 0;
}
