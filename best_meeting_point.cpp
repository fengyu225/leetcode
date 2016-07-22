/*
A group of people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):
1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
*/

#include "header.h"

class comp{
    public:
        bool operator() (int a, int b){
            return b<a;
        }
};

class MedianFinder {
    bool even;
    priority_queue<int, vector<int> > left_q;
    priority_queue<int, vector<int>, comp> right_q;
public:
    MedianFinder(){
        even = true;
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        if(even){
            if(left_q.empty() || num<=right_q.top()) left_q.push(num);
            else{
                left_q.push(right_q.top());
                right_q.pop();
                right_q.push(num);
            }
        }
        else{
            if(left_q.top()<num) right_q.push(num);
            else{
                right_q.push(left_q.top());
                left_q.pop();
                left_q.push(num);
            }
        }
        even = !even;
    }   

    // Returns the median of current data stream
    int findMedian() {
        if(even) return (left_q.top()+right_q.top())/2;
        else return left_q.top();
    }
};

int minTotalDistance(vector<vector<int> >& grid) {
    int r = grid.size();
    if(r == 0) return 0;
    int c = grid[0].size();
    if(c == 0) return 0;
    MedianFinder mf_r, mf_c;     
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(grid[i][j] == 1){
                mf_r.addNum(i);
                mf_c.addNum(j);
            }
        }
    }
    int m_r = mf_r.findMedian(), m_c = mf_c.findMedian();
    int res = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(grid[i][j]){
                res += (abs(i-m_r)+abs(j-m_c));
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int> > grid = {
        {1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0}
    };
    cout<<minTotalDistance(grid)<<endl;
    return 0;
}