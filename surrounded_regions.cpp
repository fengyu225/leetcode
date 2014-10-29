#include "header.h"

using namespace std;

void set_boarder(vector<vector<char> >& board,int i, int j){
    board[i][j] = 'B';
    queue<pair<int,int> > q;
    int move[4][2] = {{-1,0}, {1, 0}, {0, 1}, {0, -1}};
    q.push(make_pair(i,j));
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int new_x = p.first+move[i][0];
            int new_y = p.second+move[i][1];
            if(new_x<0 || new_x>=board.size() || new_y<0 || new_y>=board[0].size())
                continue;
            if(board[new_x][new_y] == 'O'){
                board[new_x][new_y] = 'B';
                q.push(make_pair(new_x, new_y));
            }
        }
    }
}

void solve(vector<vector<char> >& board){
    if(board.size() <=1) return;
    for(int i=0; i<board[0].size(); i++){
        if(board[0][i] == 'O')
            set_boarder(board,0,i);
        if(board[board.size()-1][i] == 'O')
            set_boarder(board,board.size()-1,i);
    }
    for(int j=0; j<board.size(); j++){
        if(board[j][0] == 'O')
            set_boarder(board,j,0);
        if(board[j][board[0].size()-1] == 'O')
            set_boarder(board,j,board[0].size()-1);
    }
    for(int i=0; i<board.size(); i++)
        for(int j=0; j<board[i].size(); j++)
            if(board[i][j] == 'O')
                board[i][j] = 'X';
    for(int i=0; i<board.size(); i++)
        for(int j=0; j<board[i].size(); j++)
            if(board[i][j] == 'B')
                board[i][j] = 'O';
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
