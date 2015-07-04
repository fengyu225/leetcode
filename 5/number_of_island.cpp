/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
11110
11010
11000
00000
Answer: 1

Example 2:
11000
11000
00100
00011
Answer: 3
*/

#include "header.h"

struct pos{
    int x;
    int y;
    pos(int x,int y):x(x),y(y){}
};

void dfs(vector<vector<char> >& grid, int i, int j){
    queue<pos*> q;
    q.push(new pos(i,j));
    grid[i][j] = 'A';
    while(!q.empty()){
        pos* curr = q.front();
        q.pop();
        int move[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        for(int i=0; i<4; i++){
            int new_x = curr->x+move[i][0];
            int new_y = curr->y+move[i][1];
            if(new_x>=0 && new_x<grid.size() && new_y>=0 && new_y<grid[0].size() && grid[new_x][new_y] == '1'){
                q.push(new pos(new_x, new_y));
                grid[new_x][new_y]='A';
            }
        }
        delete curr;
    }
}

int numIslands(vector<vector<char> >& grid) {
    int res = 0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++)
            if(grid[i][j]=='1'){
                res++;
                dfs(grid,i,j);
            }
    }
    return res;
}

int main(){
//    string arr[] = {
//        "11000",
//        "11000",
//        "00100",
//        "00011"
//    };
    string arr[] = {
"11111011111111101011",
"01111111111110111110",
"10111001101111111111",
"11110111111111111111",
"10011111111111111111",
"10111111011101110111",
"01111111111101101111",
"11111111111101111011",
"11111111110111111111",
"11111111111111111111",
"01111111011111111111",
"11111111111111111111",
"11111111111111111111",
"11111011111110111111",
"10111110111011110111",
"11111111111101111110",
"11111111111110111100",
"11111111111111111111",
"11111111111111111111",
"11111111111111111111"
    };
    vector<vector<char> > grid;
    for(int i=0; i<sizeof(arr)/sizeof(string); i++)
        grid.push_back(vector<char>(arr[i].begin(), arr[i].end()));
    cout<<numIslands(grid)<<endl;
    return 0;    
}