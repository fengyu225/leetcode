/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

*/

#include "header.h"

#define INF 2147483647

/* only push cell with distance larger than current min x into queue */
void wallsAndGates(vector<vector<int> >& rooms) {
    int m = rooms.size();
    if(m == 0) return;
    int n = rooms[0].size();
    queue<pair<int,int> > q;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(rooms[i][j] == 0) q.push(make_pair(i, j));
        }
    }
    while(!q.empty()){
        pair<int,int> curr_pos = q.front();
        int move[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0}, 
            {-1, 0}
        }; 
        int x = rooms[curr_pos.first][curr_pos.second]+1;
        q.pop();
        for(int k=0; k<4; k++){
            int new_x = move[k][0]+curr_pos.first;
            int new_y = move[k][1]+curr_pos.second;
            if(new_x<m && new_x>=0 && new_y<n && new_y>=0 && rooms[new_x][new_y]>x){
                rooms[new_x][new_y] = x;
                q.push(make_pair(new_x, new_y));
            }
        }
    }
}

int main(){
    vector<vector<int> > rooms = {
        {INF,  -1,  0,  INF},
        {INF, INF, INF,  -1},
        {INF,  -1, INF , -1},
        {  0,  -1, INF, INF}
    }; 
    wallsAndGates(rooms);
    print_2d_vector<int>(rooms);
    return 0;
}