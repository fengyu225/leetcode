#include "header.h"

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

string get_decimal(int a, int b){
    if(a==0) return "0";
    if(b==0) return "inf";
    string res = "0.";
    int curr=2;
    unordered_map<int,int> arr;
    while(a!=0 && arr.find(a)==arr.end()){
        res += to_string(10*a/b);
        arr[a] = curr;
        a = 10*a % b;
        curr++;
    }
    if(a==0) return res;
    return res.substr(0,arr[a])+"("+res.substr(arr[a],res.size()-arr[a])+")";
}

int maxPoints(vector<Point> &points) {
    //unordered_map<string,int> m;
    unordered_map<double,int> m;
    int res = 0;
    for(int i=0; i<points.size(); i++){
        m.clear();
        int same_point_count = 0;
        int temp = 1;
        for(int j=i+1;j<points.size();j++){
            if(points[j].x == points[i].x && points[j].y == points[i].y){
                same_point_count++;
                continue;
            }
            double slp=std::numeric_limits<double>::infinity();
            if(points[i].x != points[j].x)
                slp = (double)(points[i].y-points[j].y)/(points[i].x-points[j].x);
//            string slp = get_decimal(points[j].y-points[i].y, points[j].x-points[i].x);
            if(m.find(slp) == m.end())
                m[slp] = 1;
            m[slp]++;
            temp = std::max(temp,m[slp]);
        }
        res = std::max(res,temp+same_point_count);
    }
    return res;
}

int main(){

    return 0;
}
