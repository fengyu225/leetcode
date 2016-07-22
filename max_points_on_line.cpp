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
        int same = 1, temp = 0;
        for(int j=i+1;j<points.size(); j++){
            if(points[i].x==points[j].x && points[i].y == points[j].y){
                same++;
                continue;
            }
            double slp = points[i].x != points[j].x?
                (double)((double)(points[i].y-points[j].y)/(double)(points[i].x-points[j].x)):
                numeric_limits<double>::infinity();
            m[slp]++;
        }
        for(auto x:m) temp = max(temp, x.second);
        res = max(res,temp+same);
    }
    return res;
}

int main(){
    vector<Point> points = {{84,250},{0,0},{1,0},{0,-70},{0,-70},{1,-1},{21,10},{42,90},{-42,-230}}; 
    cout<<maxPoints(points)<<endl;
    return 0;
}
