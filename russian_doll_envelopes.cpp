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
            return a.first<b.first || a.first == b.first && a.second<b.second;
        }
};

int maxEnvelopes(vector<pair<int, int> >& envelopes) {
    int sz = envelopes.size();
    if(sz<2) return sz;
    //sort(envelopes.begin(), envelopes.end(), comp());
    sort(envelopes.begin(), envelopes.end());
    vector<int> arr(sz, 1);
    int res = 1;
    for(int i=1; i<sz; i++){
        int m = 1;
        for(int j=0; j<i; j++)
            if(envelopes[j].first<envelopes[i].first && envelopes[j].second<envelopes[i].second) m = max(m, arr[j]+1);
        arr[i] = m;
        res = max(arr[i], res);
    }
    return res;
}

int main(){
    vector<pair<int,int> > envelopes = {
        {5, 4},
        {6, 4},
        {6, 7},
        {2, 3}
    };
    cout<<maxEnvelopes(envelopes)<<endl;
    return 0;
}
