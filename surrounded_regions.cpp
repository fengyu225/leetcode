/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
*/

#include "header.h"

void set_boarder(vector<vector<char> >& board, int i, int j){
    if(board[i][j] != 'O') return;
    queue<pair<int, int> > q;
    q.push(pair<int,int>(i,j));
    board[i][j] = 'G';
    int move[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int new_x = move[i][0]+p.first;
            int new_y = move[i][1]+p.second;
            if(new_x<0 || new_x>=board.size() || new_y<0 || new_y>=board[0].size()) continue;
            if(board[new_x][new_y] == 'O'){
                board[new_x][new_y] = 'G';
                q.push(pair<int,int>(new_x, new_y));
            }
        }   
    }   
}

void solve(vector<vector<char> > &board){
    if(board.size() == 0) return;
    for(int i=0; i<board[0].size(); i++){set_boarder(board, 0, i);set_boarder(board, board.size()-1, i);}
    for(int i=0; i<board.size(); i++){set_boarder(board, i, 0);set_boarder(board, i, board[0].size()-1);}
    for(int i=0; i<board.size(); i++)
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == 'G') board[i][j]='O';
            else if(board[i][j] == 'O') board[i][j] = 'X';
        }
}

int main(){
    vector<vector<char> > board;
    string s[] = {
"OOOOOOOOXOOOOOXOOOOO",
"OOOOOOOXOOOOOOOOOOOO",
"XOOXOXOOOOXOOXOOOOOO",
"OOOOOOOOOOOOOOOOOXXO",
"OXXOOOOOOXOOOOOOOOOO",
"OOOOXOOOOOOXOOOOOXXO",
"OOOOOOOXOOOOOOOOOOOO",
"OOOOOOOOOOOOOXOOOOOO",
"OOOOOOOOOOOOOOOOOOXO",
"OOOOOXOOOOOOOOOOOOOO",
"OOOOOOOOXOOOOOOOOOOO",
"OOOOXOOOOXOOOOOOOOOO",
"OOOOOOOOXOOOOOOOOOOO",
"XOOOOOOOOXXOOOOOOOOO",
"OOOOOOOOOOOXOOOOOOOO",
"OOOOXOOOOOOOOXOOOOOX",
"OOOOOXOOOOOOOOOXOXOO",
"OXOOOOOOOOOOOOOOOOOO",
"OOOOOOOOXXOOOXOOXOOX",
"OOOOOOOOOOOOOOOOOOOO"
    };
    for(int i=0; i<sizeof(s)/sizeof(s[0]); i++)
        board.push_back(vector<char>(s[i].begin(), s[i].end()));
    solve(board);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    return 0;
}
