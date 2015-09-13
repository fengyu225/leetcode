/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include "header.h"

bool search(int i, int j, vector<vector<char> >& board, string& word, int curr){
    if(curr >= word.length()) return true;
    if(board[i][j] != word[curr]) return false;
    curr++;
    if(curr == word.length()) return true;
    int move[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    char temp = board[i][j];
    board[i][j] = '#';
    for(int x=0; x<4; x++){
        int new_x = i+move[x][0];
        int new_y = j+move[x][1];
        if(new_x>=0 && new_x<board.size() && new_y>=0 && new_y<board[0].size() && 
                board[new_x][new_y] != '#'){
            bool res = search(new_x, new_y, board, word, curr);
            if(res){
                board[i][j] = temp;
                return true;
            }
        }
    }
    board[i][j] = temp; 
    return false;
}

bool exist(vector<vector<char> >& board, string word) {
    int w_len = word.length();
    int r = board.size(), c = board[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            bool res = search(i, j, board, word, 0);
            if(res) return true;
        }
    } 
    return false;
}

int main(){
    vector<vector<char> > board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string w0("ABCCED");
//    string w1("SEE");
//    string w2("ABCB");
    printf("%s\n", exist(board,w0)?"true":"false");
//    printf("%s\n", exist(board,w1)?"true":"false");
//    printf("%s\n", exist(board,w2)?"true":"false");
    return 0;
}
