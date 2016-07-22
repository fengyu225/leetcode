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

void search(vector<vector<char> >& grid, int i, int j, int r, int c){
    queue<pair<int,int> > q;
    q.push(make_pair(i, j));
    grid[i][j] = 'X';
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        int move[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        for(int i=0; i<4; i++){
            int new_x = move[i][0]+curr.first;
            int new_y = move[i][1]+curr.second;
            if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && grid[new_x][new_y] == '1'){
                q.push(make_pair(new_x, new_y));
                grid[new_x][new_y] = 'X';
            }
        }
    }
}

int numIslands(vector<vector<char> >& grid) {
    int r = grid.size();
    if(r == 0) return 0;
    int c = grid[0].size();
    int res = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(grid[i][j] == '1'){
                search(grid, i, j, r, c);
                res++;
            }
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