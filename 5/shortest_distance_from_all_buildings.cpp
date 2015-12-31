/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.
*/

#include "header.h"

class Node{
    public:
        int x,y;
        unordered_map<int,int> buildings;
        Node(int x, int y):x(x),y(y){}
};

bool intersect(unordered_map<int,int>& a, unordered_map<int,int>& b){
    for(auto curr:a){
        if(b.find(curr.first) != b.end()) return true;
    }
    return false;
}

int shortestDistance(vector<vector<int> >& grid) {
    int r = grid.size();
    if(r == 0) return -1;
    int c = grid[0].size();
    if(c == 0) return -1;
    int building_cnt = 0;
    queue<Node*> qs[2];
    unordered_map<int,Node*> nodes;
    int path = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            Node* n = new Node(i,j);
            nodes[i*c+j] = n;
            if(grid[i][j]==1){
                building_cnt++;
                n->buildings[i*c+j] = 0;
                qs[path].push(n);
            }
        }
    }
    int move[4][2] = {
        {0, -1},
        {-1, 0},
        {0, 1},
        {1, 0}
    };
    while(!qs[path%2].empty()){
        bool found = false;
        int res = INT_MAX;
        while(!qs[path%2].empty()){
            Node* n = qs[path%2].front();
            cout<<n->x<<" "<<n->y<<endl;
            //if(n->x == 1 && n->y == 1){
            //    cout<<"xx"<<endl;
            //}
            qs[path%2].pop();
            for(int i=0; i<4; i++){
                int new_x = move[i][0]+n->x;
                int new_y = move[i][1]+n->y;
                if(new_x<0 || new_x>=r || new_y<0 || new_y>=c || grid[new_x][new_y] != 0) continue;
                if(intersect(n->buildings, nodes[new_x*c+new_y]->buildings)) continue;
                Node* temp = nodes[new_x*c+new_y];
                for(auto bd:n->buildings) temp->buildings[bd.first] = bd.second+1;
                cout<<temp->x<<" "<<temp->y<<" "<<temp->buildings.size()<<endl;
                if(temp->buildings.size() == building_cnt){
                    found = true;
                    int temp_res = 0;
                    for(auto bd:temp->buildings) temp_res += bd.second;
                    res = min(res, temp_res); 
                }
                qs[(path+1)%2].push(temp);
            }
        }
        if(found) return res;
        path++;
    }
    return -1;
 }

int main(){
    vector<vector<int> > grid = {
        {1, 0, 2, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0}
    };
    cout<<shortestDistance(grid)<<endl;
    return 0;
}