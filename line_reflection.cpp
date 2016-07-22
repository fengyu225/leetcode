/*
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?
*/

#include "header.h"

bool isReflected(vector<pair<int, int>>& points) {
    unordered_map<int,unordered_set<int> > m;
    int sz = points.size();
    if(sz<2) return true;
    int minimal = points[0].first,  maximal = points[0].first;
    for(pair<int,int> p : points){
        minimal = min(minimal, p.first);
        maximal = max(maximal, p.first);
        m[p.first].insert(p.second); 
    }
    int mid = minimal+maximal;
    for(auto p : m){
        if(p.first*2 == mid) continue;
        if(m.find(mid-p.first) == m.end()) return false;
        unordered_set<int> l = p.second, r = m[mid-p.first];
        if(l.size() != r.size()) return false;
        for(int x : l)
            if(r.find(x) == r.end()) return false;
    }
    return true;
}

int main(){
    vector<pair<int,int> > points = {
        {1, 1},
        {-1, -1}
    };
    cout<<isReflected(points)<<endl;
}
