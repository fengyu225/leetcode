/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

#include "header.h"

int maxPoints(vector<Point> &points) {
    int sz = points.size();
    if(sz <=2 ) return sz;
    unordered_map<double,int> slops;
    int res = 0;
    for(int i=0; i<points.size(); i++){
        int same = 1, cnt = 0;
        slops.clear();
        for(int j=i+1; j<points.size(); j++){
            if(points[i].x == points[j].x && points[i].y == points[j].y) same++;
            else{
                double slp = points[i].x == points[j].x?numeric_limits<double>::max():
                   (double)((double)(points[j].y-points[i].y)/(double)(points[j].x-points[i].x));
                slops[slp]++;
            }
        }
        for(auto m:slops) cnt = max(cnt, m.second);
        res = max(res, cnt+same);
    }
    return res;
}

int main(){
    vector<Point> points = {{84,250},{0,0},{1,0},{0,-70},{0,-70},{1,-1},{21,10},{42,90},{-42,-230}}; 
    cout<<maxPoints(points)<<endl;
    return 0;
}
