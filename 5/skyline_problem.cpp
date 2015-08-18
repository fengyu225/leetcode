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

class q_cmp{
    public:
        bool operator() (pair<int,int> l, pair<int,int> r){
            return l.second<r.second;
        }
};

class cmp{
    public:
        bool operator() (pair<int,int> l, pair<int,int> r){
            return abs(l.second)<abs(r.second);
        }
};

vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings){
    vector<pair<int, int> > res;
    priority_queue<pair<int,int>, vector<pair<int,int> >, q_cmp> height_q; 
    vector<pair<int,int> > points;
    for(int i=0; i<buildings.size(); i++){
        if(buildings.size()>=2 && i<buildings.size()-1 && buildings[i][0] == buildings[i+1][0] && buildings[i][1] == buildings[i+1][1]){
            buildings[i+1][2] = max(buildings[i][2], buildings[i+1][2]);
            buildings.erase(buildings.begin()+i);
            i--;
        }
    }
    int sz = buildings.size();
    for(int i=0; i<sz; i++){
        points.push_back(make_pair(i, buildings[i][0]));
        points.push_back(make_pair(i, -1*buildings[i][1]));
    }
    sort(points.begin(), points.end(), cmp());
    for(int i=0; i<points.size(); i++){
        int h;
        if(points[i].second>=0){
            h = buildings[points[i].first][2];
            height_q.push(make_pair(points[i].first, h)); 
            while(!height_q.empty() && buildings[height_q.top().first][1]<points[i].second)
                height_q.pop();
            h = height_q.top().second;
            if(res.empty() || res.back().second<h) res.push_back(make_pair(points[i].second, h));
        }
        else{
            while(!height_q.empty() && buildings[height_q.top().first][1]<-1*points[i].second)
                height_q.pop();
            if(!height_q.empty() && height_q.top().first == points[i].first){
                height_q.pop();
                while(!height_q.empty() && buildings[height_q.top().first][1]<-1*points[i].second)
                    height_q.pop();
                if(height_q.empty()){
                    res.push_back(make_pair(-1*points[i].second, 0));
                }
                else{
                    if(res.empty() || res.back().second>height_q.top().second)
                        res.push_back(make_pair(-1*points[i].second, height_q.top().second));
                }
            } 
        }
    }
    for(int i=0; i<res.size(); i++){
        if(i-2>=0 && res[i].first == res[i-1].first && res[i].second == res[i-2].second){
            res.erase(res.begin()+(i-1), res.begin()+i+1);
            i-=2;
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

    vector<pair<int,int> > res = getSkyline(buildings);
    for(int i=0; i<res.size(); i++)
        cout<<res[i].first<<" "<<res[i].second<<", ";
    cout<<endl;
    return 0; 
}