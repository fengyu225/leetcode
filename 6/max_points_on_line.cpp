/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

#include "header.h"

// doubel slope as unordered_map's key
//int maxPoints(vector<Point> &points) {
//    int sz = points.size();
//    if(sz <=2 ) return sz;
//    unordered_map<double,int> slops;
//    int res = 0;
//    for(int i=0; i<points.size(); i++){
//        int same = 1, cnt = 0;
//        slops.clear();
//        for(int j=i+1; j<points.size(); j++){
//            if(points[i].x == points[j].x && points[i].y == points[j].y) same++;
//            else{
//                double slp = points[i].x == points[j].x?numeric_limits<double>::max():
//                   (double)((double)(points[j].y-points[i].y)/(double)(points[j].x-points[i].x));
//                slops[slp]++;
//            }
//        }
//        for(auto m:slops) cnt = max(cnt, m.second);
//        res = max(res, cnt+same);
//    }
//    return res;
//}

int gcd(int a, int b){
    if(a<b) return gcd(b,a);
    if(b == 0) return a;
    return gcd(b,a%b);
}

int maxPoints(vector<Point>& points) {
    int sz = points.size();
    if(sz<=2) return sz;
    map<pair<int,int>, int> slops;
    int res=0;
    for(int i=0; i<points.size(); i++){
        int same = 1, cnt = 0, same_x = 0, same_y = 0;
        slops.clear();
        for(int j=i+1; j<points.size(); j++){
            if(points[i].x == points[j].x && points[i].y == points[j].y) same++;
            else if(points[i].x == points[j].x) same_x++;
            else if(points[i].y == points[j].y) same_y++;
            else{
                int g = gcd(abs(points[i].y-points[j].y), abs(points[i].x-points[j].x));
                pair<int,int> temp_p = make_pair((points[i].y-points[j].y)/g, (points[i].x-points[j].x)/g);
                if(temp_p.first<0){
                    temp_p.first = -temp_p.first;
                    temp_p.second = -temp_p.second;
                }
                if(slops.find(temp_p) != slops.end()) slops[temp_p]++;
                else slops[temp_p] = 1;
            }
        }
        for(auto p:slops) cnt = max(cnt, p.second);
        res = max(res, max(max(same_x, same_y)+same, same+cnt));
    }
    return res;
}

int main(){
    //vector<Point> points = {{84,250},{0,0},{1,0},{0,-70},{0,-70},{1,-1},{21,10},{42,90},{-42,-230}}; 
    vector<Point> points = {{2, 3},{3, 3},{-5, 3}}; 
    //vector<Point> points = {{0,-12},{5,2},{2,5},{0,-5},{1,5},{2,-2},{5,-4},{3,4},{-2,4},{-1,4},{0,-5},{0,-8},{-2,-1},{0,-11},{0,-9}}; 
    cout<<maxPoints(points)<<endl;
    return 0;
}
