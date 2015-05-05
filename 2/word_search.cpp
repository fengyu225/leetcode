/*
 *  Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/

#include "header.h"

bool dfs(vector<vector<char> >& board, int x, int y, int pos, string word){
    if(pos == word.size())
        return true;
    int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i=0; i<4; i++){
        int next_x = move[i][0]+x;
        int next_y = move[i][1]+y;
        if(next_x<0 || next_x>=board.size() || next_y<0 || next_y>=board[0].size()) continue;
        if(board[next_x][next_y] == word[pos]){
            char temp = board[next_x][next_y];
            board[next_x][next_y] = '#';
            bool r = dfs(board,next_x,next_y,pos+1,word);
            if(r) return true;
            board[next_x][next_y] = temp;
        }
    }
    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == word[0]){
                char temp = board[i][j];
                board[i][j] = '#';
                bool r = dfs(board,i,j,1,word);
                if(r) return true;
                board[i][j] = temp;
            }
        }
    }
    return false;
}

int main(){
    char s0[]="ABCE";
    char s1[]="SFCS";
    char s2[]="ADEE";
    vector<char> vs0(s0,s0+strlen(s0));
    vector<char> vs1(s1,s1+strlen(s1));
    vector<char> vs2(s2,s2+strlen(s2));
    vector<vector<char> > board;
    board.push_back(vs0);
    board.push_back(vs1);
    board.push_back(vs2);
//    string w0("ABCCED");
    string w1("SEE");
//    string w2("ABCB");
//    printf("%s\n", exist(board,w0)?"true":"false");
    printf("%s\n", exist(board,w1)?"true":"false");
//    printf("%s\n", exist(board,w2)?"true":"false");
    return 0;
}
