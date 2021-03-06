/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

 Buildings  Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/

#include "header.h"

class cmp{
    public:
        bool operator() (pair<int,int> l, pair<int,int> r){
            if(l.first<r.first) return true;
            else if(l.first>r.first) return false;
            else if(l.second*r.second<0) return l.second>0;
            else return l.second>r.second;
        }
};

vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings){
    vector<pair<int, int> > res;
    vector<pair<int,int> > points;
    for(auto b:buildings){
        points.push_back(make_pair(b[0], b[2]));
        points.push_back(make_pair(b[1], -1*b[2]));
    }
    sort(points.begin(), points.end(), cmp());
    multiset<int> q;
    int last_h = 0;
    for(auto p:points){
        if(p.second>0) q.insert(p.second);
        else q.erase(q.find(-1*p.second));
        if(q.empty() || *q.rbegin() != last_h){
            int new_h = q.empty()?0:*q.rbegin();
            res.push_back(make_pair(p.first, new_h));
            last_h = new_h;
        }
    }
    return res;
}

int main(){
//    vector<vector<int> > buildings = {
//        {2, 9, 10},
//        {3, 7, 15},
//        {5, 12, 12},
//        {15, 20, 10},
//        {19, 24, 8}
//    };    
    vector<vector<int> > buildings = {
        {4, 10, 10},
        {5, 10, 9},
        {6, 10, 8},
        {7, 10, 7},
        {8, 10, 6},
        {9, 10, 5}
    };

//    vector<vector<int> > buildings = {
//        {2, 4, 7},
//        {2, 4, 5},
//        {2, 4, 6}
//    };
//    vector<vector<int> > buildings = {
//        {0, 3, 5},
//        {3, 10, 5}
//    };
    vector<pair<int,int> > res = getSkyline(buildings);
    for(int i=0; i<res.size(); i++)
        cout<<res[i].first<<" "<<res[i].second<<", ";
    cout<<endl;
    return 0; 
}