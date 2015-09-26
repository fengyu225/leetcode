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

void update(vector<vector<int> >& rooms, int m, int n, int i, int j){
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    queue<pair<int,int> > curr;
    queue<pair<int,int> > next;
    curr.push(make_pair(i,j));
    queue<pair<int,int> > q_arr[2] = {curr, next};
    int x = 0;
    visited[i][j] = true;
    while(!q_arr[x%2].empty()){
        pair<int,int> curr_pos = q_arr[x%2].front();
        int move[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0}, 
            {-1, 0}
        }; 
        for(int k=0; k<4; k++){
            int new_x = move[k][0]+curr_pos.first;
            int new_y = move[k][1]+curr_pos.second;
            if(new_x<m && new_x>=0 && new_y<n && new_y>=0 && rooms[new_x][new_y]>0  && visited[new_x][new_y] == false){
                rooms[new_x][new_y] = min(rooms[new_x][new_y], x+1);
                visited[new_x][new_y] = true;
                q_arr[(x+1)%2].push(make_pair(new_x, new_y));
            }
        }
        q_arr[x%2].pop();
        if(q_arr[x%2].empty()){
            x++;
        }
    }
}

void wallsAndGates(vector<vector<int> >& rooms) {
    int m = rooms.size();
    if(m == 0) return;
    int n = rooms[0].size();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(rooms[i][j] == 0)
                update(rooms, m, n, i, j);
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