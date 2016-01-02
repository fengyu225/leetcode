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
        int x,y,path_sums;
        vector<int> buildings;
        Node(int x, int y):x(x),y(y),path_sums(0){}
};

void search(vector<vector<int> >& grid, vector<vector<Node*> >& nodes, pair<int,int> building, int r, int c, int curr_building_cnt){
    int curr = 0;
    queue<Node*> qs[2];
    qs[0].push(nodes[building.first][building.second]);
    int b = building.first*c+building.second;
    int move[4][2] = {
        {0, -1},
        {-1, 0},
        {0, 1},
        {1, 0}
    };
    while(!qs[curr%2].empty()){
        Node* temp = qs[curr%2].front();
        qs[curr%2].pop();
        for(int i=0; i<4; i++){
            int new_x = move[i][0]+temp->x;
            int new_y = move[i][1]+temp->y;
            if(new_x<0 || new_x>=r || new_y<0 || new_y>=c || grid[new_x][new_y] != 0) continue;
            if(!nodes[new_x][new_y] || nodes[new_x][new_y]->buildings.size() != curr_building_cnt || (nodes[new_x][new_y]->buildings.size() != 0 && nodes[new_x][new_y]->buildings.back() == b)) continue;
            Node* new_n = nodes[new_x][new_y];
            new_n->path_sums += curr+1;
            new_n->buildings.push_back(b);
            qs[(curr+1)%2].push(new_n);
        } 
        if(qs[curr%2].empty()) curr++;
    }
}

int shortestDistance(vector<vector<int> >& grid) {
    int r = grid.size();
    if(r == 0) return -1;
    int c = grid[0].size();
    if(c == 0) return -1;
    int building_cnt = 0;
    vector<vector<Node*> > nodes(r, vector<Node*>(c, NULL));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(grid[i][j] != 2) nodes[i][j] = new Node(i,j);
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(grid[i][j] == 1){
                search(grid, nodes, make_pair(i,j), r, c, building_cnt);
                building_cnt++;
            }
    int res = -1;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            Node* n = nodes[i][j];
            if(!n || grid[i][j] != 0 || n->buildings.size() != building_cnt) continue;
            if(res<0) res = n->path_sums;
            else res = min(res, n->path_sums);
        }
    }
    return res;
 }

int main(){
    vector<vector<int> > grid = {
        {1, 0, 2, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0}
    };
//    vector<vector<int> > grid = {
//{0,0,0,0,2,2,0},
//{2,0,2,0,0,2,2},
//{0,2,0,0,0,0,0},
//{2,2,0,2,0,0,0},
//{0,0,0,2,2,2,0},
//{0,0,0,0,2,2,0},
//{2,0,0,0,0,0,0},
//{0,0,0,0,2,2,2},
//{0,2,0,0,0,2,2},
//{2,2,2,2,0,0,0},
//{2,0,2,0,2,2,2},
//{0,2,2,0,0,0,0},
//{2,2,0,2,0,0,2},
//{0,2,0,0,0,0,2},
//{0,2,0,0,0,0,2},
//{0,0,2,0,2,0,0},
//{2,2,2,0,2,0,0},
//{2,0,0,2,2,2,0},
//{0,0,0,0,2,1,0},
//{2,0,0,0,0,0,2},
//{0,0,2,0,0,0,2},
//{0,0,0,0,0,0,0},
//{2,0,0,0,0,2,0},
//{2,2,0,0,2,2,0},
//{2,0,0,2,2,2,0},
//{0,0,0,0,2,0,0},
//{0,0,0,2,1,0,0},
//{0,0,0,0,0,2,0},
//{0,2,2,0,1,2,0},
//{1,0,0,2,2,0,0},
//{0,2,2,2,1,2,0},
//{2,0,0,0,2,2,2},
//{0,2,2,2,2,2,0},
//{0,2,2,2,0,2,2},
//{2,0,0,0,0,2,0},
//{0,2,1,0,0,0,2},
//{0,2,0,0,2,2,0},
//{0,2,2,0,0,0,2},
//{0,0,0,0,2,0,0},
//{0,0,0,0,0,0,0},
//{2,0,0,2,0,0,2},
//{2,2,2,0,2,1,0},
//{0,2,0,0,2,0,0},
//{0,2,0,0,2,2,0},
//{2,0,0,0,0,2,0},
//{2,0,0,0,2,0,2},
//{2,2,0,2,2,0,2},
//{2,2,0,1,0,0,1},
//{0,0,0,0,0,2,2},
//{0,0,2,0,0,0,1},
//{2,2,0,2,2,0,2}
//    };
    cout<<shortestDistance(grid)<<endl;
    return 0;
}