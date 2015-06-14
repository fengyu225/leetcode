/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

#include "header.h"

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points) {
    unordered_map<double,int> m;
    int res = 0;
    for(int i=0; i<points.size(); i++){
        m.clear();
        int same = 0;
        int temp = 1;
        for(int j=i+1;j<points.size(); j++){
            if(points[i].x==points[j].x && points[i].y == points[j].y){
                same++;
                continue;
            }
            double slp = numeric_limits<double>::infinity();
            if(points[i].x != points[j].x)
                slp = (double)(points[i].y-points[j].y/points[i].x-points[j].x);
            if(m.find(slp) == m.end()) m[slp] = 1;
            m[slp]++;
            temp = max(temp, m[slp]);
        }
        res = max(res,temp+same);
    }
    return res;
}

int main(){

    return 0;
}
